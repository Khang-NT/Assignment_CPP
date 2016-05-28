//
// Created by root on 28/05/2016.
//

#include <fstream>
#include <ctime>
#include "AccountManager.hpp"

AccountManager *AccountManager::instance = 0;
const char *AccountManager::FILE_NAME = "Accounts.txt";

AccountManager *AccountManager::getInstance() throw(const char*) {
    if (!AccountManager::instance) {
        instance = new AccountManager();
        instance->loadFromDisk();
    }
    return instance;
}

void AccountManager::loadFromDisk() throw(const char*) {
    ifstream fileStream(FILE_NAME);
    if (fileStream.fail())
        throw "Can not open file Accounts.txt";
    HashSum::Builder builder;
    Integer numAccounts;
    fileStream >> numAccounts >> primaryIdAutoInc;
    builder.add(numAccounts);
    builder.add(primaryIdAutoInc);
    for (long i = 0; i < numAccounts; i++)
        try {
            accounts.push_back(Account::deserialize(fileStream, builder));
        } catch (const char *e) {
            accounts.clear();
            primaryIdAutoInc = 1;
            throw e;
        }
    Integer hashSumInFile;
    fileStream >> hashSumInFile;
    fileStream.close();
    if (!(*builder.build() == hashSumInFile)) {
        accounts.clear();
        primaryIdAutoInc = 1;
        throw "Hash sum mismatch";
    }

}

void AccountManager::saveToDisk() throw(const char*) {
    ofstream fileStream(FILE_NAME);
    HashSum::Builder builder;
    Integer numAccounts = (Integer) accounts.size();
    fileStream << numAccounts << " " << primaryIdAutoInc << endl;
    builder.add(numAccounts);
    builder.add(primaryIdAutoInc);
    for (Account *account : accounts)
        account->serialize(fileStream, builder);
    HashSum hashSum = *builder.build();
    fileStream << hashSum;
    fileStream.close();
}

void AccountManager::addAccount(string userName, string password, int type) throw(const char*) {
    Account *account = new Account(userName, *HashSum::Builder().add(password).build(),
                                   static_cast<long int>(time(0)), type);
    account->setId(primaryIdAutoInc++);
    accounts.push_back(account);
    saveToDisk();
}
