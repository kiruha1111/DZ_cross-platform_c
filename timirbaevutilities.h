#ifndef TIMIRBAEVUTILITIES_H
#define TIMIRBAEVUTILITIES_H

#pragma once
#include <iostream>
#include <string>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>


inline bool IntCheck(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (isdigit((unsigned char)input[i])) continue;
        else return false;
    }
    if (input.length() == 0) return false;
    return true;
}

inline int GetCorrectNumber(int min, int max) {
    std::string num;
    while ((std::getline(std::cin, num)).fail() || IntCheck(num) == false || stoi(num) < min || stoi(num) > max) {
        std::cout << "Введите номер от " << min << " до " << max << ": ";
    }
    return stoi(num);
}

#endif // TIMIRBAEVUTILITIES_H
