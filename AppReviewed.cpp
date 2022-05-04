#include "AppReviewed.h"

AppReviewed::AppReviewed(Applications* context) : context_(context) {}

void AppReviewed::HandleGood()
{
    std::cout << "Application has been reviewed\n";
}
