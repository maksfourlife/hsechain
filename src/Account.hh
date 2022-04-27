#pragma once
#include <vector>
#include <json_struct/json_struct.h>

struct Account
{
    uint64_t balance;
    uint64_t nonce;
    std::vector<uint8_t> data;
    JS_OBJ(balance, nonce, data);
    std::vector<uint8_t> ser();
    static Account de(const std::vector<uint8_t> &rawAccount);
};
