#ifndef APPDRAFT_H
#define APPDRAFT_H
#include "AppState.h"
#include "Applications.h"

class AppDraft : public AppState {
public:
    AppDraft(Applications* context);
    void Handle();

private:
    Applications* context_;
}

#endif