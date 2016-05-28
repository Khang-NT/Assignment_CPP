//
// Created by root on 28/05/2016.
//

#ifndef ASSIGNMENT_ACCOUNTMANAGER_HPP
#define ASSIGNMENT_ACCOUNTMANAGER_HPP


#include <vector>
#include "model/Account.hpp"

class AccountManager {
public:
    /**
     * Get singlestone instance.
     * @throw (const char*) if AccountManager::loadFromDisk() error.
     * @return Singlestone instance of AccountManager
     */
    static AccountManager *getInstance() throw(const char*);

    /**
     * Load account list from Accounts.txt file.
     * @throw (const char*) Throw exception message if file Accounts.txt doesn't exist
     * or hash sum mismatch or file struct invalid.
     */
    void loadFromDisk() throw(const char*);

    /**
     * Save account list to Accounts.txt when having new changes.
     * @throw (const char*) Throw exception message if have trouble with output file Accounts.txt
     */
    void saveToDisk() throw(const char*);

    /**
     * Add new account, password will be replaced with hash code. New account list will be save to disk.
     * @param userName User name
     * @param password Raw password
     * @param type Account type
     * @throw (const char*) if AccountManager::saveToDisk() error.
     * @see AccountManager::saveToDisk, Account::TYPE_ADMIN, Account::TYPE_MANAGER, Account::TYPE_CUSTOMER;
     */
    void addAccount(string userName, string password, int type) throw(const char*);

    /**
     * Remove account which has id matches with accountId.
     * @param accountId Id of account to be removed.
     * @throw (const char*) if AccountManager::saveToDisk() error.
     */
    void removeAccount(Integer accountId) throw(const char*);

    /**
     * Check if user name exists.
     * @param userName User name
     * @return True if user name exists, ortherwise return false;
     */
    bool existUserName(string userName);

    /**
     * Check if given user name and password match with an account
     * @param userName user name
     * @param password password
     * @return (Account&) an account if exist.
     */
    Account *existAccount(string userName, string password);

    /**
     * Set logged in account.
     * @param account pointer to account logged in.
     */
    void setCurrentAccount(Account *account) {
        this->currentAccount = account;
    }

    /**
     * Get logged in account.
     * @return pointer to account logged in.
     */
    Account *getCurrentAccount() {
        return currentAccount;
    }

    ~AccountManager() {
        delete (instance);
    }

    static const char *FILE_NAME;
private:
    static AccountManager *instance;
    vector<Account *> accounts;
    Integer primaryIdAutoInc = 1;
    Account *currentAccount = 0;
};


#endif //ASSIGNMENT_ACCOUNTMANAGER_HPP
