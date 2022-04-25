#include "Applications.h"
#include "AppDraft.h"
#include "Interface.h"

Applications::Applications()
{
    state_ = new AppDraft(this);
}

// Applications::~Applications()
// {
//     if(state_)
//         delete state_;    
// }

void Applications::setState(AppState* state)
{
    state_ = state;
}

void Applications::Handle()
{
    state_->Handle();
}

void Applications::ApplicationInterface()
{
    std::cout << "\n- Application Inteface\n";
    std::cout << "\t- For help with application viewing and editing type 'help'\n";
    std::cout << "\t- If you want to go back to the home screen type 'back'\n";
    while(true)
    {
        std::cout << "\nEnter: ";
        std::string response;
        std::getline(std::cin, response);
        response = Interface::toLowerCase(response);
        std::cout << response << "\n";
        
    }
}