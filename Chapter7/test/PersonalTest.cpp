//
// Created by tkhle on 19.02.2023.
//
#include <gtest/gtest.h>
#include "../include/Personal.h"

TEST(Personal, InitializesFieldsCorrectly) {
    // Arrange
    std::string expectedName = "";
    unsigned int expectedPersNr = 0;
    unsigned int expectedSalary = 1800;

    // Act
    Personal personal;

    // Assert
    EXPECT_EQ(expectedName, personal.getName());
    EXPECT_EQ(expectedPersNr, personal.getPersonalNumber());
    EXPECT_EQ(expectedSalary, personal.getSalary());
}

