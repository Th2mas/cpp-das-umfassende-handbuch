//
// Created by tkhle on 19.02.2023.
//
#include <gtest/gtest.h>
#include "../include/Personal.h"

typedef struct PersonalData {
    std::string name;
    unsigned int personalNumber;
    unsigned int salary;
} PersonalData;

void expectPersonalContains(Personal expectedPerson, PersonalData personalData) {
    EXPECT_EQ(expectedPerson.getName(), personalData.name);
    EXPECT_EQ(expectedPerson.getPersonalNumber(), personalData.personalNumber);
    EXPECT_EQ(expectedPerson.getSalary(), personalData.salary);
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
