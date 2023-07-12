//
// Created by tkhle on 03.06.2023.
//
#include <gtest/gtest.h>
#include <stdexcept>
#include <bitset>
#include "../src/DivisionByZeroError.h"

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

TEST(ExceptionHandling, WithCustomErrorClass) {
    // Arrange
    auto division = [](int x, int y) {
        if (y == 0) {
            throw DivisionByZeroError(DivisionByZeroError::Err::DIV0);
        }
        return static_cast<double>(x) / y;
    };

    // Act and assert
    try {
        auto ignored = division(1, 0);
    } catch (DivisionByZeroError& e) {
        ASSERT_EQ(e.what(), "Division by zero");
    }
}

TEST(ExceptionHandling, DomainError) {
    // Arrange
    auto safe_sqrt = [](double value) {
        if (value < 0.0) {
            throw std::domain_error("Negative value is not allowed");
        }
        return std::sqrt(value);
    };

    // Act and assert
    try {
        auto ignored = safe_sqrt(-1);
    } catch (std::domain_error& e) {
        ASSERT_STREQ(e.what(), "Negative value is not allowed");
    }
}

TEST(ExceptionHandling, LengthError) {
    try {
        std::string text;
        text.resize(text.max_size() + 1);
    } catch (std::length_error& e) {
        ASSERT_STREQ(e.what(), "string too long");
    }
}

TEST(ExceptionHandling, InvalidArgument) {
    try {
        std::bitset<8> bitset(std::string("01011X10"));
    } catch (std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "invalid bitset char");
    }
}

TEST(ExceptionHandling, OutOfRange) {
    try {
        std::string text("A simple text");
        text.at(50) = 'X';
    } catch (std::out_of_range& e) {
        ASSERT_STREQ(e.what(), "invalid string position");
    }
}

TEST(ExceptionHandling, OverflowError) {
    try {
        std::bitset<80> bitset;
        bitset[0] = 1;
        bitset[79] = 1;
        unsigned long value = bitset.to_ulong();
    } catch (std::overflow_error& e) {
        ASSERT_STREQ(e.what(), "bitset overflow");
    }
}
