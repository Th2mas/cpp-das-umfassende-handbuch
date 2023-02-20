#ifndef CHAPTER7_PERSONAL_H
#define CHAPTER7_PERSONAL_H

#include <string>

// All class members are per default private (not package-private, since it does not exist in C++!)

class Personal {
    std::string name;
    unsigned int personalNumber;
    unsigned int salary;
public:
    Personal();

    Personal(std::string name);

    Personal(std::string name, unsigned int personalNumber);

    Personal(std::string name, unsigned int personalNumber, unsigned int salary);

    const std::string &getName() const;

    unsigned int getPersonalNumber() const;

    unsigned int getSalary() const;
};

#endif //CHAPTER7_PERSONAL_H
