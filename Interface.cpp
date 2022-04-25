#include "Interface.h"
#include "Applications.h"

Interface::Interface() {}

Interface::~Interface() {}

Interface& Interface::GetInstance()
{
    // creates static instance which is the same for the whole length of the program and return it
    static Interface instance;
    return instance;
}

void Interface::InterfaceControl()
{
    std::cout << "Hello and welcome to the Human Resource Tracking System.\n";
    std::cout << "\t- For help type 'help'\n";
    std::cout << "\t- If you are done type 'exit'\n";
    while(true)
    {
        // std::cout << "\nWhat do you want to do?\n\tEnter: ";
        std::cout << "\n- Main Terminal";
        std::cout << "\n\tEnter: ";
        std::string response;
        std::getline(std::cin, response);
        response = toLowerCase(response);
        // std::cout << response << "\n";
        if(response == "help" || response == "-h")
        {
            // std::cout << "Need to go to help function now\n";
            printHelp();
        }
        else if(response == "applications" || response == "-a")
        {
            // Add functionality
            Applications::ApplicationInterface();
        }
        else if(response == "employees" || response == "-e")
        {
            // Add functionality
        }
        else if(response == "exit" || response == "-q")
        {
            break;
        }
        else
        {
            std::cout << "What you entered was not recognised, for help type 'help'\n";
        }
    }
}

void Interface::printHelp()
{
    std::cout << "\nThe Human Resource Tracking System can do many things.\n";
    std::cout << "\t- To view and edit applications type 'applications'.\n";
    std::cout << "\t- To view and edit current employees and their information type 'employees'.\n";
    std::cout << "\t- To stop the program type 'exit'.\n";
}

std::string Interface::toLowerCase(std::string str)
{
    std::locale loc;
    for(std::string::size_type i = 0; i < str.length(); i++) // for loop to go through string and make every character lower case
    {
        str[i] = std::tolower(str[i],loc); // if character is already lower case nothing changes
    }
    return str;
}