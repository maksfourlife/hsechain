#pragma once
#include "node.hh"
#include <rpc/server.h>

class RpcService
{
private:
    Node *node;
    rpc::server *server;

    std::string getVersion();

public:
    RpcService(Node *node, uint16_t port);
};
