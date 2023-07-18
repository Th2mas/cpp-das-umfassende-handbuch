//
// Created by tkhle on 16.07.2023.
//
#include <string>
#include "../include/Container.h"

// when using a separate CPP file for the template class definitions, one needs to provide explicit conversions
// (it didn't compile without it)
template class Container<int>;

// if you provide specialized functions, you don't need the explicit conversions (but you need to specify all the functions)
// template class Container<std::string>;

template <typename T>
void Container<T>::setData(const T& data) {
    this->data = data;
}

template <typename T>
T Container<T>::getData() const {
    return data;
}

template <>
void Container<std::string>::setData(const std::string& data) {
    this->data = "New " + data;
}

// It would be nice, if this wasn't needed
template <>
std::string Container<std::string>::getData() const {
    return data;
}
