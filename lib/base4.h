//
// Created by hosein on 12/24/23.
//

#ifndef PACMAN_CPP_BASE4_H
#define PACMAN_CPP_BASE4_H

#include <ostream>
#include "vector"

class Base4 {
public:
    int value;
    int number_of_digit;
    std::vector<int> representation;

    Base4(int value, int number_of_digit);

    void setRepresentation(int val);

    bool operator<(const Base4 &rhs) const;

    bool operator>(const Base4 &rhs) const;

    bool operator<=(const Base4 &rhs) const;

    bool operator>=(const Base4 &rhs) const;

    bool operator==(const Base4 &rhs) const;

    bool operator!=(const Base4 &rhs) const;

    Base4 operator+(const Base4 &num) const;

    Base4 operator+(int num) const;

    friend std::ostream &operator<<(std::ostream &os, const Base4 &base4);

};


#endif //PACMAN_CPP_BASE4_H
