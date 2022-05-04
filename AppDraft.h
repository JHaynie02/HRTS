#ifndef APPDRAFT_H
#define APPDRAFT_H
#include <iostream>
#include <stdio.h>
#include "AppState.h"
#include "Applications.h"

class AppDraft : public AppState {
public:
    AppDraft(Applications* context);
    // ~AppDraft() {}
    void HandleGood();

private:
    Applications* context_;
};

#endif