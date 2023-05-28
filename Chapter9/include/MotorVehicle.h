//
// Created by tkhle on 28.05.2023.
//

#ifndef CHAPTER9_MOTORVEHICLE_H
#define CHAPTER9_MOTORVEHICLE_H

#include "Vehicle.h"

// We need the "virtual" keyword so that there are no ambiguous function calls in sub-classes (e.g. "drive")
// This only makes sense in the context of multiple inheritance
// The Vehicle class then only exists once in memory
class MotorVehicle : virtual public Vehicle {
    unsigned int power;
    unsigned int weight;
public:
    MotorVehicle(unsigned int speed = 0, unsigned int power = 0, unsigned int weight = 0): Vehicle(speed), weight(weight), power(power) {}
    void print() override;

    unsigned int get_power() const;

    void set_power(unsigned int power);

    unsigned int get_weight() const;

    void set_weight(unsigned int weight);
};

#endif //CHAPTER9_MOTORVEHICLE_H
