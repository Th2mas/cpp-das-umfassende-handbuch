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

TEST(PairTest, GlobalFunctionTemplate) {
    // Arrange
    int i1 = 1;
    int i2 = -1;
    int i3 = 2;

    Pair<int> p1{i1, i2};
    Pair<int> p2{i1, i2};
    Pair<int> p3{i1, i3};

    // Act
    auto resultComparison12 = comparePairs(p1, p2);
    auto resultComparison23 = comparePairs(p2, p3);

    // Assert
    EXPECT_TRUE(resultComparison12);
    EXPECT_FALSE(resultComparison23);
}

TEST(PairTest, Compare) {
    // Arrange
    int i1 = 1;
    int i2 = -1;
    int i3 = 2;

    Pair<int> p1{i1, i2};
    Pair<int> p2{i1, i2};
    Pair<int> p3{i1, i3};

    // Act
    auto resultComparison12 = p1 == p2;
    auto resultComparison23 = p2 == p3;

    // Assert
    EXPECT_TRUE(resultComparison12);
    EXPECT_FALSE(resultComparison23);
}
