//
// Created by root on 28/05/2016.
//

#include "HashSum.hpp"
#include "Account.hpp"
#include "Utils.hpp"

void Account::serialize(ostream &stream, HashSum::Builder &builder) {
    stream << getId();
    builder.add(id);
    stream << getUserName();
    builder.add(getUserName());
    stream << getPasswordHash();
    builder.add(passwordHash);
    stream << getTimeCreated();
    builder.add(timeCreated);
    stream << getType();
    builder.add(type);
}

void Account::deserialize(istream &stream, HashSum::Builder &builder) throw(const char*) {
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
}



