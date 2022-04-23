#ifndef APPLICATIONS_H
#define APPLICATIONS_H
#include <iostream>
#include "AppState.h"

class Applications {
public:
    Applications();
    // ~Applications();
    void setState(appState* state);
    void Handle();

private: 
    appState* state_;
}

#endif