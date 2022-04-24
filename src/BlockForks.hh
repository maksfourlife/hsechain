#pragma once
#include <map>
#include <set>
#include <leveldb/db.h>
#include "Block.hh"

class BlockForks
{
private:
    std::map<std::vector<uint8_t>, Block *> blocks;
    std::map<std::vector<uint8_t>, Block *> top;

public:
    void addBlock(Block *block);
    void load(leveldb::DB &db);
    ~BlockForks();
};
