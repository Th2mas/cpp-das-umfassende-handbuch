//
// Created by tkhle on 01.04.2023.
//
#include "../include/Comparison.h"
#include "gtest/gtest.h"

class ComparisonLessThanFixture : public testing::TestWithParam<std::tuple<int, int, bool>> {
};

TEST_P(ComparisonLessThanFixture, LessThan) {
    // Arrange
    auto param = GetParam();
    auto val1 = std::get<0>(param);
    auto val2 = std::get<1>(param);
    auto expected = std::get<2>(param);

    Comparison c1{val1};
    Comparison c2{val2};

    // Act
    bool actual = c1 < c2;

    // Assert
    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(LessThanTests, ComparisonLessThanFixture, ::testing::Values(
        std::make_tuple(1, 2, true),
        std::make_tuple(2, 2, false),
        std::make_tuple(3, 2, false)
));

class ComparisonEqualsFixture : public testing::TestWithParam<std::tuple<int, int, bool>> {
};

TEST_P(ComparisonEqualsFixture, Equals) {
    // Arrange
    auto param = GetParam();
    auto val1 = std::get<0>(param);
    auto val2 = std::get<1>(param);
    auto expected = std::get<2>(param);

    Comparison c1{val1};
    Comparison c2{val2};

    // Act
    bool actual = c1 == c2;

    // Assert
    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(EqualsTests, ComparisonEqualsFixture, ::testing::Values(
        std::make_tuple(1, 2, false),
        std::make_tuple(2, 2, true),
        std::make_tuple(3, 2, false)
));

class ComparisonGreaterThanFixture : public testing::TestWithParam<std::tuple<int, int, bool>> {
};

TEST_P(ComparisonGreaterThanFixture, GreaterThan) {
    // Arrange
    auto param = GetParam();
    auto val1 = std::get<0>(param);
    auto val2 = std::get<1>(param);
    auto expected = std::get<2>(param);

    Comparison c1{val1};
    Comparison c2{val2};

    // Act
    bool actual = c1 > c2;

    // Assert
    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(GreaterThanTests, ComparisonGreaterThanFixture, ::testing::Values(
        std::make_tuple(1, 2, false),
        std::make_tuple(2, 2, false),
        std::make_tuple(3, 2, true)
));
