//
// Created by tkhle on 11.04.2023.
//

#ifndef CHAPTER9_PICTUREFORMAT_H
#define CHAPTER9_PICTUREFORMAT_H

#include <string>

// A class with at least one pure virtual function is an abstract class -> we can not instantiate objects of type PictureFormat!
// There is no 'abstract' keyword in C++
class PictureFormat {
    std::string filename;
public:
    PictureFormat(const std::string &f = "") : filename(f) {}

    void setFileName(const std::string &f) {
        filename = f;
    }

    const std::string &getFileName() const {
        return filename;
    }

    // If we declare a pure virtual function, we have to define the behaviour in a sub-class!
    virtual void show_picture() const = 0;
};

#endif //CHAPTER9_PICTUREFORMAT_H
