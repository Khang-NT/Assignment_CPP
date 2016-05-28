//
// Created by root on 28/05/2016.
//

#ifndef ASSIGNMENT_UTILS_HPP
#define ASSIGNMENT_UTILS_HPP


#include <iosfwd>
#include <istream>
#include <iostream>

namespace Utils {
    void getLine(std::istream &stream, std::string &s);

    template<typename Base, typename T>
    inline bool instanceOf(const T *) {
        return std::is_base_of<Base, T>::value;
    }

    bool yesNo();

    void clearScreen();
}


#endif //ASSIGNMENT_UTILS_HPP
