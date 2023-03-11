//
// Created by tkhle on 11.03.2023.
//
#include <gtest/gtest.h>
#include "../include/Window.h"

TEST(Window, CanBeBuilt) {
    // Arrange
    unsigned int expectedX = 2550;
    unsigned int expectedY = 1880;
    unsigned int expectedPixel = 4794000;

    // Act
    constexpr Window window{5000, 5000};
    constexpr unsigned int actualPixel = window.getPixelSize();
    constexpr unsigned int actualX = window.getSizeX();
    constexpr unsigned int actualY = window.getSizeY();

    // Assert
    EXPECT_EQ(expectedPixel, actualPixel);
    EXPECT_EQ(expectedX, actualX);
    EXPECT_EQ(expectedY, actualY);
}
