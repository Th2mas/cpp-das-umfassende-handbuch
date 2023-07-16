//
// Created by tkhle on 16.07.2023.
//
#include <gtest/gtest.h>
#include "../include/Functions.h"

TEST(TemplateTest, SimpleTemplate) {
    // Arrange
    int i1 = 1;
    int i2 = 3;

    double d1 = 1.1;
    double d2 = 1.0;

    // Act
    auto actualInt = minVal(i1, i2);
    auto actualDouble = minVal(d1, d2);

    // Assert
    EXPECT_EQ(actualInt, i1);
    EXPECT_EQ(actualDouble, d2);
}

TEST(TemplateTest, TemplateWithExplicitArgument) {
    // Arrange
    int i = 1;
    double d = 2;

    // Act
    auto actual = minVal<int>(i, d); // to use ints and doubles (or any type) mixed, we need to explicitly cast the type with the diamond operator

    // Assert
    EXPECT_EQ(actual, 1);
}

TEST(TemplateTest, SpecializedTemplate) {
    // Arrange
    std::string a = "aa";
    std::string b = "b";

    // Act
    auto actual = minVal(a, b);

    // Assert
    EXPECT_EQ(actual, b);
}

TEST(TemplateTest, TemplateParametersWithReferences) {
    // Arrange
    int i1 = 1;
    int i2 = 3;

    float f1 = 3.9f;
    float f2 = 4.2f;

    // Act
    mySwap(i1, i2);
    mySwap(f1, f2);

    // Assert
    EXPECT_EQ(i1, 3);
    EXPECT_EQ(i2, 1);
    EXPECT_EQ(f1, 4.2f);
    EXPECT_EQ(f2, 3.9f);
}

TEST(TemplateTest, MultipleTemplateParameters) {
    // Arrange
    int i1 = 0;
    int i2 = 1;
    double d1 = 0;

    // Act and assert
    EXPECT_TRUE(isSameType(i1, i2));
    EXPECT_FALSE(isSameType(i1, d1));
}

TEST(TemplateTest, TemplateFunctionWithSecondArgumentBeingConcrete) {
    // Arrange
    int i = 0;
    double expected = 3;

    // Act
    auto actual = add(i, 3);

    // Assert
    EXPECT_EQ(expected, actual);
}
