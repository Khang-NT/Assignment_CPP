//
// Created by root on 28/05/2016.
//

#include "LoginScreen.hpp"
#include "../utils/MenuHelper.hpp"
#include "../utils/Utils.hpp"
#include "../model/Account.hpp"
#include "../AccountManager.hpp"

namespace LoginScreen {
    void doSignIn() {
        while (true) {
            string userName, password;
            printf("User name: ");
            Utils::getLine(std::cin, userName);
            printf("Password: ");
            Utils::getLine(std::cin, password);
            Account *account = AccountManager::getInstance()->existAccount(userName, password);
            if (account) {
                switch (account->getType()) {
                    case Account::TYPE_ADMIN:

                        break;
                }
                return;
            }
            printf("User name or password is wrong.\n");
        }
    }

    void doSignUpCustomer() {
        Utils::doSignUp(Account::TYPE_CUSTOMER);
    }

    void start() {
        MenuHelper *loginMenu = (new MenuHelper("LOGIN", MenuHelper::QUIT_CAPTION))
                ->addItem("Sign in", doSignIn)
                ->addItem("Sign up", doSignUpCustomer);
        loginMenu->run(true);
    }
}