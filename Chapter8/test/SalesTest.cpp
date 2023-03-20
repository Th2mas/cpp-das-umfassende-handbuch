//
// Created by tkhle on 12.03.2023.
//
#include <gtest/gtest.h>
#include "../include/Sales.h"

TEST(Sales, PlusOperatorWithSalesWorks) {
    // Arrange
    Sales s1{15, 10};
    Sales s2{25, 15};
    Sales expected{s1.getPaperback() + s2.getPaperback(), s1.getEbook() + s2.getEbook()};

    // Act
    Sales actual = s1 + s2;

    // Assert
    EXPECT_EQ(expected.getPaperback(), actual.getPaperback());
    EXPECT_EQ(expected.getEbook(), actual.getEbook());
}

TEST(Sales, PlusOperatorWithSalesAndExplicitCallWorks) {
    // Arrange
    Sales s1{15, 10};
    Sales s2{25, 15};
    Sales expected{s1.getPaperback() + s2.getPaperback(), s1.getEbook() + s2.getEbook()};

    // Act
    Sales actual = s1.operator+(s2);

    // Assert
    EXPECT_EQ(expected.getPaperback(), actual.getPaperback());
    EXPECT_EQ(expected.getEbook(), actual.getEbook());
}

TEST(Sales, PlusOperatorWithValueAsSecondOperandWorks) {
    // Arrange
    Sales s{15, 10};
    unsigned int paperbackIncrease = 3;
    Sales expected{s.getPaperback() + paperbackIncrease, s.getEbook()};

    // Act
    auto actual = s + paperbackIncrease;

    // Assert
    EXPECT_EQ(expected.getPaperback(), actual.getPaperback());
    EXPECT_EQ(expected.getEbook(), actual.getEbook());
}

TEST(Sales, PlusOperatorWithValueAsFirstOperandWorks) {
    // Arrange
    Sales s{15, 10};
    unsigned int paperbackIncrease = 3;
    Sales expected{s.getPaperback() + paperbackIncrease, s.getEbook()};

    // Act
    auto actual = paperbackIncrease + s;

    // Assert
    EXPECT_EQ(expected.getPaperback(), actual.getPaperback());
    EXPECT_EQ(expected.getEbook(), actual.getEbook());
}

TEST(Sales, PlusOperatorWithValueAsFirstOperandAndExplicitCallWorks) {
    // Arrange
    Sales s{15, 10};
    unsigned int paperbackIncrease = 3;
    Sales expected{s.getPaperback() + paperbackIncrease, s.getEbook()};

    // Act
    auto actual = operator+(paperbackIncrease, s);

    // Assert
    EXPECT_EQ(expected.getPaperback(), actual.getPaperback());
    EXPECT_EQ(expected.getEbook(), actual.getEbook());
}

TEST(Sales, UnaryPrefixIncrementWorks) {
    // Arrange
    unsigned int originalPaperback = 15;
    unsigned int originalEbook = 10;
    Sales s{originalPaperback, originalEbook};

    // Act
    ++s;

    // Assert
    EXPECT_EQ(s.getPaperback(), originalPaperback + 1);
    EXPECT_EQ(s.getEbook(), originalEbook + 1);
}

TEST(Sales, UnaryPrefixDecrementWorks) {
    // Arrange
    unsigned int originalPaperback = 15;
    unsigned int originalEbook = 10;
    Sales s{originalPaperback, originalEbook};

    // Act
    --s;

    // Assert
    EXPECT_EQ(s.getPaperback(), originalPaperback - 1);
    EXPECT_EQ(s.getEbook(), originalEbook - 1);
}

TEST(Sales, UnaryPostfixIncrementWorks) {
    // Arrange
    unsigned int originalPaperback = 15;
    unsigned int originalEbook = 10;
    Sales s{originalPaperback, originalEbook};

    // Act
    s++;

    // Assert
    EXPECT_EQ(s.getPaperback(), originalPaperback + 1);
    EXPECT_EQ(s.getEbook(), originalEbook + 1);
}

TEST(Sales, UnaryPostfixDecrementWorks) {
    // Arrange
    unsigned int originalPaperback = 15;
    unsigned int originalEbook = 10;
    Sales s{originalPaperback, originalEbook};

    // Act
    s--;

    // Assert
    EXPECT_EQ(s.getPaperback(), originalPaperback - 1);
    EXPECT_EQ(s.getEbook(), originalEbook - 1);
}

TEST(Sales, UnaryNotAsFriendFunctionWorksAsExpected) {
    // Arrange
    unsigned int originalPaperback = 15;
    unsigned int originalEbook = 10;
    Sales notZero{originalPaperback, originalEbook};
    Sales zero{0, 0};

    // Act
    auto isNotZeroEqualToZero = !notZero;
    auto isZeroEqualToZero = !zero;

    // Assert
    EXPECT_FALSE(isNotZeroEqualToZero);
    EXPECT_TRUE(isZeroEqualToZero);
}

TEST(Sales, AssignmentOperatorDoesNotCopyButRatherAssign) {
    // Arrange
    Sales s{100, 50};

    // Act
    Sales s2 = s;

    // Assert
    EXPECT_EQ(s.getPaperback(), s2.getPaperback());
    EXPECT_EQ(s.getEbook(), s2.getEbook());
}

// It doesn't really make sense with unsigned int values...
TEST(Sales, UnaryMinusInvertsAllValues) {
    // Arrange
    unsigned int paperback = 53;
    unsigned int ebook = 28;
    auto expectedPaperback = -paperback;
    auto expectedEbook = -ebook;

    Sales s{paperback, ebook};

    // Act
    auto s2 = -s;

    // Assert
    EXPECT_EQ(expectedPaperback, s2.getPaperback());
    EXPECT_EQ(expectedEbook, s2.getEbook());
}

TEST(Sales, EqualityReturnsCorrectValue) {
    // Arrange
}
