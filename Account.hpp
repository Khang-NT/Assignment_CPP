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

    const Integer &getId() {
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

    const long getType() {
        return type;
    }

    const string getTypeStr() {
        switch ((int) this->type) {
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

    /**
     * Serialize to stream and update hash code builder.
     * @Order:
     * ID ->
     * User name ->
     * Password hash ->
     * Time created ->
     * Account type.
     * @param stream out put stream
     * @param builder hash code builder
     */
    void serialize(ostream &stream, HashSum::Builder &builder);

    /**
     * Deserialize from input stream and update hash code builder.
     * @Order:
     * ID ->
     * User name ->
     * Password hash ->
     * Time created ->
     * Account type.
     * @param stream input stream
     * @param builder hash code builder
     * @throw (const char*) throw exception if error when read stream.
     */
    static Account *deserialize(istream &stream, HashSum::Builder &builder) throw(const char*);

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
