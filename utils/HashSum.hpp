//
// Created by root on 28/05/2016.
//

#ifndef ASSIGNMENT_HASHSUM_HPP
#define ASSIGNMENT_HASHSUM_HPP


#include <string>
#include "Integer.hpp"

using namespace std;

//Prime numbers
#define A 76963
#define B 86969

class HashSum : public Integer {
public:
    HashSum() : HashSum(0l) {};
    class Builder {
    public:
        Builder() : code(51) {};

        Builder &add(string s) {
            for (int i = 0; i < s.length(); i++)
                code = (code * A) ^ (s[i] * B);
            return *this;
        };

        HashSum *build() {
            return new HashSum(code);
        }

    private:
        long code;
    };

private:
    HashSum(long code) : Integer(code) {};
};


#endif //ASSIGNMENT_HASHSUM_HPP
