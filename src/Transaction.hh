#pragma once
#include <vector>
#include <json_struct/json_struct.h>

struct Transaction
{
    std::vector<uint8_t> from;
    std::vector<uint8_t> to;
    uint64_t amount;
    uint64_t gas;
    uint64_t gas_price;
    std::vector<uint8_t> data;
    std::vector<uint8_t> signature;
    JS_OBJ(from, to, amount, gas, gas_price, data, signature);
    std::vector<uint8_t> ser();
};
