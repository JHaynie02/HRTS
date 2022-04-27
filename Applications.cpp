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
    Applications application;
    application.Handle();
    while(true)
    {
        // creating a new application and setting the state to draft mode
        std::cout << "\n1) First and last name: ";
        std::string response;
        std::getline(std::cin, response);
        // Store name into data structure
        
        std::cout << "\n2) Email Address: ";
        std::getline(std::cin, response);

        std::cout << "\n3) Telephone Number: ";
        std::getline(std::cin, response);

        std::cout << "\n4) Address: ";
        std::getline(std::cin, response);

        std::cout << "\n5) City: ";
        std::getline(std::cin, response);
        
        std::cout << "\n6) State: ";
        std::getline(std::cin, response);

        std::cout << "\n7) Zip Code: ";
        std::getline(std::cin, response);

        std::cout << "\n8) Social Security Number: ";
        std::getline(std::cin, response);

        std::cout << "\n9) Desired Salary: ";
        std::getline(std::cin, response);

        std::cout << "\n10) Position Applied for: ";
        std::getline(std::cin, response);

        std::cout << "\n11) Are you a citizen of the United States? ";
        std::getline(std::cin, response);
        if(response == "no")
        {
            std::cout << "\n11) a) Are you authorized to work in the U.S.? ";
            std::getline(std::cin, response);
        }

        std::cout << "\n12) Have you ever been convicted of a felony? ";
        std::getline(std::cin, response);

        std::cout << "\n13) Did you graduate high school? ";
        std::getline(std::cin, response);
        if(response == "yes" || response == "Yes")
        {
            std::cout << "\n13) a) High School GPA: ";
            std::getline(std::cin, response);
        }

        std::cout << "\n14) Did you graduate from college?  ";
        std::getline(std::cin, response);
        if(response == "yes" || response == "Yes")
        {
            std::cout << "\n14) a) College GPA: ";
            std::getline(std::cin, response);
        }

        std::cout << "\n15) Do you have prior working experience? ";
        std::getline(std::cin, response);
        if(response == "yes" || response == "no")
        {
            std::cout << "\n15) a) Company Name: ";
            std::getline(std::cin, response);

            std::cout << "\n15) b) Phone Number: ";
            std::getline(std::cin, response);

            std::cout << "\n15) c) Position: ";
            std::getline(std::cin, response);
        }

        std::cout << "\nType 'submit' to submit or 'restart' to restart";
        std::cout << "\nWould you like to submit this application or restart? ";
        std::getline(std::cin, response);
        while(response != "submit" && response != "restart")
        {
            std::cout << "\nType 'submit' to submit or 'restart' to restart";
            std::cout << "\nWould you like to submit this application or restart? ";
            std::getline(std::cin, response);
        }
        if(response == "submit")
        {
            application.Handle();
            break;
        }
    }
    std::cout << "\nSuccessfully submitted\n";
}