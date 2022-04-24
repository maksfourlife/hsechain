#include "RpcService.hh"
#include "Transaction.hh"

RpcService::RpcService(Node *node, uint16_t port)
{
    this->node = node;

    this->server = new rpc::server(port);
    this->server->bind("getVersion", [this]()
                       { return this->getVersion(); });
    this->server->bind("getNodes", [this]()
                       { return this->getNodes(); });
    // this->server->bind("getBalance", [this](std::string account)
    //                    { return this->getBalance(account); });
    // this->server->bind("getData", [this](std::string account)
    //                    { return this->getData(account); });
    this->server->bind("sendTransaction", [this](std::string transaction)
                       { return this->sendTransaction(transaction); });
    this->server->async_run();
}

std::string RpcService::getVersion()
{
    return "v1.0.0-alpha";
}

std::vector<std::string> RpcService::getNodes()
{
    return std::vector<std::string>();
}

std::string RpcService::sendTransaction(std::string _tx)
{
    Transaction tx;
    JS::ParseContext ctx(_tx);
    ctx.parseTo(tx);
}
