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
    EXPECT_STREQ(company, employee1.getCompany());
}
