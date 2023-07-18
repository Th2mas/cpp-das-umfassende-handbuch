//
// Created by tkhle on 16.07.2023.
//
#include "gtest/gtest.h"
#include "../include/Container.h"

TEST(Container, SetAndGet) {
    // Arrange
    int i = 1;
    Container<int> ci;

    std::string s = "Hello Container World";
    Container<std::string> cs;

    // Act
    ci.setData(i);
    cs.setData(s);

    auto actual1 = ci.getData();
    auto actual2 = cs.getData();

    // Expect
    EXPECT_EQ(actual1, i);
    EXPECT_EQ(actual2, "New " + s);
}
