//
// Created by tkhle on 28.02.2023.
//
#include "gtest/gtest.h"
#include "../include/Employee.h"

TEST(Employee, UsingShallowCopyWithPointersWillDeleteOtherResource) {
    GTEST_SKIP();

    // Arrange
    const char* company = "Wayne Enterprise";
    Personal personal{"Batman", 0, 10000};
    Employee employee1{company, personal};

    // Act
    {
        Employee employee2(employee1);
    }

    // Assert
    // this will now throw a SEHException on Windows (we are trying to get a pointer which was deleted) if we don't use a deep copy
    // With a shallow copy, employee1.getCompany() == employee2.getCompany() (before employee2 gets destroyed)
    // employee1.getCompany();
}

TEST(Employee, UsingDeepCopyWithPointersWillNotDeleteOtherResource) {
    // Arrange
    const char* company = "Wayne Enterprise";
    Personal personal{"Batman", 0, 10000};
    Employee employee1{company, personal};

    // Act
    {
        Employee employee2(employee1);
    }

    // Assert
    EXPECT_NE(company, employee1.getCompany());
    EXPECT_STREQ(company, employee1.getCompany());
}

TEST(Employee, StaticVariableIsProperlyIncrementedAndDecrementedWithConstructorAndDestructor) {
    // Arrange
    unsigned int originalEmployeeCount = Employee::getEmployeeCount();
    unsigned int additionalEmployeeCount = 3;
    auto expectedEmployeeCount = originalEmployeeCount + additionalEmployeeCount;

    // Act and assert
    {
        Personal personal1{"Batman", 1, 10000};
        Employee employee1{"E1", personal1};
        Employee employee2{"E2", personal1};
        Employee employee3{"E3", personal1};

        EXPECT_EQ(expectedEmployeeCount, Employee::getEmployeeCount());
    }
    EXPECT_EQ(originalEmployeeCount, Employee::getEmployeeCount());
}
