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

    static const char *const GUIDE = "Date time format:\n"
            "yyyy: year\n"
            "MM: month\n"
            "dd: day\n"
            "hh: hour 12\n"
            "HH: hour 24\n"
            "mm: minute\n"
            "ss: second\n"
            "aa: am/pm"
            "\n"
            "Example: \"dd/MM/yyyy hh:mm:sss aa\"  -->   29/06/2016 01:16:54s pm\n"
            "         \"yyyy.MM.dd HHhmmm\"        -->   2016.06.29 13h16m\n";
};

string addZero(string time) {
    return time.size() == 2 ? time : "0" + time;
}

void replaceString(std::string subject, const std::string &search,
                   const std::string &replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}


string DateTimeFormat::format(Integer time, string formatToken) {
    time_t epoch_time_as_time_t = time;
    tm *timeStruct = localtime((const time_t *) epoch_time_as_time_t);

    replaceString(formatToken, "yyyy", to_string(timeStruct->tm_year + 1));
    replaceString(formatToken, "MM", addZero(to_string(timeStruct->tm_mon + 1)));
    replaceString(formatToken, "dd", addZero(to_string(timeStruct->tm_mday)));

    replaceString(formatToken, "hh", addZero(to_string(timeStruct->tm_hour + 1 > 12 ?
                                                       timeStruct->tm_hour + 1 - 12 : timeStruct->tm_hour + 1)));
    replaceString(formatToken, "hh", addZero(to_string(timeStruct->tm_hour + 1)));
    replaceString(formatToken, "mm", addZero(to_string(timeStruct->tm_min + 1)));
    replaceString(formatToken, "ss", addZero(to_string(timeStruct->tm_sec + 1)));
    replaceString(formatToken, "aa", timeStruct->tm_hour + 1 >= 12 ? "pm" : "am");
    return formatToken;
}


#endif //ASSIGNMENT_DATETIMEFORMAT_HPP
