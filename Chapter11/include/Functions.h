//
// Created by tkhle on 16.07.2023.
//

#ifndef CHAPTER11_FUNCTIONS_H
#define CHAPTER11_FUNCTIONS_H

// Interestingly, one can not separate the declaration from the definition -> one gets linker errors, if the definition
// is in its own source file
template <typename T>
T minVal(T v1, T v2) {
    return v1 < v2 ? v1 : v2;
}

// Specialized function template (a slightly different implementation for a specific case / type)
template <>
std::string minVal(std::string v1, std::string v2) {
    return v1.size() < v2.size() ? v1 : v2;
}

template <typename T>
void mySwap(T& v1, T& v2) {
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

template <typename T, typename U>
bool isSameType(T t, U u) {
    return typeid(t).name() == typeid(u).name();
}

template <typename T>
double add(T t, double d) {
    return t + d;
}

#endif //CHAPTER11_FUNCTIONS_H
