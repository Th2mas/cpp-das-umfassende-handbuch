//
// Created by tkhle on 19.02.2023.
//
#include "../include/Personal.h"

// We use the scope operator ::
Personal::Personal(): name(""), personalNumber(0), salary(1800) {
}

Personal::Personal(std::string name): name(name), personalNumber(0), salary(0) {
}

Personal::Personal(std::string name, unsigned int personalNumber): name(name), personalNumber(personalNumber), salary(0) {
}

Personal::Personal(std::string name, unsigned int personalNumber, unsigned int salary): name(name), personalNumber(personalNumber), salary(salary) {
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
