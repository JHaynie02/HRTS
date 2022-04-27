#include "AppDraft.h"
#include "AppSubmitted.h"

// AppDraft Constructor with initialization list setting context to context_
AppDraft::AppDraft(Applications* context) : context_(context) {};

// Handle function to change application from draft to finished
void AppDraft::Handle()
{
    std::cout << "\nApplication now in draft mode\n";
    context_->setState(new AppSubmitted(context_));
}