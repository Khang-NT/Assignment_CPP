//
// Created by root on 28/05/2016.
//

#include "Integer.hpp"

ostream &operator<<(ostream &output, const Integer &i) {
    output << i.value;
    return output;
}

istream &operator>>(istream &input, Integer &i) {
    long value;
    input >> value;
    i = value;
    return input;
}

bool operator==(const Integer &lhs, const Integer &rhs) {
    return lhs.value == rhs.value;
}