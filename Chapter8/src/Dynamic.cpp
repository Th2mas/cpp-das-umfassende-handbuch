//
// Created by tkhle on 14.03.2023.
//
#include <utility>
#include "../include/Dynamic.h"

Dynamic::Dynamic(int n) {
    cPtr = new int(n);
}

Dynamic::Dynamic(const Dynamic &org) {
    cPtr = new int(org.getCPtr());
}

Dynamic::~Dynamic() {
    delete[] cPtr;
}

Dynamic& Dynamic::operator=(const Dynamic &rhs) {
    if (this != &rhs) {
        Dynamic tmp(rhs);
        std::swap(cPtr, tmp.cPtr);
    }
    return *this;
}

int Dynamic::getCPtr() const {
    return *cPtr;
}
