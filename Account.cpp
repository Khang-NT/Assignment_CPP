//
// Created by root on 28/05/2016.
//

#include "HashSum.hpp"
#include "Account.hpp"
#include "Utils.hpp"

void Account::serialize(ostream &stream, HashSum::Builder &builder) {
    stream << getId() << endl;
    builder.add(id);
    stream << getUserName() << endl;
    builder.add(getUserName());
    stream << getPasswordHash() << endl;
    builder.add(passwordHash);
    stream << getTimeCreated() << endl;
    builder.add(timeCreated);
    stream << getType() << endl;
    builder.add(type);
}

Account *Account::deserialize(istream &stream, HashSum::Builder &builder) throw(const char*) {
    Integer id;
    string userName;
    HashSum passwordHash;
    Integer timeCreated;
    Integer type;
    stream >> id;
    if (stream.fail())
        throw "Invalid struct";
    builder.add(id);
    Utils::getLine(stream, userName);
    builder.add(userName);
    stream >> passwordHash;
    if (stream.fail())
        throw "Invalid struct";
    builder.add(passwordHash);
    stream >> timeCreated;
    if (stream.fail())
        throw "Invalid struct";
    builder.add(timeCreated);
    stream >> type;
    if (stream.fail())
        throw "Invalid struct";
    builder.add(type);
    Account *account = new Account(userName, passwordHash, timeCreated, type);;
    account->setId(id);
    return account;
}



