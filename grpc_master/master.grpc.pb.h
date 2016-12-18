// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: master.proto
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
#ifndef GRPC_master_2eproto__INCLUDED
#define GRPC_master_2eproto__INCLUDED

#include "master.pb.h"

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

namespace master {

class Master GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Return Type: String
    // Return Format: IP:Port_Number
    // Getting A Address Of A Specified User
    virtual ::grpc::Status GetUserAddr(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::master::AddressReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::AddressReply>> AsyncGetUserAddr(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::AddressReply>>(AsyncGetUserAddrRaw(context, request, cq));
    }
    // Return Type: Empty
    // Create A New User, Assign Node Internally
    virtual ::grpc::Status CreateUser(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::master::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::Empty>> AsyncCreateUser(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::Empty>>(AsyncCreateUserRaw(context, request, cq));
    }
    // Return Type: Map<string, string>
    // Return The Status Of Each Node
    virtual ::grpc::Status GetNodesStatus(::grpc::ClientContext* context, const ::master::Empty& request, ::master::NodesStatusReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::NodesStatusReply>> AsyncGetNodesStatus(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::NodesStatusReply>>(AsyncGetNodesStatusRaw(context, request, cq));
    }
    // Return Type: Map<string, string>
    // Return The Users List For Each Node
    virtual ::grpc::Status GetNodesInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::master::NodesInfoReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::NodesInfoReply>> AsyncGetNodesInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::NodesInfoReply>>(AsyncGetNodesInfoRaw(context, request, cq));
    }
    // Return Type: Empty
    // Disable One Node As Requested
    virtual ::grpc::Status DisableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::master::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::Empty>> AsyncDisableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::Empty>>(AsyncDisableNodeRaw(context, request, cq));
    }
    // Return Type: Empty
    // Disable One Node As Requested
    virtual ::grpc::Status EnableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::master::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::Empty>> AsyncEnableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::Empty>>(AsyncEnableNodeRaw(context, request, cq));
    }
    // As Server
    // Return Type: BufferLength
    // Request Buffer Raw Meta From Storage Node
    virtual ::grpc::Status SendMemTableInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::master::MemTableInfoReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::MemTableInfoReply>> AsyncSendMemTableInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::MemTableInfoReply>>(AsyncSendMemTableInfoRaw(context, request, cq));
    }
    // As Client
    // Return Type: BufferLength
    // Request Buffer Raw Meta From Storage Node
    virtual ::grpc::Status GetMemTableInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::master::MemTableInfo* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::MemTableInfo>> AsyncGetMemTableInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::master::MemTableInfo>>(AsyncGetMemTableInfoRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::master::AddressReply>* AsyncGetUserAddrRaw(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::master::Empty>* AsyncCreateUserRaw(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::master::NodesStatusReply>* AsyncGetNodesStatusRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::master::NodesInfoReply>* AsyncGetNodesInfoRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::master::Empty>* AsyncDisableNodeRaw(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::master::Empty>* AsyncEnableNodeRaw(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::master::MemTableInfoReply>* AsyncSendMemTableInfoRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::master::MemTableInfo>* AsyncGetMemTableInfoRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status GetUserAddr(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::master::AddressReply* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::AddressReply>> AsyncGetUserAddr(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::AddressReply>>(AsyncGetUserAddrRaw(context, request, cq));
    }
    ::grpc::Status CreateUser(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::master::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::Empty>> AsyncCreateUser(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::Empty>>(AsyncCreateUserRaw(context, request, cq));
    }
    ::grpc::Status GetNodesStatus(::grpc::ClientContext* context, const ::master::Empty& request, ::master::NodesStatusReply* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::NodesStatusReply>> AsyncGetNodesStatus(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::NodesStatusReply>>(AsyncGetNodesStatusRaw(context, request, cq));
    }
    ::grpc::Status GetNodesInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::master::NodesInfoReply* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::NodesInfoReply>> AsyncGetNodesInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::NodesInfoReply>>(AsyncGetNodesInfoRaw(context, request, cq));
    }
    ::grpc::Status DisableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::master::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::Empty>> AsyncDisableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::Empty>>(AsyncDisableNodeRaw(context, request, cq));
    }
    ::grpc::Status EnableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::master::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::Empty>> AsyncEnableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::Empty>>(AsyncEnableNodeRaw(context, request, cq));
    }
    ::grpc::Status SendMemTableInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::master::MemTableInfoReply* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::MemTableInfoReply>> AsyncSendMemTableInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::MemTableInfoReply>>(AsyncSendMemTableInfoRaw(context, request, cq));
    }
    ::grpc::Status GetMemTableInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::master::MemTableInfo* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::MemTableInfo>> AsyncGetMemTableInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::master::MemTableInfo>>(AsyncGetMemTableInfoRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::master::AddressReply>* AsyncGetUserAddrRaw(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::master::Empty>* AsyncCreateUserRaw(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::master::NodesStatusReply>* AsyncGetNodesStatusRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::master::NodesInfoReply>* AsyncGetNodesInfoRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::master::Empty>* AsyncDisableNodeRaw(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::master::Empty>* AsyncEnableNodeRaw(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::master::MemTableInfoReply>* AsyncSendMemTableInfoRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::master::MemTableInfo>* AsyncGetMemTableInfoRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_GetUserAddr_;
    const ::grpc::RpcMethod rpcmethod_CreateUser_;
    const ::grpc::RpcMethod rpcmethod_GetNodesStatus_;
    const ::grpc::RpcMethod rpcmethod_GetNodesInfo_;
    const ::grpc::RpcMethod rpcmethod_DisableNode_;
    const ::grpc::RpcMethod rpcmethod_EnableNode_;
    const ::grpc::RpcMethod rpcmethod_SendMemTableInfo_;
    const ::grpc::RpcMethod rpcmethod_GetMemTableInfo_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Return Type: String
    // Return Format: IP:Port_Number
    // Getting A Address Of A Specified User
    virtual ::grpc::Status GetUserAddr(::grpc::ServerContext* context, const ::master::UserNameRequest* request, ::master::AddressReply* response);
    // Return Type: Empty
    // Create A New User, Assign Node Internally
    virtual ::grpc::Status CreateUser(::grpc::ServerContext* context, const ::master::UserNameRequest* request, ::master::Empty* response);
    // Return Type: Map<string, string>
    // Return The Status Of Each Node
    virtual ::grpc::Status GetNodesStatus(::grpc::ServerContext* context, const ::master::Empty* request, ::master::NodesStatusReply* response);
    // Return Type: Map<string, string>
    // Return The Users List For Each Node
    virtual ::grpc::Status GetNodesInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::NodesInfoReply* response);
    // Return Type: Empty
    // Disable One Node As Requested
    virtual ::grpc::Status DisableNode(::grpc::ServerContext* context, const ::master::NodeIndexRequest* request, ::master::Empty* response);
    // Return Type: Empty
    // Disable One Node As Requested
    virtual ::grpc::Status EnableNode(::grpc::ServerContext* context, const ::master::NodeIndexRequest* request, ::master::Empty* response);
    // As Server
    // Return Type: BufferLength
    // Request Buffer Raw Meta From Storage Node
    virtual ::grpc::Status SendMemTableInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::MemTableInfoReply* response);
    // As Client
    // Return Type: BufferLength
    // Request Buffer Raw Meta From Storage Node
    virtual ::grpc::Status GetMemTableInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::MemTableInfo* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetUserAddr : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetUserAddr() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetUserAddr() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetUserAddr(::grpc::ServerContext* context, const ::master::UserNameRequest* request, ::master::AddressReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetUserAddr(::grpc::ServerContext* context, ::master::UserNameRequest* request, ::grpc::ServerAsyncResponseWriter< ::master::AddressReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_CreateUser : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_CreateUser() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_CreateUser() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateUser(::grpc::ServerContext* context, const ::master::UserNameRequest* request, ::master::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCreateUser(::grpc::ServerContext* context, ::master::UserNameRequest* request, ::grpc::ServerAsyncResponseWriter< ::master::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetNodesStatus : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetNodesStatus() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_GetNodesStatus() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetNodesStatus(::grpc::ServerContext* context, const ::master::Empty* request, ::master::NodesStatusReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetNodesStatus(::grpc::ServerContext* context, ::master::Empty* request, ::grpc::ServerAsyncResponseWriter< ::master::NodesStatusReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetNodesInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetNodesInfo() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_GetNodesInfo() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetNodesInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::NodesInfoReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetNodesInfo(::grpc::ServerContext* context, ::master::Empty* request, ::grpc::ServerAsyncResponseWriter< ::master::NodesInfoReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_DisableNode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_DisableNode() {
      ::grpc::Service::MarkMethodAsync(4);
    }
    ~WithAsyncMethod_DisableNode() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DisableNode(::grpc::ServerContext* context, const ::master::NodeIndexRequest* request, ::master::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDisableNode(::grpc::ServerContext* context, ::master::NodeIndexRequest* request, ::grpc::ServerAsyncResponseWriter< ::master::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(4, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_EnableNode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_EnableNode() {
      ::grpc::Service::MarkMethodAsync(5);
    }
    ~WithAsyncMethod_EnableNode() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status EnableNode(::grpc::ServerContext* context, const ::master::NodeIndexRequest* request, ::master::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestEnableNode(::grpc::ServerContext* context, ::master::NodeIndexRequest* request, ::grpc::ServerAsyncResponseWriter< ::master::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(5, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SendMemTableInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_SendMemTableInfo() {
      ::grpc::Service::MarkMethodAsync(6);
    }
    ~WithAsyncMethod_SendMemTableInfo() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendMemTableInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::MemTableInfoReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendMemTableInfo(::grpc::ServerContext* context, ::master::Empty* request, ::grpc::ServerAsyncResponseWriter< ::master::MemTableInfoReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(6, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetMemTableInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetMemTableInfo() {
      ::grpc::Service::MarkMethodAsync(7);
    }
    ~WithAsyncMethod_GetMemTableInfo() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetMemTableInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::MemTableInfo* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetMemTableInfo(::grpc::ServerContext* context, ::master::Empty* request, ::grpc::ServerAsyncResponseWriter< ::master::MemTableInfo>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(7, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetUserAddr<WithAsyncMethod_CreateUser<WithAsyncMethod_GetNodesStatus<WithAsyncMethod_GetNodesInfo<WithAsyncMethod_DisableNode<WithAsyncMethod_EnableNode<WithAsyncMethod_SendMemTableInfo<WithAsyncMethod_GetMemTableInfo<Service > > > > > > > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_GetUserAddr : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetUserAddr() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetUserAddr() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetUserAddr(::grpc::ServerContext* context, const ::master::UserNameRequest* request, ::master::AddressReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_CreateUser : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_CreateUser() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_CreateUser() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateUser(::grpc::ServerContext* context, const ::master::UserNameRequest* request, ::master::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetNodesStatus : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetNodesStatus() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_GetNodesStatus() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetNodesStatus(::grpc::ServerContext* context, const ::master::Empty* request, ::master::NodesStatusReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetNodesInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetNodesInfo() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_GetNodesInfo() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetNodesInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::NodesInfoReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_DisableNode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_DisableNode() {
      ::grpc::Service::MarkMethodGeneric(4);
    }
    ~WithGenericMethod_DisableNode() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DisableNode(::grpc::ServerContext* context, const ::master::NodeIndexRequest* request, ::master::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_EnableNode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_EnableNode() {
      ::grpc::Service::MarkMethodGeneric(5);
    }
    ~WithGenericMethod_EnableNode() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status EnableNode(::grpc::ServerContext* context, const ::master::NodeIndexRequest* request, ::master::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SendMemTableInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_SendMemTableInfo() {
      ::grpc::Service::MarkMethodGeneric(6);
    }
    ~WithGenericMethod_SendMemTableInfo() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendMemTableInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::MemTableInfoReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetMemTableInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetMemTableInfo() {
      ::grpc::Service::MarkMethodGeneric(7);
    }
    ~WithGenericMethod_GetMemTableInfo() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetMemTableInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::MemTableInfo* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

}  // namespace master


#endif  // GRPC_master_2eproto__INCLUDED