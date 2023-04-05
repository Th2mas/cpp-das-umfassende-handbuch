//
// Created by tkhle on 05.04.2023.
//
#include "../include/Hero.h"
#include "../include/Superhero.h"

Superhero::Superhero(std::string name, unsigned int age, std::string power): Hero(name, age), power(power) {
}

const std::string &Superhero::getPower() const {
    return power;
}

void Superhero::setPower(const std::string &power) {
    Superhero::power = power;
}
