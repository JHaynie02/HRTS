#ifndef APPLICATIONS_H
#define APPLICATIONS_H
#include "AppState.h"

// https://github.com/JHaynie02/HRTS

class Applications {
public:

    // State design pattern
    Applications();
    ~Applications() {}
    void setState(AppState* state);
    void HandleGood();

    static void ApplicationInterface();
    static void ApplicationPrintHelp();
    static void printSubmitted();
    static void printReviewed();
    static void printHistory();
    static bool findSubmitted(bool applicant, std::string nameToRemove);
    static void removeSubmitted(bool applicant, int position);
    jsonf newApplication(Applications app, bool *applicationStatePtr);
    static void toJsonHistory(jsonf jsonApp);
    static void toJsonReviewed(jsonf jsonApp);
    static void toJsonSubmitted(jsonf jsonApp);
    void checkSubmitted();
    bool filterSubmission(jsonf jsonfileRead);

private:
    AppState* state_;
};

#endif