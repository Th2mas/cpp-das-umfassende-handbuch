//
// Created by tkhle on 27.02.2023.
//
#include "gtest/gtest.h"
#include "../include/OS.h"

TEST(OS, GetOSReturnsCorrectEnum) {
    // Arrange
    OS os{0};
    auto expected = OS::OSType::LINUX;

    // Act
    os.setOS(expected);
    auto actual = os.getOS();

    // Assert
    EXPECT_EQ(expected, actual);
}

TEST(OS, GetConstProperty) {
    // Arrange
    unsigned int expected = 5;
    OS os{expected};

    // Act
    auto actual = os.getID();

    // Assert
    EXPECT_EQ(expected, actual);
}
