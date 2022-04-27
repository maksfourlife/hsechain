#include <iostream>
#include <string>
#include <leveldb/db.h>
#include <json_struct/json_struct.h>

#include "Account.hh"

int main()
{
    auto acc1 = Account{
        .balance = 0x010203,
        .nonce = 1,
        .data = {1, 2, 3}};
    std::cout << JS::serializeStruct(acc1) << std::endl;
    auto raw = acc1.ser();
    for (auto &x : raw)
    {
        printf("%02x ", x);
    }
    printf("\n");
    auto acc2 = Account::de(raw);
    std::cout << JS::serializeStruct(acc2) << std::endl;
}
