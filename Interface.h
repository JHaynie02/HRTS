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

    // To prevent copying
    Interface(Interface const &) = delete;
    Interface(Interface &&) = delete;

    // To prevent moving
    void operator=(Interface const &) = delete;
    void operator=(Interface &&) = delete;

    // Interface functions
    void InterfaceControl();
    void printHelp(); // Print out help to user
    static std::string toLowerCase(std::string str); // takes string and turns into all lowercase

private:
    Interface(); // singleton constructor must be declared private
};

#endif