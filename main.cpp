#include "Interface.h"
#include "Applications.h"

int main()
{
    Interface &user = Interface::GetInstance();
    user.InterfaceControl();

    // Applications applications;
    // applications.Handle();
    // applications.Handle();
    // applications.Handle();
    // applications.Handle();

    // std::string filePath = "pretty.json";
    // std::string response = "Jesse";
    // jsonf jsonfileWrite;
    // time_t timeToday;
    // time(&timeToday);
    // // jsonfileWrite["Time"] = asctime(localtime(&timeToday));
    // jsonfileWrite["Name"] = response;
    // response = asctime(localtime(&timeToday));
    // std::cout << response;
    // response.erase(std::remove(response.begin(), response.end(), '\n'), response.end());
    // jsonfileWrite["Time"] = response;
    // // jsonfileWrite["Time"] = asctime(localtime(&timeToday));
    // std::ofstream file(filePath);
    // file << std::setw(3) << jsonfileWrite;
    // // file << jsonfileWrite;
    // std::cout << std::setw(3) << jsonfileWrite;
    // file.close();

    // // // std::string readInString;
    // // jsonf jsonfileRead;
    // std::ifstream fileRead(filePath, std::ios::in);
    // std::cout << fileRead.rdbuf();
    // jsonfileRead = jsonf::parse(fileRead);
    // // // fileRead >> jsonfileRead;
    // std::cout << jsonfileRead;
    // // fileRead.close();

    return 0;
}