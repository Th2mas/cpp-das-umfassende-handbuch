//
// Created by tkhle on 28.05.2023.
//
#include "../include/Bicycle.h"

void Bicycle::print() {
    Vehicle::print();
    std::cout << "Weight: " << weight << std::endl;
}

void Bicycle::set_weight(unsigned int weight) {
    this->weight = weight;
}

unsigned int Bicycle::get_weight() const {
    return weight;
}
