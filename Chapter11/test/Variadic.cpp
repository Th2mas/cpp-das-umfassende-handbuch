//
// Created by tkhle on 19.07.2023.
//
#include "gtest/gtest.h"
#include "../include/Variadic.h"

TEST(Variadic, PrintValus) {
    // Arrange
    std::stringstream output;
    std::streambuf *originalCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());  // Redirect cout to a stringstream

    // Act
    printValues(1, "two", 3.14, "four", 5);

    // Restore cout
    std::cout.rdbuf(originalCoutBuffer);

    // Assert
    EXPECT_EQ(output.str(), "1 two 3.14 four 5 \n");
}

TEST(Variadic, Sum) {
    auto result = sum(1.5, 2, 3, 5.6, 5, 6);
    EXPECT_DOUBLE_EQ(result, 23.1);
}

TEST(Variadic, SizeOf) {
    // Arrange
    int expected = 5;

    // Act
    int actual = countArgs(1, 2, 3, 4, 5);

    // Assert
    EXPECT_EQ(expected, actual);
}

TEST(Variadic, ToTuple) {
    auto tuple = toTuple(1, 2, 3, 4, 5);

    EXPECT_EQ(std::get<0>(tuple), 1);
    EXPECT_EQ(std::get<1>(tuple), 2);
    EXPECT_EQ(std::get<2>(tuple), 3);
    EXPECT_EQ(std::get<3>(tuple), 4);
    EXPECT_EQ(std::get<4>(tuple), 5);
}
