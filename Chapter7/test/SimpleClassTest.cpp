//
// Created by tkhle on 11.03.2023.
//
#include <gtest/gtest.h>
#include "../include/SimpleClass.h"

TEST(SimpleClass, UseDefaultConstructor) {
    // This should pass, because we have declared that the compiler should create the default constructor by using 'default'
    SimpleClass sc;
}

TEST(SimpleClass, ShowSetValCanOnlyBeCalledWithUnsignedInt) {
    SimpleClass sc;
    unsigned int i = 2;
    sc.setVal(i);
    // sc.setVal(-3);  // Call to deleted method
}
