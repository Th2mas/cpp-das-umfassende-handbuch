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
    EXPECT_EQ(expected, actual);
}

TEST(Superhero, NonVirtualMethodOverride) {
    EXPECT_STREQ("Superhero", Superhero::type().c_str());
}

TEST(Superhero, AccessToSuperClassMethodSameAsSuperClassCall) {
    // Arrange
    std::string name = "Batman";
    unsigned int age = 40;
    std::string power = "No power";

    Hero noPowerBatman{name, age};
    Superhero batmanWithPower{name, age, power};

    // Act and assert
    EXPECT_EQ(noPowerBatman.toString(), batmanWithPower.Hero::toString());
}

TEST(Superhero, UseDerivedConstructor) {
    // Arrange
    std::string name = "Batman";
    unsigned int age = 40;

    // Act
    Superhero noPowerBatman{name, age};

    // Assert
    EXPECT_EQ(name, noPowerBatman.getName());
    EXPECT_EQ(age, noPowerBatman.getAge());
}

TEST(Superhero, CallingVirtualMethodOnPointerCallsDerivedMethod) {
    // Arrange
    std::string name = "Batman";
    unsigned int age = 40;
    std::string power = "";
    std::string expected = "Name: " + name + ", Age: " + std::to_string(age) + ", Power: " + power;

    // Act
    // We use pointers, so we can use dynamic binding! (similar to Java's "Hero h = new Superhero()")
    Hero *h = new Superhero(name, age);

    // Assert
    EXPECT_EQ(expected, h->toString());

    // For checking which destructor is called (with a simple print) -> first superhero, then hero
    delete h;
}
