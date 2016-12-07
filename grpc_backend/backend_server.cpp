//
// Created by tianli on 12/4/16.
//

#include <iostream>
#include <memory>
#include <string>
#include <map>

#include <grpc++/grpc++.h>

#include "backend.grpc.pb.h"
#include "Indexer.h"

using namespace std;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using backend::FileListRequest;
using backend::FileListReply;
using backend::Storage;

// Indexer service in-memory storage
Indexer indexer_service;

// Logic and data behind the server's behavior.
class StorageServiceImpl final : public Storage::Service {
    Status GetFileList(ServerContext* context, const FileListRequest* request, FileListReply* reply) override {
        map<string, Node*> res;
        int success = indexer_service.display(request->foldername(), res);
        if (success == 1) {
            for (map<string, Node*>::iterator it = res.begin(); it != res.end(); ++it) {
                backend::FileInfo fi;
                fi.set_name(it->second->name);
                fi.set_is_file(it->second->is_file);
                (*reply->mutable_filelist())[it->first] = fi;
            }

            return Status::OK;
        } else {
            return Status::CANCELLED;
        }
    }

    Status InsertFileList(ServerContext* context, const FileListRequest* request, FileListReply* reply) override {
        int success = indexer_service.insert(request->foldername(), request->is_file());
        if (success == 1) {
            return Status::OK;
        } else {
            return Status::CANCELLED;
        }

    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    StorageServiceImpl service;

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}