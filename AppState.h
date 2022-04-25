#ifndef APPSTATE_H
#define APPSTATE_H
#include <iostream>

class AppState {
public:
    // virtual ~AppState(); 
    virtual void Handle() = 0;
};

#endif