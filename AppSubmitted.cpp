#include "AppSubmitted.h"
#include "AppReviewed.h"

AppSubmitted::AppSubmitted(Applications* context) : context_(context) {}

void AppSubmitted::Handle()
{
    std::cout << "\nApplication submitted\n";
    context_->setState(new AppReviewed(context_));
}