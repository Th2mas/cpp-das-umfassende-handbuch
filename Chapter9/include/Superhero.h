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
    // With constructors, the constructors of the super classes are called first; the derived class comes last
    // With destructors, it is the other way around: The destructor of the derived class comes first, then the super class and so on
    Superhero(std::string name, unsigned int age, std::string power);

    // Use all constructors from the parent class (it might not make much sense here, but this is how it works)
    // We can not pass a subset of the constructors, but pass all of them (but the compiler generates code only for those
    // that are actually used)
    // Only the copy- and base constructor (no params) of the parent class are not derived
    using Hero::Hero;

    const std::string &getPower() const;

    void setPower(const std::string &power);

    // Note: 'override' can only be used, if the original method is virtual
    // This method is implicitly also virtual
    const std::string toString() const override;

    // A non-virtual method can not be annotated with override
    static const std::string type();
};

#endif //CHAPTER9_SUPERHERO_H
