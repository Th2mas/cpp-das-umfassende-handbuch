//
// Created by tkhle on 11.04.2023.
//
#ifndef CHAPTER9_JPEGPICTUREFORMAT_H
#define CHAPTER9_JPEGPICTUREFORMAT_H

#include <iostream>
#include "PictureFormat.h"

class JpegPictureFormat : public PictureFormat {
    std::string info;
public:
    JpegPictureFormat(const std::string& filename = "", const std::string& info = ""): PictureFormat(filename), info(info) {}

    // the override keyword is optional
    // if we don't override this function, we get a runtime error
    void show_picture() const override {
        std::cout << "JpegPictureFormat[filename=" << getFileName() << ",info=" << info << "]" << std::endl;
    }

    const std::string &getInfo() const {
        return info;
    }

    void setInfo(const std::string &info) {
        JpegPictureFormat::info = info;
    }
};

#endif