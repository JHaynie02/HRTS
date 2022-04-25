#include "Interface.h"
#include "Applications.h"

int main()
{
    // Interface &user = Interface::GetInstance();
    // user.InterfaceControl();

    Applications applications;
    applications.Handle();
    applications.Handle();
    applications.Handle();
    applications.Handle();
    return 0;
}