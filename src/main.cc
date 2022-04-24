#include <iostream>
#include <string>
#include <leveldb/db.h>
#include <cassert>
#include <json_struct/json_struct.h>

#include "rpc_client.hh"
#include "rpc_service.hh"
#include "node.hh"

#define PORT 8080

int main()
{
    // auto node = new Node();
    // RpcService rpc(node, PORT);

    // RpcClient client("0.0.0.0", PORT);
    // std::cout << client.getVersion() << std::endl;

    // auto nodes = client.getNodes();
    // for (auto &node : nodes)
    // {
    //     std::cout << node << std::endl;
    // }

    // leveldb::DB *db;
    // leveldb::Options options;
    // options.create_if_missing = true;
    // leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    // assert(status.ok());

    // leveldb::Slice key("Hello");
    // std::string val;
    // db->Get(leveldb::ReadOptions(), key, &val);
    // std::cout << val << std::endl;

    // status = db->Put(leveldb::WriteOptions(), key, "World");
    // assert(status.ok());

    // db would store block and tx hashes
    // we would construct block dag with those hashes
    // top: [*Block]
    // when receive new block, replace one from top if it's its parent (NO)
}
