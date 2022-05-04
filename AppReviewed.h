#ifndef APPREVIEWED_H
#define APPREVIEWED_H
#include "AppState.h"
#include "Applications.h"

class AppReviewed : public AppState {
public:
    AppReviewed(Applications* context);
    void HandleGood();

private:
    Applications* context_;
};

#endif