//
// Created by tkhle on 01.04.2023.
//
#include <iostream>
#include "../include/Comparison.h"

bool operator<(const Comparison &c1, const Comparison &c2) {
    return c1.val < c2.val;
}

bool Comparison::operator==(const Comparison &c) const {
    return c.val == val;
}

bool Comparison::operator!=(const Comparison &c) const {
    return !(*this == c);
}

bool Comparison::operator<=(const Comparison &c) const {
    return (*this) < c || (*this) == c;
}

bool Comparison::operator>(const Comparison &c) const {
    return !(*this <= c);
}

bool Comparison::operator>=(const Comparison &c) const {
    return !(*this < c);
}

std::istream& operator>>(std::istream& lop, Comparison& rop) {
    // std::cout << "val";
    lop >> rop.val;
    return lop;
}

std::ostream& operator<<(std::ostream& lop, const Comparison& rop) {
    lop << rop.val;
    return lop;
}

Comparison::operator bool() const {
    return val != 0;
}

unsigned int Comparison::operator()(unsigned int val2) {
    val += val2;
    return val;
}
