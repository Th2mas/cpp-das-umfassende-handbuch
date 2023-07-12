//
// Created by tkhle on 12.07.2023.
//

#ifndef CHAPTER10_DIVISIONBYZEROERROR_H
#define CHAPTER10_DIVISIONBYZEROERROR_H

#include <string>
#include <vector>

class DivisionByZeroError {
    std::vector<std::string> msg;
    int err_code;
public:
    enum class Err {
        DIV0 = 0,
        INP1,
        INP2
    };

    DivisionByZeroError(const Err err): err_code(static_cast<int>(err)) {
        msg.emplace_back("Division by zero");
        msg.emplace_back("Entered dividend");
        msg.emplace_back("Entered divisor");
    }

    const std::string& what() {
        return msg.at(err_code);
    }
};

#endif //CHAPTER10_DIVISIONBYZEROERROR_H
