//
// Created by tkhle on 01.03.2023.
//

#ifndef CHAPTER7_WINDOW_H
#define CHAPTER7_WINDOW_H

// The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time
// The values are then already available at compile time
// A constexpr variable immediately needs to have a value assigned
// If there is a constexpr constructor, properties must be assigned immediately (we can only use literals or constexpr variables, no objects)
// If a method is declared as constexpr, it must not be virtual. The return value and the parameters have to be literals
// If we use a constexpr ctor, the class must not have any virtual base classes

constexpr unsigned int MAX_X = 2550;
constexpr unsigned int MAX_Y = 1880;

constexpr unsigned int check_size_x(unsigned int s) {
    return s < MAX_X ? s : MAX_X;
}

constexpr unsigned int check_size_y(unsigned int s) {
    return s < MAX_Y ? s : MAX_Y;
}

class Window {
    unsigned int sizeX;
    unsigned int sizeY;
    // std::string name = "test";   // this would not work, since it is not trivial
public:
    constexpr Window(unsigned int x, unsigned int y) : sizeX(check_size_x(x)), sizeY(check_size_y(y)) {}

    // const at the end is necessary with constexpr!
    constexpr unsigned int getPixelSize() const {
        return check_size_x(sizeX) * check_size_y(sizeY);
    }

    constexpr unsigned int getSizeX() const {
        return sizeX;
    }

    constexpr unsigned int getSizeY() const {
        return sizeY;
    }
};

#endif //CHAPTER7_WINDOW_H
