#ifndef APPFINISHED_H
#define APPFINISHED_H
#include "AppState.h"
#include "Applications.h"

class AppFinished : public AppState {
public:
    AppFinished(Applications* context);
    void Handle();

private:
    Applications* context_;
};

#endif