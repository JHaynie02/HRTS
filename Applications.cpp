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
    std::cout << "\t- If you want to go back to the main terminal type 'back'\n";
    while(true)
    {
        std::cout << "\n- Application Terminal";
        std::cout << "\n\tEnter: ";
        std::string response;
        std::getline(std::cin, response);
        response = Interface::toLowerCase(response);
        // std::cout << response << "\n";
        if(response == "help" || response == "-h")
        {
            // std::cout << "Need to go to help function now\n";
            ApplicationPrintHelp();
        }
        else if(response == "new application" || response == "-na")
        {
            newApplication();
        }
        else if(response == "unreviewed applications" || response == "-ua")
        {
            
        }
        else if(response == "reviewed applications" || response == "-ra")
        {
            
        }
        else if(response == "back" || response  == "-b")
        {
            break;
        }
        else
        {
            
        }
    }
}

void Applications::ApplicationPrintHelp()
{
    std::cout << "\t- To fill out a new application type 'new application' or '-na'\n";
    std::cout << "\t- To view information about submitted but unreviewed applications type 'unreviewed applications' or '-ua'\n";
    std::cout << "\t- To view information on reviewed applications type 'reviewed applications' or '-ra'\n";
}

void Applications::newApplication()
{
    // creating a new application and setting the state to draft mode
    Applications application;
    application.Handle();
    std::cout << "\nFirst and last name: ";
    std::string response;
    std::getline(std::cin, response);
    // Store name into data structure
    // 

    // response = Interface::toLowerCase(response);
    // std::cout << response;
}