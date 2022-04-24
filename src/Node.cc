#include "Node.hh"

Node::Node(
    Consensus *cons,
    BlockForks *bf,
    std::vector<std::string> &bNodes,
    leveldb::DB *db)
{
    this->cons = cons;
    this->bf = bf;
    for (auto node : bNodes)
    {
        this->nodes.push_back(node);
    }
}

void Node::start()
{
}