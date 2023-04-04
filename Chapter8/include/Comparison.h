//
// Created by tkhle on 01.04.2023.
//

#ifndef CHAPTER8_COMPARISON_H
#define CHAPTER8_COMPARISON_H

#include <istream>

class Comparison {
    unsigned int val;
public:
    explicit Comparison(unsigned int value) : val(value) {}

    friend bool operator<(const Comparison &c1, const Comparison &c2);

    bool operator==(const Comparison &c) const;

    bool operator>(const Comparison &c) const;

    bool operator>=(const Comparison &c) const;

    bool operator<=(const Comparison &c) const;

    bool operator !=(const Comparison &c) const;

    friend std::istream& operator>>(std::istream& lop, Comparison& rop);
    friend std::ostream& operator<<(std::ostream& lop, const Comparison& rop);

    operator bool() const;

    // Objects, that are overloaded with the function operator, are called function objects or "functors"
    unsigned int operator()(unsigned int val2);
};

#endif //CHAPTER8_COMPARISON_H
