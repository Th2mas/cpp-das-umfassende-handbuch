//
// Created by tkhle on 28.05.2023.
//
#include <iostream>
#include "../include/MotorVehicle.h"

void MotorVehicle::print() {
    Vehicle::print();
    std::cout << "Weight: " << weight << std::endl;
    std::cout << "Power: " << power << std::endl;
}

unsigned int MotorVehicle::get_power() const {
    return power;
}

void MotorVehicle::set_power(unsigned int power) {
    MotorVehicle::power = power;
}

unsigned int MotorVehicle::get_weight() const {
    return weight;
}

void MotorVehicle::set_weight(unsigned int weight) {
    MotorVehicle::weight = weight;
}
