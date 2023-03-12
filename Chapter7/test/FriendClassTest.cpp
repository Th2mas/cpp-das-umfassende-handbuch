//
// Created by tkhle on 12.03.2023.
//
#include <gtest/gtest.h>
#include "../include/FriendClass.h"

TEST(FriendClass, FriendClassCanChangeOtherClassesValue) {
    // Arrange
    A a{1};
    B b;
    int expected = 2;

    // Act
    b.changeA(a);

    // Assert
    EXPECT_EQ(expected, a.getValue());
}
