#pragma once
#include <vector>
#include <json_struct/json_struct.h>

#define HASH_SIZE 32

struct Block
{
    std::vector<uint8_t> hash;
    std::vector<uint8_t> parentHash;
    std::vector<std::vector<uint8_t>> transactions;
    JS_OBJ(hash, parentHash, transactions);
    std::vector<uint8_t> ser();
    Block de(const std::vector<uint8_t> &rawBlock);
};