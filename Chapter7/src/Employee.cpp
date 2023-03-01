//
// Created by tkhle on 28.02.2023.
//
#include "../include/Employee.h"

// Why is this possible? employeeCount is private!
// Defining a static variable must happen outside the class, without the keyword "static" and almost the same as
// a regular variable (you need to prepend Employee::)
unsigned int Employee::employeeCount = 0;

Employee::Employee(const char* company, const Personal& personal) {
    assignCompanyAndPersonal(company, personal);
    employeeCount++;
}

Employee::~Employee() {
    delete[] company;
    employeeCount--;
}

Employee::Employee(const Employee& employee): Employee(employee.company, employee.person) {
}

Employee& Employee::operator=(const Employee& employee) {
    if (this != &employee) {
        assignCompanyAndPersonal(employee.company, employee.person);
    }
    return *this;
}

// Although we should store an object via the initializer list, we used this private method to extract some common code for visibility reasons
void Employee::assignCompanyAndPersonal(const char* company, const Personal& personal) {
    Employee::company = new char[std::strlen(company) + 1]; // We use +1, because we also need space for '\0'
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

// Note: We must not use the "static" keyword, when defining the static function
unsigned int Employee::getEmployeeCount() {
    return employeeCount;
}
