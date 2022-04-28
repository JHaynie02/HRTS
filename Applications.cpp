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
            Applications application;
            jsonf jsonfileWrite;
            application.Handle();
            jsonfileWrite = application.newApplication();
            if(jsonfileWrite != nullptr)
            {
                application.Handle();
            }

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

jsonf Applications::newApplication()
{
    // Applications application;
    // application->Handle();
    jsonf jsonfileWrite;
    while(true)
    {
        // creating a new application and setting the state to draft mode
        std::cout << "\n1) First and last name: ";
        std::string response;
        std::getline(std::cin, response);
        jsonfileWrite["a) Name"] = response;
        std::cout << "\n2) Email Address: ";
        std::getline(std::cin, response);
        jsonfileWrite["b) Email Address"] = response;
        std::cout << "\n3) Phone Number: ";
        std::getline(std::cin, response);
        jsonfileWrite["c) Phone Number"] = response;
        std::cout << "\n4) Address, City, State, and Zip code: ";
        std::getline(std::cin, response);
        jsonfileWrite["d) Address"] = response;
        std::cout << "\n5) Social Security Number: ";
        std::getline(std::cin, response);
        jsonfileWrite["e) SSN"] = response;
        std::cout << "\n6) Desired Salary: ";
        std::getline(std::cin, response);
        jsonfileWrite["f) Desired Salary"] = response;
        std::cout << "\n7) Position Applied for: ";
        std::getline(std::cin, response);
        jsonfileWrite["g) Position Applied for"] = response;
        std::cout << "\n8) Are you a citizen of the United States? ";
        std::getline(std::cin, response);
        jsonfileWrite["h) Citizen"] = response;
        std::string responseCitizen;
        responseCitizen = response;
        if(responseCitizen == "no")
        {
            std::cout << "\n8) a) Are you authorized to work in the U.S.? ";
            std::getline(std::cin, responseCitizen);
            jsonfileWrite["h) i) Authorized to work in the U.S."] = responseCitizen;
        }
        std::cout << "\n9) Have you ever been convicted of a felony? ";
        std::getline(std::cin, response);
        jsonfileWrite["i) Felon"] = response;
        std::cout << "\n10) Did you graduate high school? ";
        std::getline(std::cin, response);
        jsonfileWrite["j) HS-Graduate"] = response;
        std::string responseSchool;
        responseSchool = response;
        if(responseSchool == "yes" || responseSchool == "Yes")
        {
            std::cout << "\n10) a) High School GPA: ";
            std::getline(std::cin, responseSchool);
            jsonfileWrite["j) i) HS-GPA"] = responseSchool;
        }
        std::cout << "\n11) Did you graduate from college?  ";
        std::getline(std::cin, response);
        responseSchool = response;
        jsonfileWrite["k) College Graduate"] = response;
        if(responseSchool == "yes" || responseSchool == "Yes")
        {
            std::cout << "\n11) a) College GPA: ";
            std::getline(std::cin, responseSchool);
            jsonfileWrite["k) i) College-GPA"] = responseSchool;
        }
        std::cout << "\n12) Do you have prior working experience? ";
        std::getline(std::cin, response);
        jsonfileWrite["l) Prior working experience"] = response;
        if(response == "yes" || response == "no")
        {
            std::cout << "\n12) a) Company Name: ";
            std::getline(std::cin, response);
            jsonfileWrite["l) i) Company Name"] = response;
            std::cout << "\n12) b) Company Phone: ";
            std::getline(std::cin, response);
            jsonfileWrite["l) ii) Company Phone"] = response;
            std::cout << "\n12) c) Position Held: ";
            std::getline(std::cin, response);
            jsonfileWrite["l) iii) Position Held"] = response;
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
            // application.Handle();
            // std::cout << std::setw(3) << jsonfileWrite;
            std::cout << jsonfileWrite.dump(4);
            std::string filePath = "pretty.json";
            std::ofstream file(filePath);
            file << std::setw(3) << jsonfileWrite;
            file << std::setw(3) << jsonfileWrite;
            file.close();
            return jsonfileWrite;
        }
    }
    // std::cout << "\nSuccessfully submitted\n";
}