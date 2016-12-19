// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: master.proto

#include "master.pb.h"
#include "master.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace master {

static const char* Master_method_names[] = {
  "/master.Master/GetUserAddr",
  "/master.Master/CreateUser",
  "/master.Master/GetNodesStatus",
  "/master.Master/GetNodesInfo",
  "/master.Master/DisableNode",
  "/master.Master/EnableNode",
  "/master.Master/SendMemTableInfo",
};

std::unique_ptr< Master::Stub> Master::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< Master::Stub> stub(new Master::Stub(channel));
  return stub;
}

Master::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_GetUserAddr_(Master_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CreateUser_(Master_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetNodesStatus_(Master_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetNodesInfo_(Master_method_names[3], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DisableNode_(Master_method_names[4], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_EnableNode_(Master_method_names[5], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendMemTableInfo_(Master_method_names[6], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Master::Stub::GetUserAddr(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::master::AddressReply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_GetUserAddr_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::master::AddressReply>* Master::Stub::AsyncGetUserAddrRaw(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::master::AddressReply>(channel_.get(), cq, rpcmethod_GetUserAddr_, context, request);
}

::grpc::Status Master::Stub::CreateUser(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::master::Empty* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_CreateUser_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::master::Empty>* Master::Stub::AsyncCreateUserRaw(::grpc::ClientContext* context, const ::master::UserNameRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::master::Empty>(channel_.get(), cq, rpcmethod_CreateUser_, context, request);
}

::grpc::Status Master::Stub::GetNodesStatus(::grpc::ClientContext* context, const ::master::Empty& request, ::master::NodesStatusReply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_GetNodesStatus_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::master::NodesStatusReply>* Master::Stub::AsyncGetNodesStatusRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::master::NodesStatusReply>(channel_.get(), cq, rpcmethod_GetNodesStatus_, context, request);
}

::grpc::Status Master::Stub::GetNodesInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::master::NodesInfoReply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_GetNodesInfo_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::master::NodesInfoReply>* Master::Stub::AsyncGetNodesInfoRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::master::NodesInfoReply>(channel_.get(), cq, rpcmethod_GetNodesInfo_, context, request);
}

::grpc::Status Master::Stub::DisableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::master::Empty* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_DisableNode_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::master::Empty>* Master::Stub::AsyncDisableNodeRaw(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::master::Empty>(channel_.get(), cq, rpcmethod_DisableNode_, context, request);
}

::grpc::Status Master::Stub::EnableNode(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::master::Empty* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_EnableNode_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::master::Empty>* Master::Stub::AsyncEnableNodeRaw(::grpc::ClientContext* context, const ::master::NodeIndexRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::master::Empty>(channel_.get(), cq, rpcmethod_EnableNode_, context, request);
}

::grpc::Status Master::Stub::SendMemTableInfo(::grpc::ClientContext* context, const ::master::Empty& request, ::master::MemTableInfoReply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_SendMemTableInfo_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::master::MemTableInfoReply>* Master::Stub::AsyncSendMemTableInfoRaw(::grpc::ClientContext* context, const ::master::Empty& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::master::MemTableInfoReply>(channel_.get(), cq, rpcmethod_SendMemTableInfo_, context, request);
}

Master::Service::Service() {
  (void)Master_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      Master_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Master::Service, ::master::UserNameRequest, ::master::AddressReply>(
          std::mem_fn(&Master::Service::GetUserAddr), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Master_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Master::Service, ::master::UserNameRequest, ::master::Empty>(
          std::mem_fn(&Master::Service::CreateUser), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Master_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Master::Service, ::master::Empty, ::master::NodesStatusReply>(
          std::mem_fn(&Master::Service::GetNodesStatus), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Master_method_names[3],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Master::Service, ::master::Empty, ::master::NodesInfoReply>(
          std::mem_fn(&Master::Service::GetNodesInfo), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Master_method_names[4],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Master::Service, ::master::NodeIndexRequest, ::master::Empty>(
          std::mem_fn(&Master::Service::DisableNode), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Master_method_names[5],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Master::Service, ::master::NodeIndexRequest, ::master::Empty>(
          std::mem_fn(&Master::Service::EnableNode), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Master_method_names[6],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Master::Service, ::master::Empty, ::master::MemTableInfoReply>(
          std::mem_fn(&Master::Service::SendMemTableInfo), this)));
}

Master::Service::~Service() {
}

::grpc::Status Master::Service::GetUserAddr(::grpc::ServerContext* context, const ::master::UserNameRequest* request, ::master::AddressReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Master::Service::CreateUser(::grpc::ServerContext* context, const ::master::UserNameRequest* request, ::master::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Master::Service::GetNodesStatus(::grpc::ServerContext* context, const ::master::Empty* request, ::master::NodesStatusReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Master::Service::GetNodesInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::NodesInfoReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Master::Service::DisableNode(::grpc::ServerContext* context, const ::master::NodeIndexRequest* request, ::master::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Master::Service::EnableNode(::grpc::ServerContext* context, const ::master::NodeIndexRequest* request, ::master::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Master::Service::SendMemTableInfo(::grpc::ServerContext* context, const ::master::Empty* request, ::master::MemTableInfoReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace master

