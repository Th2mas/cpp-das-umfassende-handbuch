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
    Sales operator + (unsigned int val) const;

    // We need a free (friend) function to override binary operators (e.g. plus with an integer on the left side of the addition)
    // The functions then don't belong to the class; we need to use both operands as parameters
    friend Sales operator+(unsigned int val, const Sales& op2);

    // Unary operators work with prefix notation (e.g. --obj or ++obj)
    // Unary operators should return a reference to the original object
    Sales& operator++();
    Sales& operator--();

    // Special notation for unary operators with postfix notation (e.g. obj++ or obj--): we need an extra dummy parameter
    // According to the book we should return a copy of the object we are calling the unary operator on (but this doesn't work as expected)
    // Sales operator++(int);
    // Sales operator--(int);

    // Instead, we are implementing it the same way we did in the prefix notation, just with the dummy operator
    Sales& operator++(int);
    Sales& operator--(int);

    unsigned int getPaperback() const;

    unsigned int getEbook() const;
};

#endif //CHAPTER8_SALES_H
