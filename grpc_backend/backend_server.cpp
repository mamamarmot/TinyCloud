//
// Created by tianli on 12/4/16.
//

#include <iostream>
#include <memory>
#include <map>
#include <unistd.h>

#include <grpc++/grpc++.h>

#include "backend.grpc.pb.h"
#include "Indexer.h"
#include "BigTabler.h"

void RunGC();
void RunRestart();
void writeToLog(string& msg);
void replicaLogParser(string line, ofstream& outfile);
void primaryLogParser(string line, ofstream& outfile);

using namespace std;

using grpc::Channel;
using grpc::ClientContext;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using backend::FileListRequest;
using backend::FileListReply;
using backend::Empty;
using backend::FileChunk;
using backend::FileChunkRequest;
using backend::Storage;
using backend::UserAccount;
using backend::UserAccountReply;
using backend::Log;
using backend::Buffer;
using backend::MemTableInfo;

string  primary_server_ip = "0.0.0.0:50053";
string  replica_server_ip = "0.0.0.0:50054";

// Indexer service in-memory storage
Indexer indexer_service;

// File service in-memory storage
BigTabler bigtable_service(primary_server_ip);

// Log mutex
mutex primary_mutex;

// Log file
string log_file = "primary_log.txt";

/*
 * Client Class to call replica server
 */
class ReplicaClient {
public:
    ReplicaClient(std::shared_ptr<Channel> channel) : stub_(Storage::NewStub(channel)) {}

    // Assambles the client's payload, sends it and presents the response back
    // from the server.
    int InsertFileList_Backup(string foldername) {
        // Data we are sending to the server.
        FileListRequest request;
        request.set_foldername(foldername);

        // Container for the data we expect from the server.
        Empty reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->InsertFileList(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            return 1;
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

    int CreateUser_Backup(string username, string password) {
        // Data we are sending to the server.
        UserAccount request;
        request.set_username(username);
        request.set_password(password);

        // Container for the data we expect from the server.
        Empty reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->CreateUser(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            return 1;
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

    int PutFile_Backup(string username, string filename, unsigned int length, string filetype, unsigned char* data) {
        // Data we are sending to the server.
        FileChunk request;
        request.set_username(username);
        request.set_filename(filename);
        request.set_length(length);
        request.set_filetype(filetype);
        request.set_data((char *) data, length);

        // Container for the data we expect from the server.
        Empty reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->PutFile(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            return 1;
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

    int UpdateFile_Backup(string username, string filename, unsigned int length, string filetype, unsigned char* data, unsigned int orig_length, unsigned char* orig_data) {
        // Data we are sending to the server.
        FileChunk request;
        request.set_username(username);
        request.set_filename(filename);
        request.set_length(length);
        request.set_filetype(filetype);
        request.set_data((char *) data, length);
        request.set_orig_length(orig_length);
        request.set_orig_data((char *) orig_data, orig_length);

        // Container for the data we expect from the server.
        Empty reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->UpdateFile(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            return 1;
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

    int DeleteFile_Backup(string username, string filename) {
        // Data we are sending to the server.
        FileChunkRequest request;
        request.set_username(username);
        request.set_filename(filename);

        // Container for the data we expect from the server.
        Empty reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->DeleteFile(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            return 1;
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

    int GetLog_Backup(string& buffer) {
        Empty request;
        Log reply;
        ClientContext context;
        Status status = stub_->GetLog(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            buffer = reply.data();
            return 1;
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

    int GetBuffer_Backup(string& buffer, unsigned int& pt) {
        Empty request;
        Buffer reply;
        ClientContext context;
        Status status = stub_->GetBuffer(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            fprintf(stderr, "GetBuffer_Backup pt: %lu\n", reply.size());
            pt = reply.size();

            buffer = reply.data();

            return 1;
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return -1;
        }
    }

private:
    std::unique_ptr<Storage::Stub> stub_;
};

ReplicaClient replicar(grpc::CreateChannel(replica_server_ip, grpc::InsecureChannelCredentials()));

// Logic and data behind the server's behavior.
class StorageServiceImpl final : public Storage::Service {

    Status CreateUser(ServerContext* context, const UserAccount* request, Empty* reply) override {
        // Lock primary
        primary_mutex.lock();

        // Send to replica server
        if (replicar.CreateUser_Backup(request->username(), request->password()) == -1) {
            fprintf(stderr, "CreateUser: replica rpc return -1, possibly replica down\n");
        }

        // Write to primary log
        string log("CreateUser:insert(" + request->username() + ",false):createuser(" + request->username() + "," + request->password() + ")\n");
        writeToLog(log);

        int success1 = indexer_service.insert(request->username(), false);

        if (success1 == -1) {
            primary_mutex.unlock();
            return Status::CANCELLED;
        }

        fprintf(stdout, "Insert into indexer successfully\n");
        int success2 = bigtable_service.createuser(request->username(), request->password());
        if (success2 == 1) {
            fprintf(stdout, "Insert into bigtabler successfully\n");
            primary_mutex.unlock();
            return Status::OK;
        } else {
            primary_mutex.unlock();
            return Status::CANCELLED;
        }
    }

    Status CheckPassword(ServerContext* context, const UserAccount* request, UserAccountReply* reply) override {

        // Lock primary
        primary_mutex.lock();

        string res;
        int success = bigtable_service.getpassword(request->username(), res);
        //fprintf(stderr, "success: %d\n", success);
        if (success == 1) {
            if (res.compare(request->password()) == 0) {
                reply->set_correct(true);
                primary_mutex.unlock();
                return Status::OK;
            }
        }

        reply->set_correct(false);
        primary_mutex.unlock();
        return Status::OK;
    }

    Status GetFileList(ServerContext* context, const FileListRequest* request, FileListReply* reply) override {

        // Lock primary
        primary_mutex.lock();

        map<string, Node> res;
        int success = indexer_service.display(request->foldername(), res);
        //fprintf(stderr, "success: %d\n", success);
        if (success == 1) {
            for (map<string, Node>::iterator it = res.begin(); it != res.end(); ++it) {
                backend::FileInfo fi;
                fi.set_full_path(it->second.full_name);
                fi.set_name(it->second.node_name);
                fi.set_is_file(it->second.is_file);
                (*reply->mutable_filelist())[it->first] = fi;
            }

            primary_mutex.unlock();
            return Status::OK;
        } else {
            primary_mutex.unlock();
            return Status::CANCELLED;
        }
    }

    Status InsertFileList(ServerContext* context, const FileListRequest* request, Empty* reply) override {

        // Lock primary
        primary_mutex.lock();

        // Send to replica server
        if (replicar.InsertFileList_Backup(request->foldername()) == -1) {
            fprintf(stderr, "InsertFileList: replica rpc return -1, possibly replica down\n");
        }

        // Write to primary log
        string log("InsertFileList:insert(" + request->foldername() + ",false)\n");
        writeToLog(log);

        int success = indexer_service.insert(request->foldername(), false);
        if (success == 1) {
            primary_mutex.unlock();
            return Status::OK;
        } else {
            primary_mutex.unlock();
            return Status::CANCELLED;
        }
    }

    Status PutFile(ServerContext* context, const FileChunk* request, Empty* reply) override {

        // Lock primary
        primary_mutex.lock();

        unsigned char *data_temp = new unsigned char [request->length()];

        memcpy(data_temp, request->data().c_str(), request->length());

        // Send to replica server
        if (replicar.PutFile_Backup(request->username(), request->filename(), request->length(), request->filetype(), data_temp) == -1) {
            fprintf(stderr, "PutFile: replica rpc return -1, possibly repica down\n");
        }

        // Write to log
        string log("PutFile:put(" + request->username() + "," + request->filename() + "," +  request->filetype() + "," + to_string(request->length()) + "):insert(" + request->username() + "/" + request->filename() + ",true)\n");
        writeToLog(log);

        int success1 = bigtable_service.put(request->username(), request->filename(), data_temp, request->filetype(), request->length());
        int success2 = indexer_service.insert(request->username()+"/"+request->filename(), true);

        free(data_temp);
        if (success1 == 1 && success2 == 1) {
            primary_mutex.unlock();
            return Status::OK;
        } else {
            primary_mutex.unlock();
            return Status::CANCELLED;
        }
    }

    Status UpdateFile(ServerContext* context, const FileChunk* request, Empty* reply) override {

        // Lock primary
        primary_mutex.lock();

        unsigned char *orig_data_temp = new unsigned char [request->orig_length()];
        unsigned char *data_temp = new unsigned char [request->length()];

        memcpy(orig_data_temp, request->orig_data().c_str(), request->orig_length());
        memcpy(data_temp, request->data().c_str(), request->length());

        // Send to replica server
        if (replicar.UpdateFile_Backup(request->username(), request->filename(), request->length(), request->filetype(), data_temp, request->orig_length(), orig_data_temp) == -1) {
            fprintf(stderr, "UpdateFile: replica rpc return -1, possibly repica down\n");
        }

        int success = bigtable_service.cput(request->username(), request->filename(), (unsigned char *) request->orig_data().c_str(), (unsigned char *) request->data().c_str(), request->filetype(), request->orig_length(), request->length());
        if (success == 1) {

            // Write to log
            string log("UpdateFile:delet(" + request->username() + "," + request->filename() + ")" + ":put(" + request->username() + "," + request->filename() + "," + request->filetype() + "," + to_string(request->length()) + ")\n");
            writeToLog(log);

            int success1 = bigtable_service.delet(request->username(), request->filename());

            int success2 = 0;
            if (success1 == 1) {
                success2 = bigtable_service.put(request->username(), request->filename(), data_temp, request->filetype(), request->length());
            } else {
                primary_mutex.unlock();
                return Status::CANCELLED;
            }

            if (success2 == 1) {
                primary_mutex.unlock();
                return Status::OK;
            } else {
                primary_mutex.unlock();
                return Status::CANCELLED;
            }
        } else {
            primary_mutex.unlock();
            return Status::CANCELLED;
        }
    }

    Status GetFile(ServerContext* context, const FileChunkRequest* request, FileChunk* reply) override {

        // Lock primary
        primary_mutex.lock();

        FileMeta* file_meta = bigtable_service.getMeta(request->username(), request->filename());

        if (file_meta == NULL) {
            primary_mutex.unlock();
            return Status::CANCELLED;
        }

        reply->set_username(file_meta->username);
        reply->set_filename(file_meta->file_name);
        reply->set_length(file_meta->file_length);
        reply->set_filetype(file_meta->file_type);

        unsigned char temp[file_meta->file_length];
        int success = bigtable_service.get(request->username(), request->filename(), (unsigned char *) temp, file_meta->file_length);
        if (success == file_meta->file_length) {
            reply->set_data((char *)temp, file_meta->file_length);
            primary_mutex.unlock();
            return Status::OK;
        } else {
            primary_mutex.unlock();
            return Status::CANCELLED;
        }
    }

    Status DeleteFile(ServerContext* context, const FileChunkRequest* request, Empty* reply) override {

        // Lock primary
        primary_mutex.lock();

        // Send to replica server
        if (replicar.DeleteFile_Backup(request->username(), request->filename()) == -1) {
            fprintf(stderr, "DeleteFile: replica rpc return -1, possibly repica down\n");
        }

        //Write to log
        string log("DeleteFile:delet(" + request->username() + ", " + request->filename() + ")\n");
        writeToLog(log);

        pair<int, bool> file_info = indexer_service.checkIsFile(request->username()+"/"+request->filename());

        if (file_info.first == -1) {
            primary_mutex.unlock();
            return Status::CANCELLED;
        }

        if (file_info.second) {
            int success1 = indexer_service.delet(request->username()+"/"+request->filename());
            if (success1 == -1) {
                primary_mutex.unlock();
                return Status::CANCELLED;
            }
            int success2 = bigtable_service.delet(request->username(), request->filename());
            if (success1 == 1 && success2 == 1) {
                primary_mutex.unlock();
                return Status::OK;
            } else {
                primary_mutex.unlock();
                return Status::CANCELLED;
            }
        } else {
            vector<string> delete_candidates;
            int success = indexer_service.findAllChildren(request->username()+"/"+request->filename(), delete_candidates);
            if (success == -1) {
                primary_mutex.unlock();
                return Status::CANCELLED;
            }

            int success1 = indexer_service.delet(request->username()+"/"+request->filename());
            if (success1 == -1) {
                primary_mutex.unlock();
                return Status::CANCELLED;
            }

            int success2 = 1;
            for (string str : delete_candidates) {
                int delim = str.find("/");
                success2 = (success2 == 1 && bigtable_service.delet(str.substr(0, delim), str.substr(delim+1, str.length()-delim-1)) == 1) ? 1 : -1;
            }

            if (success1 == 1 && success2 == 1) {
                primary_mutex.unlock();
                return Status::OK;
            } else {
                primary_mutex.unlock();
                return Status::CANCELLED;
            }
        }
    }

    Status GetLog(ServerContext* context, const Empty* request, Log* reply) override {

        ifstream ifs(log_file, ios::binary|ios::ate);
        int pos = ifs.tellg();
        //fprintf(stderr, "pos: %d", pos);

        char result[pos];

        ifs.seekg(0, ios::beg);
        ifs.read(result, pos);

        reply->set_size(pos);
        reply->set_data(result, pos);
        return Status::OK;
    }

    Status GetBuffer(ServerContext* context, const Empty* request, Buffer* reply) override {
        unsigned char result[bigtable_service.getCur_pt()];
        bigtable_service.getMemtable(result, (int) bigtable_service.getCur_pt());

        reply->set_size(bigtable_service.getCur_pt());
        fprintf(stderr, "Give size from bigtable_service.getCur_pt(): %d\n", (int) bigtable_service.getCur_pt());
        reply->set_data(result, (int) bigtable_service.getCur_pt());

        return Status::OK;
    }

    Status GetMemTableInfo (ServerContext* context, const Empty* request, MemTableInfo* reply) override {
        // cout << "Here!!!!\n";
        reply->set_buffer_length(bigtable_service.getCur_pt());
        // cout << "Here!!!!Here!!!\n";
        return Status::OK;
    }
};

void RunServer() {

    ofstream of(log_file, ostream::out | ostream::app);
    of.close();

    // Primary port
    std::string primary_server_address(primary_server_ip);
    StorageServiceImpl primary_service;

    ServerBuilder primary_builder;
    // Listen on the given address without any authentication mechanism.
    primary_builder.AddListeningPort(primary_server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    primary_builder.RegisterService(&primary_service);
    // Finally assemble the server.
    std::unique_ptr<Server> primary_server(primary_builder.BuildAndStart());
    std::cout << "Server primary listening on " << primary_server_address << std::endl;

    /*
    // Replica port
    std::string replica_server_address(replica_server_ip);
    StorageServiceImpl replica_service;

    ServerBuilder replica_builder;
    // Listen on the given address without any authentication mechanism.
    replica_builder.AddListeningPort(replica_server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    replica_builder.RegisterService(&replica_service);
    // Finally assemble the server.
    std::unique_ptr<Server> replica_server(replica_builder.BuildAndStart());
    std::cout << "Server replica listening on " << replica_server_address << std::endl;

    replica_server->Wait();
    */

    RunRestart();
    RunGC();
    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.


    primary_server->Wait();
}

void* gcHelper(void*) {
    int res = 1;
    while (res == 1) {
        sleep(DELETE_BUFFER_TIME);
        res = bigtable_service.gc(log_file);
    }
    pthread_exit(NULL);
}

void RunGC() {
    int rc = 0;
    pthread_t gcthread;

    pthread_create(&gcthread, NULL, &gcHelper, NULL);
}

void RunRestart() {

    string buffer;
    if (replicar.GetLog_Backup(buffer) == -1) {
        fprintf(stderr, "GetLog_Backup fail!\n");
        return;
    }

    fprintf(stderr, "Get log successfully! Log size: %zu\n", strlen(buffer.c_str()));

    ofstream outfile("primary_log_tmp.txt");

    stringstream ss(buffer);
    string line;
    while (getline(ss, line)) {
        replicaLogParser(line, outfile);
    }

    ifstream myfile(log_file);
    if (myfile) {
        while (getline(myfile, line)) {
            primaryLogParser(line, outfile);
        }
        myfile.close();
    }

    string memtable;
    unsigned int pt;
    if (replicar.GetBuffer_Backup(memtable, pt) == -1) {
        fprintf(stderr, "GetBuffer_Backup fail!\n");
    }

    fprintf(stderr, "Get buffer successfully! Buffersize: %zu\n", memtable.size());

    bigtable_service.setMemtable(memtable, pt);
    bigtable_service.setCur_pt(pt);

    outfile.close();
    remove("primary_log.txt");
    rename("primary_log_tmp.txt", "primary_log.txt");
}

int main(int argc, char** argv) {
    /* Indexer test
    cout << indexer_service.insert("/tianli", false) << endl;
    cout << indexer_service.insert("/tianli/folder1", false) << endl;
    cout << indexer_service.insert("/tianli/folder2", false) << endl;
    cout << indexer_service.insert("/tianli/file3", true) << endl;
    cout << indexer_service.insert("/tianli/folder1/folder1.1", false) << endl;
    map<string, Node> res;
    int success = indexer_service.display("/tianli", res);
    cout << success << endl;
    for (map<string, Node>::iterator it = res.begin(); it != res.end(); ++it) {
        cout << it->first << " " << it->second.is_file << endl;
    }
    */

    /* File storage test
    ifstream ifs1("file1.txt", ios::binary|ios::ate);
    ifstream::pos_type pos1 = ifs1.tellg();

    int length1 = pos1;

    char *pChars1 = new char[length1];
    ifs1.seekg(0, ios::beg);
    ifs1.read(pChars1, length1);
    ifs1.close();

    cout << "First put" << endl;
    cout << bigtable_service.put("tianli", "file1", (unsigned char *) pChars1, ".txt", length1) << endl;

    ifstream ifs2("file2.txt", ios::binary|ios::ate);
    ifstream::pos_type pos2 = ifs2.tellg();

    int length2 = pos2;

    char *pChars2 = new char[length2];
    ifs2.seekg(0, ios::beg);
    ifs2.read(pChars2, length2);
    ifs2.close();

    cout << "second put" << endl;
    cout << bigtable_service.put("tianli", "file2", (unsigned char *) pChars2, ".txt", length2) << endl;

    char *pChars3 = new char[length2+1];
    pChars3[length2] = '\0';
    cout << "get file2, length:" << length2 << endl;
    cout << bigtable_service.get("tianli", "file2", (unsigned char *) pChars3, length2) << endl;

    printf("%s\n", pChars3);

    cout << indexer_service.delet("tianli/file2") << endl;
    cout << bigtable_service.delet("tianli", "file2") << endl;
    cout << indexer_service.delet("tianli/folder2") << endl;
    */

    // int c;
    // Read command line opts
    // while ((c = getopt (argc, argv, "p:r:")) != -1) {
    //     switch (c) {
    //         case 'p': primary_server_ip += optarg; log_file += optarg; log_file += ".txt"; break;
    //         case 'r': replica_server_ip += optarg; break;
    //         case '?':
    //             if (optopt == 'p' || optopt == 'r')
    //                 fprintf(stderr, "Option -%c requires an argument.\n", optopt);
    //             else if (isprint(optopt))
    //                 fprintf(stderr, "Unknown option '-%c'.\n", optopt);
    //             else
    //                 fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
    //             return -1;
    //         default: abort(); break;
    //     }
    // }

    RunServer();

    return 0;
}

void writeToLog(string& msg) {
    bigtable_service.log_mutex.lock();
    ofstream replica_log(log_file, ofstream::app);
    replica_log.write(msg.c_str(), msg.size());
    replica_log.close();
    bigtable_service.log_mutex.unlock();
}

void replicaLogParser(string line, ofstream& outfile) {
    istringstream ss(line);
    string group;
    getline(ss, group, ':');
    if (strcmp(group.c_str(), "CreateUser") == 0) {
        fprintf(stderr, "CreateUser handler\n");
        outfile.write((line+"\n").c_str(), strlen((line+"\n").c_str()));
        string username;
        getline(ss, username, '(');
        getline(ss, username, ',');
        indexer_service.insert(username, false);

        string password;
        getline(ss, password, ',');
        getline(ss, password, ')');
        bigtable_service.createuser(username, password);

    } else if (strcmp(group.c_str(), "InsertFileList") == 0) {
        fprintf(stderr, "InsertFileList handler\n");
        outfile.write((line+"\n").c_str(), strlen((line+"\n").c_str()));
        string username;
        getline(ss, username, '(');
        getline(ss, username, ',');
        indexer_service.insert(username, false);

    } else if (strcmp(group.c_str(), "PutFile") == 0) {
        fprintf(stderr, "PutFile handler\n");
        outfile.write((line+"\n").c_str(), strlen((line+"\n").c_str()));
        string username, filename, filetype, filelength;
        getline(ss, username, '(');
        getline(ss, username, ',');
        getline(ss, filename, ',');
        getline(ss, filetype, ',');
        getline(ss, filelength, ')');
        bigtable_service.put(username, filename, filetype, stoul(filelength));

        indexer_service.insert(username+"/"+filename, true);

    } else if (strcmp(group.c_str(), "UpdateFile") == 0) {
        fprintf(stderr, "UpdateFile handler\n");
        outfile.write((line+"\n").c_str(), strlen((line+"\n").c_str()));
        string username, filename, filetype, filelength;
        getline(ss, username, '(');
        getline(ss, username, ',');
        getline(ss, filename, ')');
        getline(ss, filetype, ',');
        getline(ss, filetype, ',');
        getline(ss, filetype, ',');
        getline(ss, filelength, ')');
        bigtable_service.delet(username, filename);
        bigtable_service.put(username, filename, filetype, stoul(filelength));

    } else if (strcmp(group.c_str(), "DeleteFile") == 0) {
        fprintf(stderr, "DeleteFile handler\n");
        outfile.write((line+"\n").c_str(), strlen((line+"\n").c_str()));
        string username, filename, filetype, filelength;
        getline(ss, username, '(');
        getline(ss, username, ',');
        getline(ss, filename, ')');
        bigtable_service.delet(username, filename);

    } else if (strcmp(group.c_str(), "GC") == 0) {
        // No need for GC:
    }

}

void primaryLogParser(string line, ofstream& outfile) {
    istringstream ss(line);
    string group;
    getline(ss, group, ':');
    if (strcmp(group.c_str(), "GC") == 0) {
        fprintf(stderr, "GC handler\n");
        outfile.write((line+"\n").c_str(), strlen((line+"\n").c_str()));
        string sstable;
        getline(ss, sstable, ',');

        string size;
        getline(ss, size, ',');
        int length = stoi(size);
        //string temp[length];
        vector<string> temp;
        string str;
        for (int i = 0; i < length; i++) {
            getline(ss, str, ',');
            temp.push_back(str);
        }
        bigtable_service.gcLog(sstable, temp, length);
    }
}