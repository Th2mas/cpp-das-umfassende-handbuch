//
// Created by tkhle on 18.07.2023.
//

#ifndef CHAPTER11_FIXEDARRAY_H
#define CHAPTER11_FIXEDARRAY_H

#include <stdexcept>

template <typename T = int, int n = 1>
class FixedArray {
    T data[n]{0};   // creates n elements
public:
    T& operator[](int index) {
        if (index >= n || index < 0) {
            throw std::out_of_range("FixedArray:IndexOutOfBounds");
        }
        return data[index];
    }

    // The attribute [[nodiscard]] indicates, that the return value should not be discarded/ignored
    // If the return value is not used, the compiler might warn you about the unused value
    [[nodiscard]] int size() const {
        return n;
    }
};

template <int n>
using IntFixedArray = FixedArray<int, n>;

#endif //CHAPTER11_FIXEDARRAY_H
