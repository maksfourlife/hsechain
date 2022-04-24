#include <json_struct/json_struct.h>
#include "BlockForks.hh"

void BlockForks::addBlock(Block *block)
{
    this->blocks.insert({block->hash, block});
    if (this->top.find(block->hash) != this->top.end())
    {
    }
}

void BlockForks::load(leveldb::DB &db)
{
    leveldb::Iterator *it = db.NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next())
    {
        // add checks and determijne if you are using a single db or 3 separated
        Block b;
        JS::ParseContext ctx(it->value().data());
        ctx.parseTo(b);
        this->addBlock(new Block(b));
        // this->addBlock(b);
    };
}

BlockForks::~BlockForks()
{
    for (auto it : this->blocks)
    {
        delete it.second;
    }
}