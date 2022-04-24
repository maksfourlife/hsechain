#pragma once
#include <rpc/client.h>
#include <string>
#include "Transaction.hh"

class RpcClient
{
private:
    rpc::client *client;

public:
    RpcClient(std::string const &addr, uint16_t port);
    std::string getVersion();
    std::vector<std::string> getNodes();
    std::string sendTransaction(Transaction &tx);
};
