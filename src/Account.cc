#include "Account.hh"
#include <iostream>

std::vector<uint8_t> Account::ser()
{
    std::vector<uint8_t> ra;

    uint8_t *p = (uint8_t *)&this->balance;
    ra.insert(ra.end(), p, p + sizeof(uint64_t));

    p = (uint8_t *)&this->nonce;
    ra.insert(ra.end(), p, p + sizeof(uint64_t));

    ra.insert(ra.end(), this->data.begin(), this->data.end());

    return ra;
}

Account Account::de(const std::vector<uint8_t> &ra)
{
    uint64_t balance, nonce;
    std::vector<uint8_t> data;

    auto it = ra.begin();

    uint8_t *p = (uint8_t *)&balance;
    std::copy(it, it += sizeof(uint64_t), p);

    p = (uint8_t *)&nonce;
    std::copy(it, it += sizeof(uint64_t), p);

    data.insert(data.end(), it, ra.end());

    return Account{balance, nonce, data};
}
