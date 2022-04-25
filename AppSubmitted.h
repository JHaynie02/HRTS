#ifndef APPSUBMITTED_H
#define APPSUBMITTED_H
#include "AppState.h"
#include "Applications.h"

class AppSubmitted : public AppState {
public:
    AppSubmitted(Applications* context);
    void Handle();

private:
    Applications* context_;
};

#endif