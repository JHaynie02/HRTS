#include "Applications.h"
#include "AppDraft.h"
#include "Interface.h"


Applications::Applications()
{
    state_ = new AppDraft(this);
}

void Applications::setState(AppState* state)
{
    state_ = state;
}

void Applications::HandleGood()
{
    state_->HandleGood();
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
            bool applicationState = true;
            bool *applicationStatePtr;
            applicationStatePtr = &applicationState;
            jsonf jsonfileWrite;
            application.HandleGood();
            jsonfileWrite = application.newApplication(application, applicationStatePtr);
            if(applicationState == true)
            {
                std::cout << "Application will not be put on file for further review\n";
            }
            else
            {
                application.HandleGood();
            }
            application.checkSubmitted();
        }
        else if(response == "unreviewed applications" || response == "-ua")
        {
            Applications::printSubmitted();
            bool applicant;
            std::cout << "\nTo hire or remove an applicant type their full name.";
            std::cout << "\n\tEnter: ";
            std::string response;
            std::getline(std::cin, response);
            std::cout << "\nTo hire this applicant type 'hire' or to remove the type 'remove'.";
            std::cout << "\n\tEnter: ";
            std::string responseBool;
            std::getline(std::cin, responseBool);
            if(responseBool == "remove")
            {
                applicant = false;
            }
            else if(responseBool == "hire")
            {
                applicant = true;
            }
            response = Interface::toLowerCase(response);
            Applications::findSubmitted(applicant, response);
        }
        else if(response == "reviewed applications" || response == "-ra")
        {
            Applications::printReviewed();
        }
        else if(response == "back" || response  == "-b")
        {
            break;
        }
    }
}

void Applications::ApplicationPrintHelp()
{
    std::cout << "\t- To fill out a new application type 'new application' or '-na'\n";
    std::cout << "\t- To view information about submitted but unreviewed applications type 'unreviewed applications' or '-ua'\n";
    std::cout << "\t- To view information on reviewed applications type 'reviewed applications' or '-ra'\n";
}

jsonf Applications::newApplication(Applications app, bool *applicationStatePtr)
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
            *applicationStatePtr = app.filterSubmission(jsonfileWrite);
            return jsonfileWrite;
        }
    }
}

void Applications::toJsonHistory(jsonf jsonApp)
{
    // Gets amount of applications on file
    int count = 0;
    std::ifstream fileCount("AppHistoryCount.txt");
    // fileCount >> Applications::AppHistCount_;
    fileCount >> count;
    fileCount.close();

    std::string filePath = "ApplicationHistory.json";
    std::ifstream fileRead(filePath);
    jsonf jsonfileRead;

    std::string filePathCopy = "ApplicationHistoryCopy.json";
    std::ofstream fileWriteCopy(filePathCopy);

    for(int i = 0; i < count; i++)
    {
        fileRead >> jsonfileRead;
        fileWriteCopy << std::setw(3) << jsonfileRead;
    }
    fileRead.close();
    fileWriteCopy.close();

    std::ifstream fileReadCopy(filePathCopy);
    std::ofstream fileWrite(filePath);
    for(int i = 0; i < count; i++)
    {
            fileReadCopy >> jsonfileRead;
            fileWrite << std::setw(3) << jsonfileRead;
    }
    fileWrite << std::setw(3) << jsonApp;
    count++;

    std::ofstream fileCountChange("AppHistoryCount.txt");
    fileCountChange << count;

    remove("ApplicationHistoryCopy.json");
    fileCountChange.close();
    fileReadCopy.close();
    fileWrite.close();
}

void Applications::toJsonSubmitted(jsonf jsonApp)
{
    int count = 0;
    std::ifstream fileCount("AppSubmittedCount.txt");
    // fileCount >> Applications::AppHistCount_;
    fileCount >> count;
    // std::cout << "Count: " << count << "\n";
    fileCount.close();

    std::string filePath = "ApplicationSubmitted.json";
    std::ifstream fileRead(filePath);
    jsonf jsonfileRead;

    std::string filePathCopy = "ApplicationSubmittedCopy.json";
    std::ofstream fileWriteCopy(filePathCopy);

    for(int i = 0; i < count; i++)
    {
        fileRead >> jsonfileRead;
        fileWriteCopy << std::setw(3) << jsonfileRead;
    }
    fileRead.close();
    fileWriteCopy.close();

    std::ifstream fileReadCopy(filePathCopy);
    std::ofstream fileWrite(filePath);
    for(int i = 0; i < count; i++)
    {
            fileReadCopy >> jsonfileRead;
            fileWrite << std::setw(3) << jsonfileRead;
    }
    fileWrite << std::setw(3) << jsonApp;
    count++;

    std::ofstream fileCountChange("AppSubmittedCount.txt");
    fileCountChange << count;

    remove("ApplicationSubmittedCopy.json");
    fileCountChange.close();
    fileReadCopy.close();
    fileWrite.close();
}

void Applications::checkSubmitted()
{
     int count = 0;
    std::ifstream fileCount("AppHistoryCount.txt");
    // fileCount >> Applications::AppHistCount_;
    fileCount >> count;
    fileCount.close();
    if(count != 0)
    {
        std::cout << "\nYou have unreviewed applications, would you like to review them?\n";
        std::cout << "Type 'unreviewed applications' or '-ua' to review submitted applications\n";
    }
    else
    {
        std::cout << "No oustanding applications to be reviewed\n";
    }
}

bool Applications::filterSubmission(jsonf jsonfileRead)
{
    bool application = false;
    
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
                // std::cout << "Applicant is a felon\n";
                application = true;
            }
        }
        else if(item.key() == "K) HS-Graduate")
        {
            if(Interface::toLowerCase(item.value()) != "yes")
            {
                // std::cout << "Applicant is not a high school graduate\n";
                application = true;
            }
        }
        else if(item.key() == "M) Prior working experience")
        {
            if(Interface::toLowerCase(item.value()) != "yes")
            {
                // std::cout << "Applicant has no prior working experince\n";
                application = true;
            }
        }
    }
    if(application == true)
    {
        std::cout << "Application was not submitted for further review because basic standards for this job were not met.\n";
        return application;
    }
    else if(application == false)
    {
        std::cout << "Application being submitted\n";
        Applications::toJsonSubmitted(jsonfileRead);
        return application;
    }
    return true;
}

void Applications::printSubmitted()
{
    int count = 0;
    std::ifstream readSubCount("AppSubmittedCount.txt");
    readSubCount >> count;
    readSubCount.close();
    
    std::ifstream readFile("ApplicationSubmitted.json");
    jsonf jsonReadFile;
    for(int i = 0; i < count; i++)
    {
        readFile >> jsonReadFile;
        std::cout << jsonReadFile.dump(3) << "\n";
    }
    readFile.close();
}

void Applications::printReviewed()
{
    int count = 0;
    std::ifstream readSubCount("AppReviewedCount.txt");
    readSubCount >> count;
    readSubCount.close();
    
    std::ifstream readFile("ApplicationReviewed.json");
    jsonf jsonReadFile;
    for(int i = 0; i < count; i++)
    {
        readFile >> jsonReadFile;
        std::cout << jsonReadFile.dump(3) << "\n";
    }
    readFile.close();
}

void Applications::findSubmitted(bool applicant, std::string nameToRemove)
{
    int count = 0;
    std::ifstream readSubCount("AppSubmittedCount.txt");
    readSubCount >> count;
    // std::cout << count << "\n";
    readSubCount.close();
    if(count > 0)
    {
        std::ifstream readFile("ApplicationSubmitted.json");
        jsonf jsonfileRead;
        for(int i = 0; i < count; i++)
        {
            readFile >> jsonfileRead;
            for (const auto& item : jsonfileRead.items())
            {
                // std::cout << item.key();    
                // std::cout << " : " << item.value() << "\n";
                if(item.key() == "B) Name")
                {
                    if(Interface::toLowerCase(item.value()) == Interface::toLowerCase(nameToRemove))
                    {
                        // std::cout << "count: " << i << "\n";
                        Applications::removeSubmitted(applicant, i);
                    }
                }
            }
        }
        readFile.close();
    }
}

void Applications::removeSubmitted(bool applicant, int position)
{
    int count = 0;
    std::ifstream readSubCount("AppSubmittedCount.txt");
    readSubCount >> count;
    // std::cout << count << "\n";
    readSubCount.close();
    std::ifstream readFile("ApplicationSubmitted.json");
    jsonf jsonfileRemove;
    readFile >> jsonfileRemove;
    for(int i = 0; i < position; i++)
    {
        readFile >> jsonfileRemove;
    }
    // std::cout << jsonfileRemove.dump(3) << "\n";
    readFile.close();

    std::string filePath = "ApplicationSubmitted.json";
    std::ifstream fileRead(filePath);
    jsonf jsonfileRead;

    std::string filePathCopy = "ApplicationSubmittedCopy.json";
    std::ofstream fileWriteCopy(filePathCopy);

    for(int i = 0; i < count; i++)
    {
        fileRead >> jsonfileRead;
        if(jsonfileRead == jsonfileRemove)
        {
            // std::cout << "Copy found\n";
            if(applicant == true)
            {
                Applications::toJsonReviewed(jsonfileRead);
            }
        }
        else
        {
            fileWriteCopy << std::setw(3) << jsonfileRead;
        }
    }
    fileRead.close();
    fileWriteCopy.close();

    std::ifstream fileReadCopy(filePathCopy);
    std::ofstream fileWrite(filePath);
    for(int i = 0; i < count - 1; i++)
    {
            fileReadCopy >> jsonfileRead;
            fileWrite << std::setw(3) << jsonfileRead;
    }
    count--;

    std::ofstream fileCountChange("AppSubmittedCount.txt");
    fileCountChange << count;

    remove("ApplicationSubmittedCopy.json");
    fileCountChange.close();
    fileReadCopy.close();
    fileWrite.close();

}

void Applications::toJsonReviewed(jsonf jsonApp)
{
    int count = 0;
    std::ifstream fileCount("AppReviewedCount.txt");
    // fileCount >> Applications::AppHistCount_;
    fileCount >> count;
    fileCount.close();

    std::string filePath = "ApplicationReviewed.json";
    std::ifstream fileRead(filePath);
    jsonf jsonfileRead;

    std::string filePathCopy = "ApplicationReviewedCopy.json";
    std::ofstream fileWriteCopy(filePathCopy);

    for(int i = 0; i < count; i++)
    {
        fileRead >> jsonfileRead;
        fileWriteCopy << std::setw(3) << jsonfileRead;
    }
    fileRead.close();
    fileWriteCopy.close();

    std::ifstream fileReadCopy(filePathCopy);
    std::ofstream fileWrite(filePath);
    for(int i = 0; i < count; i++)
    {
            fileReadCopy >> jsonfileRead;
            fileWrite << std::setw(3) << jsonfileRead;
    }
    fileWrite << std::setw(3) << jsonApp;
    count++;

    std::ofstream fileCountChange("AppReviewedCount.txt");
    fileCountChange << count;

    remove("ApplicationReviewedCopy.json");
    fileCountChange.close();
    fileReadCopy.close();
    fileWrite.close();
}