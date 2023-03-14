//
// Created by tkhle on 12.03.2023.
//

#ifndef CHAPTER8_SALES_H
#define CHAPTER8_SALES_H

// When overloading operators, we can only use C++ operators and are not allowed to come up with random operators
// The priority of operators stays the same
// We can only overload operators in the context with classes (at least one argument must be an instance of a class)
// -> we are not allowed to overwrite the operator functionality of base type (e.g. change the addition of two ints)
// Some operators can only be written as methods, not as friend functions
// Some operators can not be overloaded at all (e.g. :: or sizeof)
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

    // We must not use a parameter, if the unary operator should be part of the class
    // We either declare it as a friend function and pass the object reference as a parameter,
    // or use it without any parameter and make it part of the class
    friend bool operator!(const Sales& op);
    // bool operator!();

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
