//
// Created by hosein on 12/24/23.
//

#include <array>
#include "base4.h"

void Base4::setRepresentation(int val) {
    representation.resize(number_of_digit);
    for (int i = 0; i < number_of_digit; ++i) {
        representation[number_of_digit - i - 1] = val % 4;
        val = val / 4;
    }
}

bool Base4::operator<(const Base4 &rhs) const {
    return value < rhs.value;
}

bool Base4::operator>(const Base4 &rhs) const {
    return rhs < *this;
}

bool Base4::operator<=(const Base4 &rhs) const {
    return !(rhs < *this);
}

bool Base4::operator>=(const Base4 &rhs) const {
    return !(*this < rhs);
}

bool Base4::operator==(const Base4 &rhs) const {
    return value == rhs.value;
}

bool Base4::operator!=(const Base4 &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Base4 &base4) {
    for (auto digit: base4.representation) {
        os << std::to_string(digit);
    }
    return os;
}

Base4 Base4::operator+(const Base4 &num) const {
    return {value + num.value, std::max(number_of_digit, num.number_of_digit)};
}

Base4::Base4(const int value, const int number_of_digit) : value(value), number_of_digit(number_of_digit) {
    setRepresentation(value);
}

Base4 Base4::operator+(const int num) const {
    return {value + num, number_of_digit};
}
