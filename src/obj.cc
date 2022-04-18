#include <memory>
#include "obj.hh"

Transaction::Transaction(uint8_t const *_from, uint8_t const *_to, uint64_t amount, uint64_t gas, uint64_t gas_price, std::vector<uint8_t> data)
{
    this->_from = _from;
    this->_to = _to;
    this->_amount = amount;
    this->_gas = gas;
    this->_gas_price = gas_price;
    this->_data = data;
}

std::vector<uint8_t> Transaction::serialize()
{
    std::vector<uint8_t> b;
    b.insert(b.end(), this->_from, this->_from + 20);
    b.insert(b.end(), this->_to, this->_to + 20);
    b.insert(b.end(), &this->_amount, &this->_amount + 8);
    b.insert(b.end(), &this->_gas, &this->_gas + 8);
    b.insert(b.end(), &this->_gas_price, &this->_gas_price + 8);
    b.insert(b.end(), this->_data.begin(), this->_data.end());
    return b;
}
