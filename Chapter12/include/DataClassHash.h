//
// Created by tkhle on 18.08.2023.
//

#ifndef CHAPTER12_DATACLASSHASH_H
#define CHAPTER12_DATACLASSHASH_H

#include <cstddef>
#include "DataClass.h"

class DataClassHash {
public:
    std::size_t operator()(const DataClass& d) const {
        return d.getData() % 7;
    }
};

#endif //CHAPTER12_DATACLASSHASH_H
