//
// Created by tkhle on 27.02.2023.
//

#ifndef CHAPTER7_OS_H
#define CHAPTER7_OS_H

class OS {
public:
    enum OSType { WIN, MAC, UNIX, LINUX };

    explicit OS(const unsigned int id);
    OS() = default;

    void setOS(OSType t);
    OSType getOS() const;
    unsigned int getID() const;
private:
    OSType type;
    const unsigned int ID;
};

#endif //CHAPTER7_OS_H
