//
// Created by tkhle on 18.08.2023.
//

#ifndef CHAPTER12_DATACLASS_H
#define CHAPTER12_DATACLASS_H

class DataClass {
    int data;
public:
    DataClass(int d = 0): data(d) {}

    int getData() const { return data; }

    bool operator==(const DataClass& other) const {
        return data == other.data;
    }

    /*
     * Alternatively you could write
        friend bool operator==(const DataClass& d1, const DataClass& d2) {
            return d1.data == d2.data;
        }
     */
};

#endif //CHAPTER12_DATACLASS_H
