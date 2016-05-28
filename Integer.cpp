//
// Created by root on 28/05/2016.
//

#include "Integer.hpp"

ostream &operator<<(ostream &output, const Integer &i) {
    output << i;
    return output;
}

istream &operator>>(istream &input, const Integer &i) {
    input >> i;
    return input;
}