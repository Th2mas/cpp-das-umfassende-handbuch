//
// Created by tkhle on 03.06.2023.
//
#include <gtest/gtest.h>
#include <stdexcept>

TEST(ExceptionHandling, DivisionByZeroWithStdException) {
    // Arrange
    int val1 = 1;
    int val2 = 0;

    // Act and assert
    try {
        if (val2 == 0) {
            throw std::runtime_error("Division by zero");
        }

        val1 / val2;
    } catch (std::exception& e) {
        // Make sure we get into this block
        ASSERT_STREQ(e.what(), "Division by zero");
    }
}

TEST(ExceptionHandling, DivisionByZeroWithThreeDotsCatch) {
    // Arrange
    int val1 = 1;
    int val2 = 0;

    // Act and assert
    try {
        if (val2 == 0) {
            throw std::string("Division by zero");
        }

        val1 / val2;
    } catch (...) {
        // Make sure we get into this block
        ASSERT_TRUE(true);
    }
}

TEST(ExceptionHandling, RedirectThrow) {
    // Arrange
    auto func = [](){
        try {
            throw -1;
        } catch (int i) {
            ASSERT_EQ(i, -1);
            throw;
        }
    };

    // Act and assert
    try {
        func();
    } catch (int i) {
        ASSERT_EQ(i, -1);
    }
}
