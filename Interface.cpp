#include "Interface.h"

Interface::Interface() {}

Interface::~Interface() {}

Interface& Interface::GetInstance()
{
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
        std::cout << "Enter: ";
        std::string response;
        std::getline(std::cin, response);
        response = toLowerCase(response);
        // std::cout << response << "\n";
        if(response == "help")
        {
            // std::cout << "Need to go to help function now\n";
            printHelp();
        }
        else if(response == "applications")
        {
            // Add functionality
        }
        else if(response == "employees")
        {
            // Add functionality
        }
        else if(response == "exit")
        {
            break;
        }
    }
}

void Interface::printHelp()
{
    std::cout << "\nThe Human Resource Tracking System can do many things.\n\n";
    std::cout << "\t- To view and edit applications type 'applications'.\n";
    std::cout << "\t- To view and edit current employees and their information type 'employees'.\n";
    std::cout << "\t- To stop the program type 'exit'.\n";
}

std::string Interface::toLowerCase(std::string str)
{
    std::locale loc;
    for(std::string::size_type i = 0; i < str.length(); i++)
    {
        str[i] = std::tolower(str[i],loc);
    }
    return str;
}