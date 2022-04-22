#include "Interface.h"

int main()
{
    Interface &user = Interface::GetInstance();
    user.InterfaceControl();
    return 0;
}