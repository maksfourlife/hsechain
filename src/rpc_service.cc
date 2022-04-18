#include "rpc_service.hh"

RpcService::RpcService(Node *node, uint16_t port)
{
    this->node = node;

    this->server = new rpc::server(port);
    this->server->bind("getVersion", [this]()
                       { return this->getVersion(); });

    this->server->async_run();
}

std::string RpcService::getVersion()
{
    return "Hsechain v0.1.0";
}
