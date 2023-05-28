//
// Created by tkhle on 28.05.2023.
//

#ifndef CHAPTER9_MOTORCYCLE_H
#define CHAPTER9_MOTORCYCLE_H

#include "Bicycle.h"
#include "MotorVehicle.h"

class Motorcycle : public Bicycle, public MotorVehicle {
    std::string brand;
    public:
    explicit Motorcycle(unsigned int speed = 0, unsigned int weight = 0, unsigned int power = 0, std::string brand = 0);
    void print() override;

    const std::string &get_brand() const;

    void set_brand(const std::string &brand);
};

#endif //CHAPTER9_MOTORCYCLE_H
