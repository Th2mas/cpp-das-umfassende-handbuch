//
// Created by tkhle on 05.04.2023.
//
#include "../include/Superhero.h"
#include <gtest/gtest.h>

TEST(Superhero, ConstructorWorks) {
    // Arrange
    std::string name = "Batman";
    unsigned int age = 40;
    std::string power = "No power";

    // Act
    Superhero batman{name, age, power};

    // Assert
    EXPECT_EQ(name, batman.getName());
    EXPECT_EQ(age, batman.getAge());
    EXPECT_EQ(power, batman.getPower());
}