#include <iostream>
#include "obj.hpp"

int main()
{
    Transaction tx(
        new uint8_t[20],
        new uint8_t[20],
        42352345,
        5,
        2000000,
        std::vector<uint8_t>(10));
    auto raw = tx.serialize();
    for (uint8_t x : raw)
    {
        std::printf("%02x", x);
    }
    std::cout << std::endl;
}
