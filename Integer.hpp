//
// Created by root on 28/05/2016.
//

#ifndef ASSIGNMENT_INTEGER_HPP
#define ASSIGNMENT_INTEGER_HPP


#include <iostream>
#include <string>

using namespace std;

class Integer {
public:
    Integer() : Integer(0) {};

    Integer(int value) : value(value) {};

    operator int() {
        return value;
    }

    /**
     * Autoboxing - cast to string
     * @return value in string.
     */
    operator string() {
        return to_string(value);
    }

    operator const char *() {
        return (operator string()).c_str();
    }

    void operator=(int const &value) {
        this->value = value;
    }

    bool operator==(Integer a) {
        return a.value == this->value;
    }

    iostream &operator>>(iostream &input) {
        cin >> this->value;
        return input;
    }

protected:
    int value;
};


#endif //ASSIGNMENT_INTEGER_HPP
