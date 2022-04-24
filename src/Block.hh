#pragma once
#include <vector>
#include <json_struct/json_struct.h>

struct Block
{
    std::vector<uint8_t> hash;
    std::vector<uint8_t> parentHash;
    std::vector<std::vector<uint8_t>> transactions;
    JS_OBJ(hash, parentHash, transactions);
};