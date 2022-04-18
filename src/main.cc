#include <iostream>
#include <string>

#include "rpc_client.hh"
#include "rpc_service.hh"
#include "node.hh"

int main()
{
    auto node = new Node();
    RpcService rpc(node, 8080);

    RpcClient client("0.0.0.0", 8080);
    std::cout << client.getVersion() << std::endl;
}
