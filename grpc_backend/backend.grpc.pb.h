// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: backend.proto
// Original file comments:
// Copyright 2015, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
#ifndef GRPC_backend_2eproto__INCLUDED
#define GRPC_backend_2eproto__INCLUDED

#include "backend.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace backend {

// The storage service definition.
class Storage GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Frontend Backend Communication
    // Get file list
    virtual ::grpc::Status GetFileList(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::backend::FileListReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::FileListReply>> AsyncGetFileList(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::FileListReply>>(AsyncGetFileListRaw(context, request, cq));
    }
    // Insert a directory
    virtual ::grpc::Status InsertFileList(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::backend::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>> AsyncInsertFileList(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>>(AsyncInsertFileListRaw(context, request, cq));
    }
    // Upload a file
    virtual ::grpc::Status PutFile(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::backend::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>> AsyncPutFile(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>>(AsyncPutFileRaw(context, request, cq));
    }
    // Update a file
    virtual ::grpc::Status UpdateFile(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::backend::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>> AsyncUpdateFile(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>>(AsyncUpdateFileRaw(context, request, cq));
    }
    // Get a file
    virtual ::grpc::Status GetFile(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::backend::FileChunk* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::FileChunk>> AsyncGetFile(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::FileChunk>>(AsyncGetFileRaw(context, request, cq));
    }
    // Delete a file
    virtual ::grpc::Status DeleteFile(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::backend::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>> AsyncDeleteFile(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>>(AsyncDeleteFileRaw(context, request, cq));
    }
    // Backend Backend Communication
    // Insert a directory
    virtual ::grpc::Status InsertFileList_Back(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::backend::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>> AsyncInsertFileList_Back(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>>(AsyncInsertFileList_BackRaw(context, request, cq));
    }
    // Upload a file
    virtual ::grpc::Status PutFile_Back(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::backend::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>> AsyncPutFile_Back(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>>(AsyncPutFile_BackRaw(context, request, cq));
    }
    // Update a file
    virtual ::grpc::Status UpdateFile_Back(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::backend::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>> AsyncUpdateFile_Back(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>>(AsyncUpdateFile_BackRaw(context, request, cq));
    }
    // Delete a file
    virtual ::grpc::Status DeleteFile_Back(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::backend::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>> AsyncDeleteFile_Back(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>>(AsyncDeleteFile_BackRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::FileListReply>* AsyncGetFileListRaw(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>* AsyncInsertFileListRaw(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>* AsyncPutFileRaw(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>* AsyncUpdateFileRaw(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::FileChunk>* AsyncGetFileRaw(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>* AsyncDeleteFileRaw(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>* AsyncInsertFileList_BackRaw(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>* AsyncPutFile_BackRaw(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>* AsyncUpdateFile_BackRaw(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::backend::Empty>* AsyncDeleteFile_BackRaw(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status GetFileList(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::backend::FileListReply* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::FileListReply>> AsyncGetFileList(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::FileListReply>>(AsyncGetFileListRaw(context, request, cq));
    }
    ::grpc::Status InsertFileList(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::backend::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>> AsyncInsertFileList(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>>(AsyncInsertFileListRaw(context, request, cq));
    }
    ::grpc::Status PutFile(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::backend::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>> AsyncPutFile(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>>(AsyncPutFileRaw(context, request, cq));
    }
    ::grpc::Status UpdateFile(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::backend::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>> AsyncUpdateFile(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>>(AsyncUpdateFileRaw(context, request, cq));
    }
    ::grpc::Status GetFile(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::backend::FileChunk* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::FileChunk>> AsyncGetFile(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::FileChunk>>(AsyncGetFileRaw(context, request, cq));
    }
    ::grpc::Status DeleteFile(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::backend::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>> AsyncDeleteFile(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>>(AsyncDeleteFileRaw(context, request, cq));
    }
    ::grpc::Status InsertFileList_Back(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::backend::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>> AsyncInsertFileList_Back(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>>(AsyncInsertFileList_BackRaw(context, request, cq));
    }
    ::grpc::Status PutFile_Back(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::backend::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>> AsyncPutFile_Back(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>>(AsyncPutFile_BackRaw(context, request, cq));
    }
    ::grpc::Status UpdateFile_Back(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::backend::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>> AsyncUpdateFile_Back(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>>(AsyncUpdateFile_BackRaw(context, request, cq));
    }
    ::grpc::Status DeleteFile_Back(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::backend::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>> AsyncDeleteFile_Back(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::backend::Empty>>(AsyncDeleteFile_BackRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::backend::FileListReply>* AsyncGetFileListRaw(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::backend::Empty>* AsyncInsertFileListRaw(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::backend::Empty>* AsyncPutFileRaw(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::backend::Empty>* AsyncUpdateFileRaw(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::backend::FileChunk>* AsyncGetFileRaw(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::backend::Empty>* AsyncDeleteFileRaw(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::backend::Empty>* AsyncInsertFileList_BackRaw(::grpc::ClientContext* context, const ::backend::FileListRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::backend::Empty>* AsyncPutFile_BackRaw(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::backend::Empty>* AsyncUpdateFile_BackRaw(::grpc::ClientContext* context, const ::backend::FileChunk& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::backend::Empty>* AsyncDeleteFile_BackRaw(::grpc::ClientContext* context, const ::backend::FileChunkRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_GetFileList_;
    const ::grpc::RpcMethod rpcmethod_InsertFileList_;
    const ::grpc::RpcMethod rpcmethod_PutFile_;
    const ::grpc::RpcMethod rpcmethod_UpdateFile_;
    const ::grpc::RpcMethod rpcmethod_GetFile_;
    const ::grpc::RpcMethod rpcmethod_DeleteFile_;
    const ::grpc::RpcMethod rpcmethod_InsertFileList_Back_;
    const ::grpc::RpcMethod rpcmethod_PutFile_Back_;
    const ::grpc::RpcMethod rpcmethod_UpdateFile_Back_;
    const ::grpc::RpcMethod rpcmethod_DeleteFile_Back_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Frontend Backend Communication
    // Get file list
    virtual ::grpc::Status GetFileList(::grpc::ServerContext* context, const ::backend::FileListRequest* request, ::backend::FileListReply* response);
    // Insert a directory
    virtual ::grpc::Status InsertFileList(::grpc::ServerContext* context, const ::backend::FileListRequest* request, ::backend::Empty* response);
    // Upload a file
    virtual ::grpc::Status PutFile(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response);
    // Update a file
    virtual ::grpc::Status UpdateFile(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response);
    // Get a file
    virtual ::grpc::Status GetFile(::grpc::ServerContext* context, const ::backend::FileChunkRequest* request, ::backend::FileChunk* response);
    // Delete a file
    virtual ::grpc::Status DeleteFile(::grpc::ServerContext* context, const ::backend::FileChunkRequest* request, ::backend::Empty* response);
    // Backend Backend Communication
    // Insert a directory
    virtual ::grpc::Status InsertFileList_Back(::grpc::ServerContext* context, const ::backend::FileListRequest* request, ::backend::Empty* response);
    // Upload a file
    virtual ::grpc::Status PutFile_Back(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response);
    // Update a file
    virtual ::grpc::Status UpdateFile_Back(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response);
    // Delete a file
    virtual ::grpc::Status DeleteFile_Back(::grpc::ServerContext* context, const ::backend::FileChunkRequest* request, ::backend::Empty* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetFileList : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetFileList() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetFileList() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFileList(::grpc::ServerContext* context, const ::backend::FileListRequest* request, ::backend::FileListReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetFileList(::grpc::ServerContext* context, ::backend::FileListRequest* request, ::grpc::ServerAsyncResponseWriter< ::backend::FileListReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_InsertFileList : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_InsertFileList() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_InsertFileList() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status InsertFileList(::grpc::ServerContext* context, const ::backend::FileListRequest* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestInsertFileList(::grpc::ServerContext* context, ::backend::FileListRequest* request, ::grpc::ServerAsyncResponseWriter< ::backend::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_PutFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_PutFile() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_PutFile() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status PutFile(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestPutFile(::grpc::ServerContext* context, ::backend::FileChunk* request, ::grpc::ServerAsyncResponseWriter< ::backend::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_UpdateFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_UpdateFile() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_UpdateFile() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status UpdateFile(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestUpdateFile(::grpc::ServerContext* context, ::backend::FileChunk* request, ::grpc::ServerAsyncResponseWriter< ::backend::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetFile() {
      ::grpc::Service::MarkMethodAsync(4);
    }
    ~WithAsyncMethod_GetFile() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFile(::grpc::ServerContext* context, const ::backend::FileChunkRequest* request, ::backend::FileChunk* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetFile(::grpc::ServerContext* context, ::backend::FileChunkRequest* request, ::grpc::ServerAsyncResponseWriter< ::backend::FileChunk>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(4, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_DeleteFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_DeleteFile() {
      ::grpc::Service::MarkMethodAsync(5);
    }
    ~WithAsyncMethod_DeleteFile() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeleteFile(::grpc::ServerContext* context, const ::backend::FileChunkRequest* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDeleteFile(::grpc::ServerContext* context, ::backend::FileChunkRequest* request, ::grpc::ServerAsyncResponseWriter< ::backend::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(5, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_InsertFileList_Back : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_InsertFileList_Back() {
      ::grpc::Service::MarkMethodAsync(6);
    }
    ~WithAsyncMethod_InsertFileList_Back() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status InsertFileList_Back(::grpc::ServerContext* context, const ::backend::FileListRequest* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestInsertFileList_Back(::grpc::ServerContext* context, ::backend::FileListRequest* request, ::grpc::ServerAsyncResponseWriter< ::backend::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(6, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_PutFile_Back : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_PutFile_Back() {
      ::grpc::Service::MarkMethodAsync(7);
    }
    ~WithAsyncMethod_PutFile_Back() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status PutFile_Back(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestPutFile_Back(::grpc::ServerContext* context, ::backend::FileChunk* request, ::grpc::ServerAsyncResponseWriter< ::backend::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(7, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_UpdateFile_Back : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_UpdateFile_Back() {
      ::grpc::Service::MarkMethodAsync(8);
    }
    ~WithAsyncMethod_UpdateFile_Back() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status UpdateFile_Back(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestUpdateFile_Back(::grpc::ServerContext* context, ::backend::FileChunk* request, ::grpc::ServerAsyncResponseWriter< ::backend::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(8, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_DeleteFile_Back : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_DeleteFile_Back() {
      ::grpc::Service::MarkMethodAsync(9);
    }
    ~WithAsyncMethod_DeleteFile_Back() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeleteFile_Back(::grpc::ServerContext* context, const ::backend::FileChunkRequest* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDeleteFile_Back(::grpc::ServerContext* context, ::backend::FileChunkRequest* request, ::grpc::ServerAsyncResponseWriter< ::backend::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(9, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetFileList<WithAsyncMethod_InsertFileList<WithAsyncMethod_PutFile<WithAsyncMethod_UpdateFile<WithAsyncMethod_GetFile<WithAsyncMethod_DeleteFile<WithAsyncMethod_InsertFileList_Back<WithAsyncMethod_PutFile_Back<WithAsyncMethod_UpdateFile_Back<WithAsyncMethod_DeleteFile_Back<Service > > > > > > > > > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_GetFileList : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetFileList() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetFileList() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFileList(::grpc::ServerContext* context, const ::backend::FileListRequest* request, ::backend::FileListReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_InsertFileList : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_InsertFileList() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_InsertFileList() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status InsertFileList(::grpc::ServerContext* context, const ::backend::FileListRequest* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_PutFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_PutFile() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_PutFile() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status PutFile(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_UpdateFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_UpdateFile() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_UpdateFile() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status UpdateFile(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetFile() {
      ::grpc::Service::MarkMethodGeneric(4);
    }
    ~WithGenericMethod_GetFile() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFile(::grpc::ServerContext* context, const ::backend::FileChunkRequest* request, ::backend::FileChunk* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_DeleteFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_DeleteFile() {
      ::grpc::Service::MarkMethodGeneric(5);
    }
    ~WithGenericMethod_DeleteFile() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeleteFile(::grpc::ServerContext* context, const ::backend::FileChunkRequest* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_InsertFileList_Back : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_InsertFileList_Back() {
      ::grpc::Service::MarkMethodGeneric(6);
    }
    ~WithGenericMethod_InsertFileList_Back() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status InsertFileList_Back(::grpc::ServerContext* context, const ::backend::FileListRequest* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_PutFile_Back : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_PutFile_Back() {
      ::grpc::Service::MarkMethodGeneric(7);
    }
    ~WithGenericMethod_PutFile_Back() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status PutFile_Back(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_UpdateFile_Back : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_UpdateFile_Back() {
      ::grpc::Service::MarkMethodGeneric(8);
    }
    ~WithGenericMethod_UpdateFile_Back() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status UpdateFile_Back(::grpc::ServerContext* context, const ::backend::FileChunk* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_DeleteFile_Back : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_DeleteFile_Back() {
      ::grpc::Service::MarkMethodGeneric(9);
    }
    ~WithGenericMethod_DeleteFile_Back() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DeleteFile_Back(::grpc::ServerContext* context, const ::backend::FileChunkRequest* request, ::backend::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

}  // namespace backend


#endif  // GRPC_backend_2eproto__INCLUDED
