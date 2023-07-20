//
// Created by tkhle on 20.07.2023.
//
#include "gtest/gtest.h"
#include "../include/RawFind.h"
#include <algorithm>

TEST(RawFindTest, FindPointer) {
    // Arrange
    const int MAX = 10;

    int arr[MAX]{0};
    int findIndex = 5;
    arr[findIndex] = 1;

    auto begin = arr;
    auto end = arr + MAX;

    // Act
    auto resultSuccess = findPointer(begin, end, 1);
    auto resultFailure = findPointer(begin, end, 2);

    // Assert
    EXPECT_EQ(resultSuccess, arr + findIndex);
    EXPECT_EQ(resultFailure, arr + MAX);
}

TEST(RawFindTest, StdFind) {
    // Arrange
    const int MAX = 10;

    int arr[MAX]{0};
    int findIndex = 5;
    arr[findIndex] = 1;

    auto begin = arr;
    auto end = arr + MAX;

    // Act
    auto resultSuccess = std::find(begin, end, 1);
    auto resultFailure = std::find(begin, end, 2);

    // Assert
    EXPECT_EQ(resultSuccess, arr + findIndex);
    EXPECT_EQ(resultFailure, arr + MAX);
}

TEST(RawFindTest, FindIterator) {
    // Arrange
    const int MAX = 10;

    std::vector<int> vec(MAX);
    int findIndex = 5;
    int searchValue = 1;

    vec[findIndex] = searchValue;

    // Act
    auto result = findIterator(vec, searchValue);

    // Assert
    EXPECT_EQ(*result, searchValue);
}
