#include <iostream>
#include <string>
#include <rpc/server.h>
#include <rpc/client.h>

int main()
{
    rpc::server srv(8080);

    srv.bind("hello_world", []()
             { return "hello_world!"; });

    srv.bind("greet", [](std::string name)
             { return "Hello, " + name; });

    srv.async_run();

    rpc::client client("0.0.0.0", 8080);
    auto result = client.call("greet", "max").as<std::string>();
    std::cout << result << std::endl;
}
