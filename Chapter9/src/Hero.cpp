//
// Created by tkhle on 05.04.2023.
//
#include <iostream>
#include "../include/Hero.h"

const unsigned int defaultAge = 25;

Hero::Hero(std::string name, unsigned int age) {
    Hero::name = name;
    Hero::age = age;
}

Hero::Hero(std::string name) : Hero(name, defaultAge) {
}

Hero::Hero() : Hero("No name") {}

Hero::~Hero() {
    std::cout << "Destroying hero" << std::endl;
}

const std::string &Hero::getName() const {
    return name;
}

void Hero::setName(const std::string &name) {
    Hero::name = name;
}

unsigned int Hero::getAge() const {
    return age;
}

void Hero::setAge(unsigned int age) {
    Hero::age = age;
}

const std::string Hero::toString() const {
    return "Name: " + name + ", Age: " + std::to_string(age);
}

const std::string Hero::type() {
    return "Hero";
}
