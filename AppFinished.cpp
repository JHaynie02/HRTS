#include "AppFinished.h"
#include "AppSubmitted.h"

AppFinished::AppFinished(Applications* context) : context_(context) {};

void AppFinished::Handle()
{
    std::cout << "Application finished\n";
    context_->setState(new AppSubmitted(context_));
}