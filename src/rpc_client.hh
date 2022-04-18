#pragma once
#include <rpc/client.h>
#include <string>

class RpcClient
{
private:
    rpc::client *client;

public:
    RpcClient(std::string const &addr, uint16_t port);
    std::string getVersion();
};
