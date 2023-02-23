//
// Created by tkhle on 19.02.2023.
//
#include <gtest/gtest.h>
#include "../include/Personal.h"

typedef struct PersonalData {
    std::string name;
    unsigned int personalNumber;
    unsigned int salary = 1800;
} PersonalData;

void expectPersonalContains(const Personal &expectedPerson, const PersonalData &personalData) {
    EXPECT_EQ(expectedPerson.getName(), personalData.name);
    EXPECT_EQ(expectedPerson.getPersonalNumber(), personalData.personalNumber);
    EXPECT_EQ(expectedPerson.getSalary(), personalData.salary);
}

void expectPersonalEquals(const Personal &personal1, const Personal &personal2) {
    EXPECT_EQ(personal1.getName(), personal2.getName());
    EXPECT_EQ(personal1.getPersonalNumber(), personal2.getPersonalNumber());
    EXPECT_EQ(personal1.getSalary(), personal2.getSalary());
}

TEST(Personal, ConstructorInitializesFieldsCorrectly) {
    // Arrange
    PersonalData personalData = {"", 0, 1800};

    // Act
    Personal personal;

    // Assert
    expectPersonalContains(personal, personalData);
}

TEST(Personal, OverloadedConstructorInitializesFieldsCorrectly) {
    // Arrange
    PersonalData p1 = {"Max Mustermann", 100480, 2200};
    PersonalData p2 = {"Maxi Musterfrau", 100481, 2300};
    PersonalData p3 = {"Hans Muster", 100482};
    PersonalData p4 = {"Marie Muster"};

    // Act
    Personal person01(p1.name, p1.personalNumber, p1.salary);
    Personal person02{p2.name, p2.personalNumber, p2.salary};
    Personal person03(p3.name, p3.personalNumber);
    Personal person04{p4.name};

    // Assert
    expectPersonalContains(person01, p1);
    expectPersonalContains(person02, p2);
    expectPersonalContains(person03, p3);
    expectPersonalContains(person04, p4);
}

TEST(Personal, DefaultCopyConstructorWorks) {
    // Arrange
    Personal defaultPersonal{"Default"};

    // Act
    Personal copyPersonal(defaultPersonal);
    Personal copyPersonal2 = defaultPersonal;   // calls the copy constructor instead of the assignment!

    // Act
    expectPersonalEquals(defaultPersonal, copyPersonal);
    expectPersonalEquals(defaultPersonal, copyPersonal2);
    expectPersonalEquals(copyPersonal, copyPersonal2);
}

TEST(Personal, ShowMoveConstructorOperation) {
    // Arrange
    std::string expectedName = "Batman";
    unsigned int expectedPersonalNumber = 100488;
    unsigned int expectedSalary = 2200;

    Personal person01{expectedName, expectedPersonalNumber, expectedSalary};

    // Act
    Personal person02 = std::move(person01);

    // Assert
    expectPersonalContains(person02, {expectedName, expectedPersonalNumber, expectedSalary});

    // Default value of a string (which is an object) is an empty string, the rest (primitives) is not moved! This is the default implementation!
    EXPECT_EQ(person01.getName(), "");
    EXPECT_EQ(person01.getPersonalNumber(), expectedPersonalNumber);
    EXPECT_EQ(person01.getSalary(), expectedSalary);
}

TEST(Personal, AvoidImplicitConversion) {
    // Arrange
    const char name[] = "Batman";

    // Act
    Personal person(name);  // should work without another constructor which accepts C strings instead of std::string

    // Even if CLion complains that there is "no viable conversion from const char[] to Personal",
    // the following two lines work when using implicit conversion
    // To avoid this, we use the "explicit" keyword to forbid this
    Personal person2 = name;
    Personal person3 = "Superman";

    // Assert
    EXPECT_EQ(person.getName(), name);
    EXPECT_EQ(person2.getName(), name);
    EXPECT_EQ(person3.getName(), "Superman");
}

TEST(Personal, ShowingDifferenceBetweenNormalConstructorAndUnifiedInitializationList) {
    GTEST_SKIP();
    Personal person1("Batman", 100.48, 1000);   // we pass a double to personalNumber (uint) -> gets implicitly casted
    // Personal person2{"Batman", 100.48, 1000};   // when passing a double, we get an error
    Personal person2{"Batman", static_cast<unsigned int>(100.48), 1000};    // We need to cast explicitly
}
