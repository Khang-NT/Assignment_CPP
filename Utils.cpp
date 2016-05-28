//
// Created by root on 28/05/2016.
//

#include "Utils.hpp"

namespace Utils {
    void getLine(std::istream &stream, std::string &s) {
        do {
            std::getline(stream, s);
        } while (s.compare("") == 0);
    }

    bool yesNo() {
        char c = ' ';
        while (c != 'Y' && c != 'y' && c != 'N' && c != 'n') {
            std::cin >> c;
        }
        return (c == 'y' || c == 'Y');
    }

    void clearScreen() {
#ifdef WINDOWS
        system("cls");
#else
        system("clear");
#endif
    }
}