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

TEST(Superhero, ToString) {
    // Arrange
    std::string name = "Batman";
    unsigned int age = 40;
    std::string power = "No power";
    std::string expected = "Name: " + name + ", Age: " + std::to_string(age) + ", Power: " + power;

    Superhero batman{name, age, power};

    // Act
    auto actual = batman.toString();

    // Assert
    EXPECT_STREQ(expected.c_str(), actual.c_str());
}

TEST(Superhero, NonVirtualMethodOverride) {
    EXPECT_STREQ("Superhero", Superhero::type().c_str());
}
