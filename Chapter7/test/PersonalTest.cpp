//
// Created by tkhle on 19.02.2023.
//
#include <gtest/gtest.h>
#include <fmt/core.h>
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
    /*
    EXPECT_EQ(person01.getName(), "");
    EXPECT_EQ(person01.getPersonalNumber(), expectedPersonalNumber);
    EXPECT_EQ(person01.getSalary(), expectedSalary);
    */
    EXPECT_EQ(person01.getName(), "");
    EXPECT_NE(person01.getPersonalNumber(), expectedPersonalNumber);
    EXPECT_NE(person01.getSalary(), expectedSalary);
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

TEST(Personal, InitPersonalSetsValuesCorrectly) {
    // Arrange
    PersonalData personalData = {"Batman", 100489, 2500};
    std::string defaultName = "";
    unsigned int defaultPersonalNumber = 0;
    unsigned int defaultSalary = 1900;

    // Act
    Personal person1, person2;
    person1.initPersonal(personalData.name, personalData.personalNumber, personalData.salary);
    person2.initPersonal();

    // Assert
    expectPersonalContains(person1, personalData);
    EXPECT_EQ(defaultName, person2.getName());
    EXPECT_EQ(defaultPersonalNumber, person2.getPersonalNumber());
    EXPECT_EQ(defaultSalary, person2.getSalary());
}

TEST(Personal, ShowDestructorFunctionality) {
    GTEST_SKIP();
    auto simple_function = [](){Personal person("simple function Batman");};
    Personal *person1 = new Personal("new Batman");
    static Personal person2("static Batman");   // Static objects are deleted after the completion of the "main" function
    simple_function();
    delete person1;
    Personal person3("local Batman");
    {
        Personal person4("scope Batman");
        std::unique_ptr<Personal> person5(new Personal("unique_ptr Batman"));
    }
    // person3.~Personal(); // Although this is possible, it leads to unexpected/undefined behaviour since the destructor is called multiple times!
}

TEST(Personal, ShowStructCanBeUsedAsClass) {
    GTEST_SKIP();
    PersonalStruct personalStruct;  // Since "struct" in C++ is a variant of "class", we don't need a typedef!
    // personalStruct.privateInt;   // Not possible, since "privateInt" was declared private
    personalStruct.publicInt;
}

TEST(Personal, ToString) {
    // Arrange
    std::string name = "Batman";
    unsigned int personalNumber = 1900;
    unsigned int salary = 2800;
    Personal personal{name, personalNumber, salary};

    auto expected = fmt::format("Personal[name={}, personalNumber={}, salary={}]", name, personalNumber, salary);
    // auto expected = std::format("Personal[name={}, personalNumber={}, salary={}]", name, personalNumber, salary);    // should work with C++20

    // Act
    auto actual = personal.toString();

    // Assert
    EXPECT_EQ(expected, actual);
}

TEST(Personal, CompareSalaryReturnsObjectWithHighestSalary) {
    // Arrange
    const Personal p1{"P1", 0, 2200};
    const Personal p2{"P2", 1, 2300};

    const Personal expected = p2;

    // Act
    auto actual = p1.compareSalary(p2);

    // Assert
    expectPersonalEquals(expected, actual);
}

TEST(Personal, FriendGlobalFunctionHasAccessToObjectPrivateProperties) {
    // Arrange
    unsigned int multiplier = 3;
    const Personal p{"P1", 0, 2300};
    const auto expected = p.getSalary() * multiplier;

    // Act
    const auto actual = multiplySalary(p, multiplier);

    // Assert
    EXPECT_EQ(expected, actual);
}
