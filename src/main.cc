#include <iostream>
#include <string>

#include "Node.hh"

int main()
{
    leveldb::DB *db;
    std::vector<std::string> bNodes;
    Node node(new Consensus(), new BlockForks(), bNodes, db);
    node.start();
}
