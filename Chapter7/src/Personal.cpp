//
// Created by tkhle on 19.02.2023.
//
#include <iostream>
#include <utility>
#include "../include/Personal.h"
#include "fmt/format.h"

// We use the scope operator ::
Personal::Personal() : Personal("", -1, 1800) {
    personalNumber = 0;
}

// Without the element initializer, 'name' would first be an empty string (every string is first initialized with "")
// and only then we would pass the actual param -> more efficient
// Only with an element initializer it is possible to "instantiate" a const variable
Personal::Personal(std::string name) : Personal(std::move(name), 0, 1800) {
}

// Personal::Personal(const char* name) : Personal(name, 0, 1800) {}

Personal::Personal(std::string name, unsigned int personalNumber) : Personal(std::move(name), personalNumber, 1800) {
}

Personal::Personal(std::string name, unsigned int personalNumber, unsigned int salary)
        : name(std::move(name)), personalNumber(personalNumber), salary(salary) {
}

// Copy constructor
Personal::Personal(const Personal& p) {
    name = p.name;
    personalNumber = p.personalNumber;
    salary = p.salary;
}

// Move constructor
Personal::Personal(Personal &&p) {
    name = std::move(p.name);
    personalNumber = p.personalNumber;
    p.personalNumber = 0;
    salary = p.salary;
    p.salary = 0;
}

Personal::~Personal() {
    // std::cout << "Deleted " << name << std::endl;
}

void Personal::initPersonal(std::string name, unsigned int personalNumber, unsigned int salary) {
    this->name = std::move(name);
    this->personalNumber = personalNumber;
    this->salary = salary;
}

Personal Personal::compareSalary(const Personal &p) const {
    if (getSalary() > p.getSalary()) {
        return *this;
    }
    return p;
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

std::string Personal::toString() {
    // return std::format("Personal[name={}, personalNumber={}, salary={}]", name, personalNumber, salary); // should work with C++20
    return fmt::format("Personal[name={}, personalNumber={}, salary={}]", name, personalNumber, salary);
}

void Personal::setName(const std::string &name) {
    if (name.empty()) {
        // throw some exception
        std::cout << "Name must not be empty!" << std::endl;
    }
    Personal::name = name;
}

void Personal::setPersonalNumber(unsigned int personalNumber) {
    Personal::personalNumber = personalNumber;
}

void Personal::setSalary(unsigned int salary) {
    Personal::salary = salary;
}
