//
// Created by tkhle on 22.07.2023.
//
#include "gtest/gtest.h"
#include <vector>
#include <deque>
#include <array>
#include <forward_list>
#include <stack>

TEST(Vector, PushEmplace) {
    // Arrange
    std::vector<int> vector;

    // Act
    vector.push_back(3);
    // no push_front
    vector.emplace(vector.begin(), 1);
    vector.emplace_back(5);

    // Assert
    ASSERT_EQ(vector.at(0), 1);
    ASSERT_EQ(vector.at(1), 3);
    ASSERT_EQ(vector.at(2), 5);
    ASSERT_EQ(vector.size(), 3);
}

TEST(Deque, PushEmplace) {
    // Arrange
    std::deque<int> deque;

    // Act
    deque.push_back(1);
    deque.push_front(2);
    deque.emplace(deque.begin(), 3);    // emplace* doesn't copy an object, if it is added to the container
    deque.emplace_back(4);

    // Assert
    ASSERT_EQ(deque.at(0), 3);
    ASSERT_EQ(deque.at(1), 2);
    ASSERT_EQ(deque.at(2), 1);
    ASSERT_EQ(deque.at(3), 4);
    ASSERT_EQ(deque.size(), 4);
}

TEST(Array, SizeAndRange) {
    // Arrange
    const int size = 10;
    std::array<double, size> array{};

    // Act
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    double sum = 0;
    for (double & it : array) {
        sum += it;
    }

    // Assert
    EXPECT_EQ(array.size(), size);
    EXPECT_EQ(array.at(5), 5);
    EXPECT_EQ(sum, 45);
}

TEST(ForwardList, Test) {
    // Arrange
    std::forward_list<char> forwardList;

    // Act
    forwardList.push_front('a');
    // no push_back or emplace*
    forwardList.push_front('b');

    forwardList.pop_front();

    // No size method
    int size = 0;
    for (auto it = forwardList.begin(); it != forwardList.end(); it++) {
        size++;
    }

    // Assert
    EXPECT_EQ(size, 1);
    EXPECT_EQ(forwardList.front(), 'a');
}

TEST(ForwardList, Sort) {
    // Arrange
    std::forward_list<char> forwardList;

    // Act
    forwardList.push_front('c');
    forwardList.push_front('b');
    forwardList.push_front('o');
    forwardList.push_front('d');

    forwardList.sort();
    std::string s;
    for (auto it = forwardList.begin(); it != forwardList.end(); it++) {
        s += *it;
    }

    // Assert
    EXPECT_EQ(s, "bcdo");
}

TEST(Stack, PushPopTop) {
    // Arrange
    std::stack<double> stack;

    // Act
    stack.push(5);
    stack.push(4);
    stack.push(9);
    stack.push(1.4);

    // Assert
    EXPECT_EQ(stack.top(), 1.4);
    stack.pop();    // pop does not return the removed element!
    EXPECT_EQ(stack.top(), 9);
    stack.pop();
    EXPECT_EQ(stack.size(), 2);
    EXPECT_FALSE(stack.empty());
    stack.pop();
    stack.pop();
    EXPECT_TRUE(stack.empty());
}
