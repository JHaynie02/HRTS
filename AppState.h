#ifndef APPSTATE_H
#define APPSTATE_H
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <time.h>

using jsonf = nlohmann::json;

class AppState {
public:
    virtual void HandleGood() = 0;
};

#endif