//
// Created by tkhle on 11.03.2023.
//

#ifndef CHAPTER7_SIMPLECLASS_H
#define CHAPTER7_SIMPLECLASS_H

class SimpleClass {
    unsigned int val{0};
public:
    SimpleClass(unsigned int v): val(v) {}
    // Create an explicit stand version of the constructor
    SimpleClass() = default;

    void setVal(unsigned int val) {
        this->val = val;
    }

    // Forbids to call setVal with anything but an unsigned int
    template <typename T>
    void setVal(T val) = delete;
};

#endif //CHAPTER7_SIMPLECLASS_H
