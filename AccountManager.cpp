//
// Created by root on 28/05/2016.
//

#include "AccountManager.hpp"

AccountManager *AccountManager::instance = 0;

AccountManager &AccountManager::getInstance() throw(const char*) {
    if (!AccountManager::instance) {
        instance = new AccountManager();
        instance->loadFromDisk();
    }
    return *instance;
}

void AccountManager::loadFromDisk() throw(const char*) {

}

void AccountManager::saveToDisk() throw(const char*) {

}
