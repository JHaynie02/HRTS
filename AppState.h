#ifndef APPSTATE_H
#define APPSTATE_H
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <time.h>
// #include <string>
// #include <chrono>
// #include <ctime>
using jsonf = nlohmann::json;

class AppState {
public:
    // virtual ~AppState(); 
    virtual void Handle() = 0;
};

#endif