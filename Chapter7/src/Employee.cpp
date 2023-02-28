//
// Created by tkhle on 28.02.2023.
//
#include "../include/Employee.h"

Employee::Employee(const char* company, const Personal& personal) {
    assignCompanyAndPersonal(company, personal);
}

Employee::~Employee() {
    delete[] company;
}

Employee::Employee(const Employee& employee): Employee(employee.company, employee.person) {
}

Employee& Employee::operator=(const Employee& employee) {
    if (this != &employee) {
        assignCompanyAndPersonal(employee.company, employee.person);
    }
    return *this;
}

void Employee::assignCompanyAndPersonal(const char* company, const Personal& personal) {
    Employee::company = new char[std::strlen(company) + 1];
    // Copy the passed pointer to the local 'company' property
    std::strcpy(Employee::company, company);

    // Manually copy the values
    person.setName(personal.getName());
    person.setPersonalNumber(personal.getPersonalNumber());
    person.setSalary(personal.getSalary());
}

char* Employee::getCompany() {
    return company;
}
