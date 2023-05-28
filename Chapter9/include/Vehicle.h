//
// Created by tkhle on 27.05.2023.
//

#ifndef CHAPTER9_VEHICLE_H
#define CHAPTER9_VEHICLE_H

#include <iostream>

class Vehicle {
    unsigned int speed;
public:
    explicit Vehicle(unsigned int speed = 0): speed(speed) {}

    void drive();
    virtual void print();
    void set_speed(unsigned int speed);
    unsigned int get_speed() const;
};

#endif //CHAPTER9_VEHICLE_H
