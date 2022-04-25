#include "AppDraft.h"
#include "AppFinished.h"

AppDraft::AppDraft(Applications* context) : context_(context) {};

void AppDraft::Handle()
{
    std::cout << "Application in draft mode\n";
    context_->setState(new AppFinished(context_));
}