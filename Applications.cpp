#include "Applications.h"
#include "AppDraft.h"
#include "Interface.h"

int Applications::AppHistCount_;
int Applications::AppSubmittedCount_;

Applications::Applications()
{
    state_ = new AppDraft(this);
}

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
            jsonfileWrite = application.newApplication(application);
            if(jsonfileWrite != nullptr)
            {
                application.Handle();
            }
            // application.checkSubmitted();
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

jsonf Applications::newApplication(Applications app)
{
    jsonf jsonfileWrite;
    while(true)
    {
        // creating a new application and setting the state to draft mode
        std::string response;
        time_t timeToday;
        struct tm* timeinfo;
        time(&timeToday);
        timeinfo = localtime(&timeToday);
        response = asctime(timeinfo);
        response.pop_back();
        jsonfileWrite["A) Time"] = response;
        std::cout << "\n1) First and last name: ";
        std::getline(std::cin, response);
        jsonfileWrite["B) Name"] = response;
        std::cout << "\n2) Email Address: ";
        std::getline(std::cin, response);
        jsonfileWrite["C) Email Address"] = response;
        std::cout << "\n3) Phone Number: ";
        std::getline(std::cin, response);
        jsonfileWrite["D) Phone Number"] = response;
        std::cout << "\n4) Address, City, State, and Zip code: ";
        std::getline(std::cin, response);
        jsonfileWrite["E) Address"] = response;
        std::cout << "\n5) Social Security Number: ";
        std::getline(std::cin, response);
        jsonfileWrite["F) SSN"] = response;
        std::cout << "\n6) Desired Salary: ";
        std::getline(std::cin, response);
        jsonfileWrite["G) Desired Salary"] = response;
        std::cout << "\n7) Position Applied for: ";
        std::getline(std::cin, response);
        jsonfileWrite["H) Position Applied for"] = response;
        std::cout << "\n8) Are you a citizen of the United States? ";
        std::getline(std::cin, response);
        jsonfileWrite["I) Citizen"] = response;
        std::string responseCitizen;
        responseCitizen = response;
        if(responseCitizen == "no")
        {
            std::cout << "\n8) a) Are you authorized to work in the U.S.? ";
            std::getline(std::cin, responseCitizen);
            jsonfileWrite["I) i) Authorized to work in the U.S."] = responseCitizen;
        }
        std::cout << "\n9) Have you ever been convicted of a felony? ";
        std::getline(std::cin, response);
        jsonfileWrite["J) Felon"] = response;
        std::cout << "\n10) Did you graduate high school? ";
        std::getline(std::cin, response);
        jsonfileWrite["K) HS-Graduate"] = response;
        std::string responseSchool;
        responseSchool = response;
        if(responseSchool == "yes" || responseSchool == "Yes")
        {
            std::cout << "\n10) a) High School GPA: ";
            std::getline(std::cin, responseSchool);
            jsonfileWrite["K) i) HS-GPA"] = responseSchool;
        }
        std::cout << "\n11) Did you graduate from college?  ";
        std::getline(std::cin, response);
        responseSchool = response;
        jsonfileWrite["L) College Graduate"] = response;
        if(responseSchool == "yes" || responseSchool == "Yes")
        {
            std::cout << "\n11) a) College GPA: ";
            std::getline(std::cin, responseSchool);
            jsonfileWrite["L) i) College-GPA"] = responseSchool;
        }
        std::cout << "\n12) Do you have prior working experience? ";
        std::getline(std::cin, response);
        jsonfileWrite["M) Prior working experience"] = response;
        if(response == "yes" || response == "Yes")
        {
            std::cout << "\n12) a) Company Name: ";
            std::getline(std::cin, response);
            jsonfileWrite["M) i) Company Name"] = response;
            std::cout << "\n12) b) Company Phone: ";
            std::getline(std::cin, response);
            jsonfileWrite["M) ii) Company Phone"] = response;
            std::cout << "\n12) c) Position Held: ";
            std::getline(std::cin, response);
            jsonfileWrite["M) iii) Position Held"] = response;
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
            // std::cout << jsonfileWrite.dump(4) << "\n";
            // std::string filePath = "ApplicationHistory.json";
            // std::ofstream file(filePath);
            // file << std::setw(3) << jsonfileWrite;
            // file.close();


            
            // app.toJsonSubmitted(jsonfileWrite);
            app.filterSubmission();
            
            
            return jsonfileWrite;
        }
    }
}

void Applications::toJsonHistory(jsonf jsonApp)
{
    // Gets amount of applications on file
    std::ifstream fileCount("AppHistoryCount.txt");
    fileCount >> Applications::AppHistCount_;
    fileCount.close();

    std::string filePath = "ApplicationHistory.json";
    std::ifstream fileRead(filePath);
    jsonf jsonfileRead;

    std::string filePathCopy = "ApplicationHistoryCopy.json";
    std::ofstream fileWriteCopy(filePathCopy);

    for(int i = 0; i < Applications::AppHistCount_; i++)
    {
        fileRead >> jsonfileRead;
        fileWriteCopy << std::setw(3) << jsonfileRead;
    }
    fileRead.close();
    fileWriteCopy.close();

    std::ifstream fileReadCopy(filePathCopy);
    std::ofstream fileWrite(filePath);
    for(int i = 0; i < Applications::AppHistCount_; i++)
    {
            fileReadCopy >> jsonfileRead;
            fileWrite << std::setw(3) << jsonfileRead;
    }
    fileWrite << std::setw(3) << jsonApp;
    Applications::AppHistCount_++;

    std::ofstream fileCountChange("AppHistoryCount.txt");
    fileCountChange << Applications::AppHistCount_;

    remove("ApplicationHistoryCopy.json");
    fileCountChange.close();
    fileReadCopy.close();
    fileWrite.close();
}

void Applications::toJsonSubmitted(jsonf jsonApp)
{
    std::ifstream fileCount("AppSubmittedCount.txt");
    fileCount >> Applications::AppSubmittedCount_;
    fileCount.close();

    std::string filePath = "ApplicationSubmitted.json";
    std::ifstream fileRead(filePath);
    jsonf jsonfileRead;

    std::string filePathCopy = "ApplicationSubmittedCopy.json";
    std::ofstream fileWriteCopy(filePathCopy);

    for(int i = 0; i < Applications::AppSubmittedCount_; i++)
    {
        fileRead >> jsonfileRead;
        fileWriteCopy << std::setw(3) << jsonfileRead;
    }
    fileRead.close();
    fileWriteCopy.close();

    std::ifstream fileReadCopy(filePathCopy);
    std::ofstream fileWrite(filePath);
    for(int i = 0; i < Applications::AppSubmittedCount_; i++)
    {
            fileReadCopy >> jsonfileRead;
            fileWrite << std::setw(3) << jsonfileRead;
    }
    fileWrite << std::setw(3) << jsonApp;
    Applications::AppSubmittedCount_++;

    std::ofstream fileCountChange("AppSubmittedCount.txt");
    fileCountChange << Applications::AppSubmittedCount_;

    remove("ApplicationSubmittedCopy.json");
    fileCountChange.close();
    fileReadCopy.close();
    fileWrite.close();
}

void Applications::checkSubmitted()
{
    if(Applications::AppSubmittedCount_ != 0)
    {
        std::cout << "\nYou have unreviewed applications, would you like to review them?\n";
    }
    else
    {
        
    }
}

void Applications::filterSubmission()
{
    bool application = false;
    jsonf jsonFilter;
    std::string filePath = "ApplicationSubmitted.json";
    std::ifstream fileRead(filePath);
    jsonf jsonfileRead;

    fileRead >> jsonfileRead;

    std::cout << "Application Being Reviewed:\n" << jsonfileRead.dump(3) << "\n";
    
    for (const auto& item : jsonfileRead.items())
    {
        // std::cout << item.key();    
        // std::cout << " : " << item.value() << "\n";
        if(item.key() == "I) Citizen")
        {
            if(Interface::toLowerCase(item.value()) != "yes")
            {
                // std::cout << "Applicant is not a citizen\n";
                application = true;
            }
        }
        else if(item.key() == "J) Felon")
        {
            if(Interface::toLowerCase(item.value()) == "yes")
            {
                std::cout << "Applicant is a felon\n";
                application = true;
            }
        }
        else if(item.key() == "K) HS-Graduate")
        {
            if(Interface::toLowerCase(item.value()) != "yes")
            {
                std::cout << "Applicant is not a high school graduate\n";
                application = true;
            }
        }
        else if(item.key() == "M) Prior working experience")
        {
            if(Interface::toLowerCase(item.value()) != "yes")
            {
                std::cout << "Applicant has no prior working experince\n";
                application = true;
            }
        }
    }
    if(application == true)
    {
        std::cout << "Application was not submitted for further review because basic standards for this job where not met.\n";
    }
    else if(application == false)
    {
        Applications::toJsonSubmitted(jsonfileRead);
    }
}