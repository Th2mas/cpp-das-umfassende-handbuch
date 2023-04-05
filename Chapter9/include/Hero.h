//
// Created by tkhle on 05.04.2023.
//

#ifndef CHAPTER9_HERO_H
#define CHAPTER9_HERO_H

#include <string>

class Hero {
    std::string name;
    unsigned int age;
public:
    Hero();

    Hero(std::string name, unsigned int age);

    // ClangTidy: Constructors with one parameter should be marked with "explicit" to avoid unintentional implicit conversions
    explicit Hero(std::string name);

    const std::string &getName() const;

    void setName(const std::string &name);

    unsigned int getAge() const;

    void setAge(unsigned int age);
};

#endif //CHAPTER9_HERO_H
