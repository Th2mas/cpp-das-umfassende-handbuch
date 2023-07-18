//
// Created by tkhle on 18.07.2023.
//
#include "gtest/gtest.h"
#include "../include/Pair.h"

TEST(PairTest, ConstructorAndGetter) {
    // Arrange
    int i1 = 1;
    int i2 = 3;
    std::string s = "Test";
    double d = 5.3;

    // Act
    Pair<int> pi{i1, i2};
    Pair<std::string, double> psd{s, d};

    // Assert
    EXPECT_EQ(i1, pi.first());
    EXPECT_EQ(i2, pi.second());
    EXPECT_EQ(s, psd.first());
    EXPECT_EQ(d, psd.second());
}
