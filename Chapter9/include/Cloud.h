//
// Created by tkhle on 27.05.2023.
//

#ifndef CHAPTER9_CLOUD_H
#define CHAPTER9_CLOUD_H

// Pure interface classes are abstract classes that don't have any properties and only contain pure virtual methods
class Cloud {
public:
    virtual void read() = 0;
    virtual void write() = 0;
    virtual void error() = 0;

    // Info: If a class has at least one virtual method, one should also define a virtual destructor!
    virtual ~Cloud() = 0;
};

#endif //CHAPTER9_CLOUD_H
