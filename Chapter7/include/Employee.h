//
// Created by tkhle on 28.02.2023.
//

#ifndef CHAPTER7_EMPLOYEE_H
#define CHAPTER7_EMPLOYEE_H

#include "Personal.h"

class Employee {
    // Using a char* (a pointer) might lead to some problems which we would not have with C++ pointers
    // (or simple strings in this case)
    char* company;
    Personal person;

    void assignCompanyAndPersonal(const char* company, const Personal& personal);
public:
    Employee(const char* company, const Personal& personal);
    ~Employee();

    // Since we added a destructor, we should also add a copy constructor and the assignment operator (Big Three!)
    Employee(const Employee& employee);
    Employee& operator=(const Employee& employee);

    char* getCompany();
};

#endif //CHAPTER7_EMPLOYEE_H
