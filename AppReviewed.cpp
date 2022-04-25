// #include "AppSubmitted.h"
#include "AppReviewed.h"

AppReviewed::AppReviewed(Applications* context) : context_(context) {}

void AppReviewed::Handle()
{
    std::cout << "Application has been reviewed\n";
    // context_->setState(new AppReviewed(context_));
}