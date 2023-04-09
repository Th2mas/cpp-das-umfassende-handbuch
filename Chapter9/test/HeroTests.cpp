//
// Created by tkhle on 09.04.2023.
//
#include <gtest/gtest.h>
#include "../include/Hero.h"

TEST(Hero, Constructor) {
    // Arrange
    std::string name = "Hero";
    unsigned int age = 40;

    // Act
    Hero hero{name, age};

    // Assert
    EXPECT_EQ(name, hero.getName());
    EXPECT_EQ(age, hero.getAge());
}

TEST(Hero, ToString) {
    // Arrange
    std::string name = "Hero";
    unsigned int age = 40;
    std::string expected = "Name: " + name + ", Age: " + std::to_string(age);

    Hero hero{name, age};

    // Act
    auto actual = hero.toString();

    // Assert
    EXPECT_STREQ(expected.c_str(), actual.c_str());
}

TEST(Hero, NonVirtualMethodOverride) {
    EXPECT_STREQ("Hero", Hero::type().c_str());
}
