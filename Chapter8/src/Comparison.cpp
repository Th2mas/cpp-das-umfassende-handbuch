//
// Created by tkhle on 01.04.2023.
//
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
