//
// Created by tkhle on 28.05.2023.
//
#include <gtest/gtest.h>
#include "../include/Motorcycle.h"

TEST(Motorcycle, SetsCorrectValues) {
    // Arrange
    Motorcycle motorcycle{100, 250, 80, "Yamaha"};

    // Act
    motorcycle.print();

    // No assert
}

TEST(Motorcycle, Drive) {
    // Arrange
    Motorcycle motorcycle{100, 250, 80, "Yamaha"};

    // Act
    motorcycle.drive();

    // No assert
}
