#pragma once
#include "Node.hh"
#include <rpc/server.h>

class RpcService
{
private:
    Node *node;
    rpc::server *server;

    std::string getVersion();
    std::vector<std::string> getNodes();
    std::string getBalance(std::string account);
    std::string getData(std::string account);
    std::string sendTransaction(std::string transaction);

public:
    RpcService(Node *node, uint16_t port);
};
