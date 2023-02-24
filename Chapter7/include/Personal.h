#ifndef CHAPTER7_PERSONAL_H
#define CHAPTER7_PERSONAL_H

#include <string>

// All class members are per default private (not package-private, since it does not exist in C++!)
// The Big Three: If you ever need to write a copy-constructor, an assignment operator or a destructor, you should always
// write the other two as well

static const unsigned int GG = 1900;

struct PersonalStruct {
    int publicInt;
private:
    int privateInt;
};

class Personal {
    std::string name;
    unsigned int personalNumber;
    unsigned int salary;
public:
    Personal();

    Personal(std::string name);
    // explicit Personal(std::string name);

    // Personal(const char* name);  // if we want to convert our argument to another type, we might create a conversion constructor (in this case not needed, C strings are also valid C++ strings)

    Personal(std::string name, unsigned int personalNumber);

    Personal(std::string name, unsigned int personalNumber, unsigned int salary);

    // The destructor is usually not called manually, but implicitly (either by calling "delete" or leaving the scope)
    ~Personal();

    /*
    // The compiler basically creates the following copy-constructor per default
    // If the parameter is marked with "const Personal&", this means that we have a reference to a const/immutable Personal
    Personal(const Personal& p) {
        name = p.name;
        personalNumber = p.personalNumber;
        salary = p.salary;
    }
     */

    /*
    // In a move constructor, the parameter must not be const! We need to "take away" the arguments data,
    // so that it doesn't contain any (or only partially) data
    // The compiler basically creates the following move-constructor per default
    Personal(Personal &&p) {
        name = p.name;
        p.name = "";
        // rest (the primitive data types) are omitted -> we might opt for our own implementation!
    }
    // If we write our own move-constructor, we might delete the option for a copy-constructor!
    Personal(const Personal &p) = delete;
     */
    void initPersonal(std::string name = "", unsigned int personalNumber = 0, unsigned int salary = GG);

    const std::string &getName() const;

    unsigned int getPersonalNumber() const;

    unsigned int getSalary() const;
};

#endif //CHAPTER7_PERSONAL_H
