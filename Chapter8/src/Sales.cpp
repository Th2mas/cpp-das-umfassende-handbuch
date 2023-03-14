//
// Created by tkhle on 12.03.2023.
//
#include "../include/Sales.h"

Sales Sales::operator+(const Sales &op2) const {
    // Copy the current object to tmp
    Sales tmp(*this);
    tmp.paperback += op2.paperback;
    tmp.ebook += op2.ebook;
    return tmp;
}

Sales Sales::operator + (unsigned int val) const {
    Sales tmp(*this);
    tmp.paperback += val;
    return tmp;
}

// Friend function, doesn't have a scope!
Sales operator+(unsigned int val, const Sales& op2) {
    Sales tmp(op2);
    return tmp + val;
}

// We can implement this unary operator with the scope operator like this
/*
bool Sales::operator!() {
    return paperback == 0 && ebook == 0;
}
 */
// If we use it as a friend function, we simply omit the scope and add the reference as the parameter
bool operator!(const Sales& op) {
    return op.paperback == 0 && op.ebook == 0;
}

Sales& Sales::operator++() {
    paperback++;
    ebook++;
    return *this;
}

Sales& Sales::operator--() {
    if (paperback > 0 && ebook > 0) {
        paperback--;
        ebook--;
    }
    return *this;
}

// According to the book, it is better to implement it the following way (which is incorrect and makes the tests fail)
/*
Sales Sales::operator++(int) {
    Sales tmp(*this);
    tmp.paperback++;
    tmp.ebook++;
    return tmp;
}

Sales Sales::operator--(int) {
    Sales tmp(*this);
    if (tmp.paperback > 0 && tmp.ebook > 0) {
        tmp.paperback--;
        tmp.ebook--;
    }
    return tmp;
}
*/

// We are implementing the postfix unary operator similarly like we did before
Sales& Sales::operator++(int) {
    return operator++();
}

Sales& Sales::operator--(int) {
    return operator--();
}

unsigned int Sales::getPaperback() const {
    return paperback;
}

unsigned int Sales::getEbook() const {
    return ebook;
}
