//
// Created by tkhle on 16.07.2023.
//

#ifndef CHAPTER11_CONTAINER_H
#define CHAPTER11_CONTAINER_H

// T is called a formal datatype
// A non-type parameter would be the specification of a template with an actual datatype, e.g. template <typename T, int i>
template <typename T>
class Container {
    T data;
public:
    // One should use a const reference in order to avoid copying unnecessary data (except when working with threads)
    void setData(const T& data);
    T getData() const;
};

#endif //CHAPTER11_CONTAINER_H
