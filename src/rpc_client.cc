#include "rpc_client.hh"

RpcClient::RpcClient(std::string const &addr, uint16_t port)
{
    this->client = new rpc::client(addr, port);
}

std::string RpcClient::getVersion()
{
    return this->client->call("getVersion").as<std::string>();
}

std::vector<std::string> RpcClient::getNodes()
{
    return this->client->call("getNodes").as<std::vector<std::string>>();
}
