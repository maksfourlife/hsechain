#include "Block.hh"

std::vector<uint8_t> Block::ser()
{
    std::vector<uint8_t> rb;
    rb.insert(rb.end(), this->hash.begin(), this->hash.end());
    rb.insert(rb.end(), this->parentHash.begin(), this->parentHash.end());
    for (auto h : this->transactions)
    {
        rb.insert(rb.end(), h.begin(), h.end());
    }
    return rb;
}

Block Block::de(const std::vector<uint8_t> &rb)
{
    std::vector<uint8_t> hash, parentHash;
    std::vector<std::vector<uint8_t>> hashes;

    auto it = rb.begin();
    hash.assign(it, it += HASH_SIZE);
    parentHash.assign(it, it += HASH_SIZE);

    while (it != rb.end())
    {
        std::vector<uint8_t> t;
        t.assign(it, it += HASH_SIZE);
        hashes.push_back(t);
    }

    return Block{hash, parentHash, transactions};
}