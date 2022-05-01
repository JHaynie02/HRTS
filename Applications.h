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
    jsonf newApplication(Applications app);
    void toJsonHistory(jsonf jsonApp);
    void toJsonSubmitted(jsonf jsonApp);

private:
    AppState* state_;
    int AppHistCount_;
    int AppSubmittedCount_;
    // std::string name_;
    // std::string eAddress_;
    // std::string phoneNumber_;
    // std::string address_;
};

#endif