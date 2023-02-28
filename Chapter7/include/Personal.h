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
public:
    int publicInt2;
private:
    int privateInt2;
protected:
    int protectedInt;
};

// Class declaration: Class Clazz;
// Class definition: Class Clazz { };

class Personal {
    // Per default, everything is private
    std::string name;
    unsigned int personalNumber;
    unsigned int salary;
public:
    Personal();

    Personal(std::string name);

    // We use "explicit" to avoid the implicit conversion of the parameter (e.g. convert a C string to a C++ string)
    // explicit Personal(std::string name);

    // if we want to convert our argument to another type, we might create a conversion constructor
    // (in this case not needed, C strings are also valid C++ strings)
    // Personal(const char* name);

    Personal(std::string name, unsigned int personalNumber);

    Personal(std::string name, unsigned int personalNumber, unsigned int salary);

    // The destructor is usually not called manually, but implicitly (either by calling "delete" or leaving the scope)
    // Note: The destructor is also called when an exception occurs!
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
    Personal(const Personal& p);

    /*
    // In a move constructor, the parameter must not be const! We need to "take away" the argument's data,
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
    Personal(Personal &&p);

    void initPersonal(std::string name = "", unsigned int personalNumber = 0, unsigned int salary = GG);

    // "const" at the end of a method declaration tells us, that we are not modifying any values in the getter (only read-access)
    Personal compareSalary(const Personal &p) const;

    const std::string &getName() const;

    unsigned int getPersonalNumber() const;

    unsigned int getSalary() const;

    void setName(const std::string &name);

    void setPersonalNumber(unsigned int personalNumber);

    void setSalary(unsigned int salary);

    std::string toString();

    friend unsigned int multiplySalary(const Personal& p, unsigned int multiplier);
};

// Make multiplySalary a global function
unsigned int multiplySalary(const Personal& p, unsigned int multiplier);

#endif //CHAPTER7_PERSONAL_H
