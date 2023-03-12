//
// Created by tkhle on 12.03.2023.
//

#ifndef CHAPTER8_SALES_H
#define CHAPTER8_SALES_H

class Sales {
    unsigned int paperback;
    unsigned int ebook;
public:
    Sales(unsigned int p = 0, unsigned int e = 0): paperback(p), ebook(e) {}
    Sales operator+(const Sales& op2) const;
    Sales operator+(unsigned int val) const;
};

#endif //CHAPTER8_SALES_H
