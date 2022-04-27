#ifndef APPLICATIONS_H
#define APPLICATIONS_H
#include "AppState.h"

class Applications {
public:

    // State design
    Applications();
    void setState(AppState* state);
    void Handle();

    static void ApplicationInterface();
    static void ApplicationPrintHelp();
    static void newApplication();
    // void toJson();

private:
    // std::string
    AppState* state_;
};

#endif