//
// Created by tkhle on 01.04.2023.
//

#ifndef CHAPTER8_COMPARISON_H
#define CHAPTER8_COMPARISON_H

class Comparison {
    unsigned int val;
public:
    explicit Comparison(int value) : val(value) {}

    friend bool operator<(const Comparison &c1, const Comparison &c2);

    bool operator==(const Comparison &c) const;

    bool operator>(const Comparison &c) const;

    bool operator>=(const Comparison &c) const;

    bool operator<=(const Comparison &c) const;

    bool operator !=(const Comparison &c) const;
};

#endif //CHAPTER8_COMPARISON_H
