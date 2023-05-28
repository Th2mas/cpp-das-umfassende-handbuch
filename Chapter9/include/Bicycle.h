//
// Created by tkhle on 28.05.2023.
//

#ifndef CHAPTER9_BICYCLE_H
#define CHAPTER9_BICYCLE_H

#include "Vehicle.h"

class Bicycle : virtual public Vehicle {
    unsigned int weight;
public:
    explicit Bicycle(unsigned int speed = 0, unsigned int weight = 0): Vehicle(speed), weight(weight) {}
    void print() override;

    void set_weight(unsigned int weight);
    unsigned int get_weight() const;
};

#endif //CHAPTER9_BICYCLE_H
