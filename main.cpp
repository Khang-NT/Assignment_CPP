#include <iostream>
#include "AccountManager.hpp"
#include "Utils.hpp"

using namespace std;

int main() {
    AccountManager *accountManager;
    try {
        accountManager = AccountManager::getInstance();
    } catch (const char *e) {
        printf("Read accounts from file error: %s\n", e);
        printf("Do you want to renew Accounts.txt (Y/N)? ");
        if (!Utils::yesNo())
            return 0;
        accountManager = AccountManager::getInstance();
        accountManager->addAccount("admin", "admin", Account::TYPE_ADMIN);
    }
    return 0;
}