//
// Created by tkhle on 18.07.2023.
//
#include "gtest/gtest.h"
#include "../include/FixedArray.h"

TEST(FixedArray, CorrectIndexUsageWithNonTypeDefinition) {
    // Arrange
    FixedArray<int, 5> fa;

    // Act and assert
    try {
        fa[4] = 4;
    } catch (std::out_of_range& e) {
        FAIL();
    }

    try {
        fa[-1] = -1;
        FAIL();
    } catch (std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "FixedArray:IndexOutOfBounds");
    }

    try {
        fa[5] = 5;
        FAIL();
    } catch (std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "FixedArray:IndexOutOfBounds");
    }
}

TEST(FixedArray, CorrectIndexUsageWithoutNonTypeDefinition) {
    // Arrange
    FixedArray<int> fa;

    // Act and assert
    try {
        fa[0] = 0;
    } catch (std::out_of_range& e) {
        FAIL();
    }

    try {
        fa[-1] = -1;
        FAIL();
    } catch (std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "FixedArray:IndexOutOfBounds");
    }

    try {
        fa[1] = 1;
        FAIL();
    } catch (std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "FixedArray:IndexOutOfBounds");
    }
}

TEST(FixedArray, Size) {
    // Arrange
    const int expected = 3;
    FixedArray<int, expected> fi;   // If you want to use a variable for the non-type, the variable must be const!

    // Act
    auto actual = fi.size();

    // Assert
    EXPECT_EQ(expected, actual);
}
