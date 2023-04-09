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

// We don't have access to Hero's private member variables
class Superhero final : public Hero {
    std::string power;
public:
    Superhero(std::string name, unsigned int age, std::string power);

    const std::string &getPower() const;

    void setPower(const std::string &power);

    // Note: 'override' can only be used, if the original method is virtual
    const std::string toString() const override;

    // A non-virtual method can not be annotated with override
    static const std::string type();
};

#endif //CHAPTER9_SUPERHERO_H
