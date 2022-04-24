#pragma once
#include <string>
#include <vector>
#include "Consensus.hh"
#include "BlockForks.hh"

class Node
{
public:
    Consensus *cons;
    BlockForks *bf;
    std::vector<std::string> nodes;

    Node(
        Consensus *cons,
        BlockForks *bf,
        std::vector<std::string> &bootNodes,
        leveldb::DB *db);
    void start();
};
