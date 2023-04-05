//
// Created by tkhle on 05.04.2023.
//

#ifndef CHAPTER9_SUPERHERO_H
#define CHAPTER9_SUPERHERO_H

#include "Hero.h"

// The keyword "final" after the class name defines that no other class can extend this class
// The access modifiers defined when extending a base class define how you want to access the member of the base class
// "public" allows access to the "public" and "protected" members of the base class
// "private" converts the "public" and "protected" members of the base class to "private" members of the sub-class
// (forbids public access to all super classes when working with this class)
// "protected" works similar to "private", but converts the members of all super classes to "protected" members of the
// extended class
class Superhero final : public Hero {
    std::string power;
public:
    Superhero(std::string name, unsigned int age, std::string power);

    const std::string &getPower() const;

    void setPower(const std::string &power);
};

#endif //CHAPTER9_SUPERHERO_H
