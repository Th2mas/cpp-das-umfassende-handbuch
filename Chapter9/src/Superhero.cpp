//
// Created by tkhle on 05.04.2023.
//
#include <iostream>
#include "../include/Hero.h"
#include "../include/Superhero.h"

// We call the initializer of Hero "base initializer"
Superhero::Superhero(std::string name, unsigned int age, std::string power): Hero(name, age), power(power) {
}

Superhero::~Superhero() {
    std::cout << "Destroying superhero" << std::endl;
}

const std::string &Superhero::getPower() const {
    return power;
}

void Superhero::setPower(const std::string &power) {
    Superhero::power = power;
}

const std::string Superhero::toString() const {
    return Hero::toString() + ", Power: " + power;
}

const std::string Superhero::type() {
    return "Superhero";
}
