//
// Created by root on 28/05/2016.
//

#include "HashSum.hpp"
#include "Account.hpp"

void Account::serialize(ostream &stream, HashSum::Builder &builder) {
    stream << getId();
    builder.add(id);
    stream << getUserName();
    builder.add(getUserName());
    stream << getPasswordHash();
    builder.add(passwordHash);
    stream << getTimeCreated();
    builder.add(getTimeCreated());
    stream << getType();
    builder.add(getType());
}


