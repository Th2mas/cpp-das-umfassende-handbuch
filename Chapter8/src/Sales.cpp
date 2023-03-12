//
// Created by tkhle on 12.03.2023.
//
#include "../include/Sales.h"

Sales Sales::operator+(const Sales& op2) const {
    // Copy the current object to tmp
    Sales tmp(*this);
    tmp.paperback += op2.paperback;
    tmp.ebook += op2.ebook;
    return tmp;
}

Sales Sales::operator+(unsigned int val) const {
    Sales tmp(*this);
    tmp.paperback += val;
    return tmp;
}
