//
// Created by tkhle on 14.03.2023.
//

#ifndef CHAPTER8_DYNAMIC_H
#define CHAPTER8_DYNAMIC_H

class Dynamic {
    int* cPtr;
public:
    Dynamic(int n = 1);

    // Copy constructor
    Dynamic(const Dynamic& org);

    // Destructor
    ~Dynamic();

    // Assignment operator
    Dynamic& operator=(const Dynamic& rhs);

    int getCPtr() const;
};

#endif //CHAPTER8_DYNAMIC_H
