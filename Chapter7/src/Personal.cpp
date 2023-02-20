//
// Created by tkhle on 19.02.2023.
//
#include "../include/Personal.h"

// We use the scope operator ::
Personal::Personal() : Personal("", 0, 1800) {
}

// Without the element initializer, 'name' would first be an empty string (every string is first initialized with "")
// and only then we would pass the actual param -> more efficient
// Only with an element initializer it is possible to "instantiate" a const variable
Personal::Personal(std::string name) : Personal(name, 0, 0) {
}

Personal::Personal(std::string name, unsigned int personalNumber) : Personal(name, personalNumber, 0) {
}

Personal::Personal(std::string name, unsigned int personalNumber, unsigned int salary) :
        name(name), personalNumber(personalNumber), salary(salary) {
}

const std::string &Personal::getName() const {
    return name;
}

unsigned int Personal::getPersonalNumber() const {
    return personalNumber;
}

unsigned int Personal::getSalary() const {
    return salary;
}
