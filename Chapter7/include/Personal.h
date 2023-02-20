#ifndef CHAPTER7_PERSONAL_H
#define CHAPTER7_PERSONAL_H

#include <string>

// All class members are per default private (not package-private, since it does not exist in C++!)
// The Big Three: If you ever need to write a copy-constructor, an assignment operator or a destructor, you should always
// write the other two as well

class Personal {
    std::string name;
    unsigned int personalNumber;
    unsigned int salary;
public:
    Personal();

    Personal(std::string name);

    Personal(std::string name, unsigned int personalNumber);

    Personal(std::string name, unsigned int personalNumber, unsigned int salary);

    /*
     * The compiler basically creates the following copy-constructor per default
    Personal(const Personal& p) {
        name = p.name;
        personalNumber = p.personalNumber;
        salary = p.salary;
    }
     */

    const std::string &getName() const;

    unsigned int getPersonalNumber() const;

    unsigned int getSalary() const;
};

#endif //CHAPTER7_PERSONAL_H
