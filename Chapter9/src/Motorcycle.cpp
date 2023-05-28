//
// Created by tkhle on 28.05.2023.
//
#include <iostream>
#include <utility>
#include "../include/Motorcycle.h"

Motorcycle::Motorcycle(unsigned int speed, unsigned int weight, unsigned int power, std::string brand) :
        Bicycle(speed, weight), MotorVehicle(speed, power, weight), brand(std::move(brand)) {}

void Motorcycle::print() {
    MotorVehicle::print();
    std::cout << "Brand: " << brand << std::endl;
}

const std::string &Motorcycle::get_brand() const {
    return brand;
}

void Motorcycle::set_brand(const std::string &brand) {
    Motorcycle::brand = brand;
}
