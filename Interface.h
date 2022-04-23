#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <string>
#include <locale>

class Interface {
public:
    // Accessor method that returns a reference
    // to the singleton instance of Interface class
    static Interface& GetInstance();

    // Class destructor
    ~Interface();

    // To prevent cloning
    Interface(Interface const &) = delete;
    Interface(Interface &&) = delete;

    // Non assignable
    void operator=(Interface const &) = delete;
    void operator=(Interface &&) = delete;

    // Interface functions
    void InterfaceControl();
    void printHelp();
    std::string toLowerCase(std::string str);

private:
    Interface();
};

#endif