#ifndef CHAPTER7_PERSONAL_H
#define CHAPTER7_PERSONAL_H

#include <string>

// All class members are per default private (not package-private, since it does not exist in C++!)

class Personal {
    std::string name;
    unsigned int personalNumber{0};
    unsigned int salary{1800};
public:
    Personal() {}

    const std::string &getName() const {
        return name;
    }

    unsigned int getPersonalNumber() const {
        return personalNumber;
    }

    unsigned int getSalary() const {
        return salary;
    }
};

#endif //CHAPTER7_PERSONAL_H
