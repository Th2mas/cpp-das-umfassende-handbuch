//
// Created by tkhle on 22.07.2023.
//
#include <deque>
#include <unordered_map>
#include <algorithm>
#include "gtest/gtest.h"
#include "../include/DataClass.h"
#include "../include/DataClassHash.h"

TEST(Set, Insert) {
    // Arrange
    std::deque<int> deque{1, 1, 2, 3, 4};
    std::set<int> set{deque.begin(), deque.end()};
    std::multiset<int> multiset{deque.begin(), deque.end()};

    // Act
    set.insert(5);
    set.insert(5);
    multiset.insert(5);
    multiset.insert(5);

    // Assert
    EXPECT_EQ(set.size(), 5);
    EXPECT_EQ(multiset.size(), 7);
    EXPECT_EQ(*set.begin(), 1);
    EXPECT_EQ(*(++set.begin()), 2);
    EXPECT_EQ(*multiset.begin(), 1);
    EXPECT_EQ(*(++multiset.begin()), 1);
    EXPECT_EQ(set.count(5), 1);
    EXPECT_EQ(multiset.count(5), 2);
}

TEST(Set, Erase) {
    // Arrange
    std::set<int> set{1, 1, 2, 3, 4};

    // Act
    set.erase(1);

    // Assert
    EXPECT_EQ(set.size(), 3);
    EXPECT_EQ(*set.begin(), 2);
}

TEST(Map, InsertEmplace) {
    // Arrange
    std::map<int, std::string> map;

    // Act
    map.insert(std::make_pair(1, "1"));
    map.emplace(2, "2");
    auto pair = map.begin();
    auto secondPair = map.find(2);

    // Assert
    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(pair->first, 1);
    EXPECT_EQ(pair->second, "1");
    EXPECT_EQ(secondPair->first, 2);
    EXPECT_EQ(secondPair->second, "2");
}

TEST(Multimap, InsertEmplace) {
    // Arrange
    std::multimap<std::string, std::string> phonebook;

    // Act
    phonebook.insert(std::make_pair("Max Man", "+43 664 123456"));
    phonebook.emplace("Max Man", "+49 664 456789");
    phonebook.emplace("Maria Book", "+44 567 890789");

    auto maxManEntry = phonebook.find("Max Man");

    // Assert
    EXPECT_EQ(phonebook.size(), 3);
    EXPECT_EQ(phonebook.count("Max Man"), 2);
    EXPECT_EQ(maxManEntry->first, "Max Man");
    EXPECT_EQ(maxManEntry->second, "+43 664 123456");
    maxManEntry++;
    EXPECT_EQ(maxManEntry->second, "+49 664 456789");
}

TEST(UnordereredMultiMap, EmplaceAndBucket) {
    std::unordered_multimap<std::string, int> numbers;
    numbers.emplace("Stark", 5557354);
    numbers.emplace("Stark", 5557345);
    numbers.emplace("Wayne", 555987);
    numbers.emplace("Banner", 5558883);

    // This is not perfect, since the lambda returns true for the two "Stark" elements and therefore the count_if returns 2
    bool atLeastOneBucketHasTwoElements = std::count_if(numbers.begin(), numbers.end(), [numbers](const auto& pair){
        return numbers.bucket_size(numbers.bucket(pair.first)) >= 2;
    }) > 0;
    bool atLeastOneBucketHasNoElements = std::count_if(numbers.begin(), numbers.end(), [numbers](const auto& pair){
        return numbers.bucket_size(numbers.bucket(pair.first)) == 0;
    }) > 0;

    EXPECT_GE(numbers.bucket_count(), 4);
    EXPECT_TRUE(atLeastOneBucketHasTwoElements);
    EXPECT_TRUE(atLeastOneBucketHasNoElements);
}

TEST(UnorderedMultiMap, WithCustomHash) {
    std::unordered_multimap<DataClass, int, DataClassHash> values;
    values.emplace(101, 1234);
    values.emplace(100, 3212);
    values.emplace(202, 4325);
    values.emplace(199, 3311);

    bool atLeastOneBucketHasTwoElements = std::count_if(values.begin(), values.end(), [values](const auto& pair){
        return values.bucket_size(values.bucket(pair.first)) >= 2;
    }) > 0;

    EXPECT_GE(values.bucket_count(), 4);
    EXPECT_TRUE(atLeastOneBucketHasTwoElements);
}
