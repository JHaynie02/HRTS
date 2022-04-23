#include "Applications.h"

Applications::Applications()
{
    state_ = new AppDraft(this);
}

void Applications::setState(AppState* state)
{
    state_ = state;
}

void Applications::Handle()
{
    state_->Handle();
}