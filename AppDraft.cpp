#include "AppDraft.h"

AppDraft::AppDraft(Applications* context): context_(context) {};

void Applications::Handle()
{
    std::cout << "Application in draft mode\n";
    context_->setState(new AppFinished(context_));
}