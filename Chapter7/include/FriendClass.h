//
// Created by tkhle on 12.03.2023.
//

#ifndef CHAPTER7_FRIENDCLASS_H
#define CHAPTER7_FRIENDCLASS_H

class B;

class A {
    int value;
public:
    A(int val): value(val) {}
    int getValue() const {
        return value;
    }

    friend class B;
};

class B {
public:
    void changeA(A& a) {
        a.value++;
    }
};

#endif //CHAPTER7_FRIENDCLASS_H
