//
// Created by tkhle on 14.03.2023.
//
#include <gtest/gtest.h>
#include "../include/Dynamic.h"

TEST(Dynamic, Test) {
    Dynamic d01;
    {
        Dynamic d02(5);
        d01 = d02;  // Assignment and not copy!
    }

    EXPECT_EQ(d01.getCPtr(), 5);
}
