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
    Integer() : Integer(0l) {};

    Integer(long value) : value(value) {};

    operator long() {
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

    void operator=(long const &value) {
        this->value = value;
    }

    bool operator==(Integer a) {
        return a.value == this->value;
    }

    Integer &operator++() {
        value++;
        return *this;
    }

    Integer operator++(int) {
        Integer tmp(*this);
        value++;
        return tmp;
    }

    long value;
};

ostream &operator<<(ostream &output, const Integer &i);

istream &operator>>(istream &input, Integer &i);




#endif //ASSIGNMENT_INTEGER_HPP
