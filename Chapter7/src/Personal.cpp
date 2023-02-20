//
// Created by tkhle on 19.02.2023.
//
#include "../include/Personal.h"

// We use the scope operator ::
Personal::Personal() {
    name = "";
    personalNumber = 0;
    salary = 1800;
}

Personal::Personal(std::string name) {
    this->name = name;
    this->personalNumber = 0;
    this->salary = 0;
}

Personal::Personal(std::string name, unsigned int personalNumber) {
    this->name = name;
    this->personalNumber = personalNumber;
    this->salary = 0;
}

Personal::Personal(std::string name, unsigned int personalNumber, unsigned int salary) {
    this->name = name;
    this->personalNumber = personalNumber;
    this->salary = salary;
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
