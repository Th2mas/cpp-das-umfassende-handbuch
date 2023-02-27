#include "../include/OS.h"

//
// Created by tkhle on 27.02.2023.
//

void OS::setOS(OSType t) {
    type = t;
}

// The following line requires the additional scope of OS to resolve the return type
// OS::OSType OS::getOS() const { return type; }
// It is easier to do the following
auto OS::getOS() const -> OSType {
    return type;
}

OS::OS(const unsigned int id) : ID(id) {
    // We don't have to do anything here!
    // It is not possible to do `ID = id;` here!
}

auto OS::getID() const -> unsigned int {
    return ID;
}
