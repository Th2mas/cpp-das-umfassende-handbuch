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
        FAIL();
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
        FAIL();
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
        FAIL();
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
        FAIL();
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
        FAIL();
    } catch (std::domain_error& e) {
        ASSERT_STREQ(e.what(), "Negative value is not allowed");
    }
}

TEST(ExceptionHandling, LengthError) {
    try {
        std::string text;
        text.resize(text.max_size() + 1);
        FAIL();
    } catch (std::length_error& e) {
        ASSERT_STREQ(e.what(), "string too long");
    }
}

TEST(ExceptionHandling, InvalidArgument) {
    try {
        std::bitset<8> bitset(std::string("01011X10"));
        FAIL();
    } catch (std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "invalid bitset char");
    }
}

TEST(ExceptionHandling, OutOfRange) {
    try {
        std::string text("A simple text");
        text.at(50) = 'X';
        FAIL();
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
        FAIL();
    } catch (std::overflow_error& e) {
        ASSERT_STREQ(e.what(), "bitset overflow");
    }
}

TEST(ExceptionHandling, SystemError) {
    try {
        std::thread().detach();
        FAIL();
    } catch (std::system_error& e) {
        ASSERT_STREQ(e.what(), "invalid argument: invalid argument");
        ASSERT_EQ(e.code().value(), 22);
        ASSERT_STREQ(e.code().category().name(), "generic");
        ASSERT_EQ(e.code().message(), "invalid argument");
    }
}

TEST(ExceptionHandling, BadAlloc) {
    int length = 1000000000;
    try {
        auto ignored = new int[length];
        FAIL();
    } catch (std::bad_alloc& e) {
        ASSERT_STREQ(e.what(), "bad allocation");
    }
}

TEST(ExceptionHandling, BadArrayNewLength) {
    int length = -1;
    try {
        auto ignored = new int[length];
        FAIL();
    } catch (std::bad_array_new_length& e) {
        ASSERT_STREQ(e.what(), "bad array new length");
    }
}

TEST(ExceptionHandling, BadCast) {
    class Window { virtual void draw() {} };
    class Button { virtual void draw() {} };

    Window w;
    try {
        auto ignored = dynamic_cast<Button&>(w);
        FAIL();
    } catch (std::bad_cast& e) {
        ASSERT_STREQ(e.what(), "Bad dynamic_cast!");
    }
}

TEST(ExceptionHandling, BadTypeId) {
    class Window { virtual void draw() {} };
    Window *wPtr = nullptr;
    try {
        auto ignored = typeid(*wPtr).name();
        FAIL();
    } catch (std::bad_typeid& e) {
        ASSERT_STREQ(e.what(), "Attempted a typeid of nullptr pointer!");
    }
}

TEST(ExceptionHandling, BadFunctionCall) {
    std::function<int(double, double)> func;
    try {
        func(1.0, 2);
        FAIL();
    } catch (std::bad_function_call& e) {
        ASSERT_STREQ(e.what(), "bad function call");
    }
}
