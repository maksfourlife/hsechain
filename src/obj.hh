#pragma once
#include <vector>
#include <unordered_set>

class Transaction
{
private:
    uint8_t const *_from;
    uint8_t const *_to;
    uint64_t _amount;
    uint64_t _gas;
    uint64_t _gas_price;
    std::vector<uint8_t> _data;
    uint8_t const *_signature;

public:
    Transaction(uint8_t const *_from, uint8_t const *_to, uint64_t amount, uint64_t gas, uint64_t gas_price, std::vector<uint8_t> data);
    std::vector<uint8_t> serialize();
    static Transaction *deserialize(std::vector<uint8_t> *buf);
    uint8_t const *from();
    uint8_t const *to();
    uint64_t amount();
    std::vector<uint8_t> const *data();
    uint64_t gas();
    uint64_t gasPrice();
    uint8_t const *signature();
};
