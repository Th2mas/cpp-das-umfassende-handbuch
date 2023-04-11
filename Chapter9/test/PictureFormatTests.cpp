//
// Created by tkhle on 11.04.2023.
//
#include <gtest/gtest.h>
#include "../include/PictureFormat.h"
#include "../include/JpegPictureFormat.h"

TEST(JpegPictureFormat, CallingShowPicturePrintsDataToConsole) {
    // Arrange
    JpegPictureFormat jpegPicture{"batman.jpeg", "Picture of batman"};

    // Act
    jpegPicture.show_picture();

    // No assert
}

TEST(PictureFormat, CallingShowPictureWithBaseClassPointer) {
    // Arrange
    PictureFormat *batmanPicture = new JpegPictureFormat("batman.jpeg", "Picture of batman");
    auto supermanPicture(new JpegPictureFormat("superman.jpeg", "Picture of superman"));

    // Act
    batmanPicture->show_picture();
    supermanPicture->show_picture();

    // No assert
}
