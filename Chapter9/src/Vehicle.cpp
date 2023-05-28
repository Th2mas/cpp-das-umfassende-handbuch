//
// Created by tkhle on 27.05.2023.
//
#include "../include/Vehicle.h"

void Vehicle::drive() {
    std::cout << "The vehicle is driving" << std::endl;
}

void Vehicle::print() {
    std::cout << "Speed: " << speed << std::endl;
}

void Vehicle::set_speed(unsigned int speed) {
    this->speed = speed;
}

unsigned int Vehicle::get_speed() const {
    return speed;
}
