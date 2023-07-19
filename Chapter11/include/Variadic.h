//
// Created by tkhle on 19.07.2023.
//

#ifndef CHAPTER11_VARIADIC_H
#define CHAPTER11_VARIADIC_H

#include <iostream>

void printValues() {
    std::cout << std::endl;
}

template <typename T, typename... Args>
void printValues(const T& value, const Args&... args) {
    std::cout << value << " ";
    printValues(args...);
}

// We need this base function to work with a single parameter (when ... is simply empty or has one element left)
// It's like a base case
template <typename T>
T sum(T a) {
    return a;
}

template <typename T, typename ... U>
double sum(const T& t, const U& ... args) {
    return t + sum(args ...);
}

#endif //CHAPTER11_VARIADIC_H
