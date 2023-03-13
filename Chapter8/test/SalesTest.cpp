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
