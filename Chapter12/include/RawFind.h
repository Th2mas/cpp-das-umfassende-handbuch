//
// Created by tkhle on 20.07.2023.
//

#ifndef CHAPTER12_RAWFIND_H
#define CHAPTER12_RAWFIND_H

int* findPointer(int* begin, int* end, const int& val) {
    for (auto it = begin; it != end; it++) {
        if (*it == val) {
            return it;
        }
    }
    return end;
}

std::vector<int>::iterator findIterator(std::vector<int>& vec, const int& val) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (*it == val) {
            return it;
        }
    }
    return vec.end();
}

#endif //CHAPTER12_RAWFIND_H
