//
// Created by tkhle on 19.07.2023.
//
#include "gtest/gtest.h"
#include "../include/Variadic.h"

TEST(Variadic, PrintValus) {
    // Arrange
    std::stringstream output;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf();
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
