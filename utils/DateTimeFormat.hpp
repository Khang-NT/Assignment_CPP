//
// Created by root on 28/05/2016.
//

#ifndef ASSIGNMENT_DATETIMEFORMAT_HPP
#define ASSIGNMENT_DATETIMEFORMAT_HPP


#include <string>
#include "Integer.hpp"
#include <ctime>

using namespace std;

class DateTimeFormat {
public:
    static string format(Integer time, string formatToken);

    static const char *GUIDE;
};

string addZero(string time);

void replaceString(std::string subject, const std::string &search,
                   const std::string &replace);



#endif //ASSIGNMENT_DATETIMEFORMAT_HPP
