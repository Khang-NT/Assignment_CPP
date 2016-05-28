//
// Created by root on 28/05/2016.
//

#ifndef ASSIGNMENT_ACCOUNT_HPP
#define ASSIGNMENT_ACCOUNT_HPP

#include <string>
#include "HashSum.hpp"
#include "DateTimeFormat.hpp"
#include "Configs.hpp"

using namespace std;

class Account {
public:
    Account(const string &userName, const HashSum &passwordHash, const Integer &timeCreated, const Integer &type)
            : userName(userName), passwordHash(passwordHash), timeCreated(timeCreated), type(type) {}

    void setId(const Integer &id) {
        Account::id = id;
    }

    void changePassword(string newPassword) {
        this->passwordHash = *HashSum::Builder().add(newPassword).build();
    }

    const Integer &getId() const {
        return id;
    }

    const string &getUserName() const {
        return userName;
    }

    const HashSum &getPasswordHash() const {
        return passwordHash;
    }

    const Integer &getTimeCreated() const {
        return timeCreated;
    }

    const string getTimeCreatedStr() const {
        return DateTimeFormat::format(timeCreated, Configs::dateTimeFormat);
    }

    const Integer &getType() const {
        return type;
    }

    const string getTypeStr() const {
        switch (type) {
            case TYPE_ADMIN:
                return "ADMIN";
            case TYPE_MANAGER:
                return "MANAGER";
            case TYPE_CUSTOMER:
                return "CUSTOMER";
            default:
                return "UNKNOWN";
        }
    }


    static const int TYPE_ADMIN = 1;
    static const int TYPE_MANAGER = 2;
    static const int TYPE_CUSTOMER = 3;
private:
    Integer id;
    string userName;
    HashSum passwordHash;
    Integer timeCreated;
    Integer type;
};


#endif //ASSIGNMENT_ACCOUNT_HPP
