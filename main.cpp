#include "Interface.h"
#include "Applications.h"

int main()
{
    // Interface &user = Interface::GetInstance();
    // user.InterfaceControl();

    // Applications applications;
    // applications.Handle();
    // applications.Handle();
    // applications.Handle();
    // applications.Handle();

    std::string filePath = "pretty.json";
    std::string response = "Jesse";
    jsonf jsonfileWrite;
    jsonfileWrite["Name"] = response;
    std::ofstream file(filePath);
    file << std::setw(3) << jsonfileWrite;
    // std::cout << jsonfileWrite;
    file.close();

    // std::string readInString;
    // jsonf jsonfileRead;
    std::ifstream fileRead(filePath, std::ios::in);
    std::cout << fileRead.rdbuf();
    // // jsonfileRead = jsonf::parse(fileRead);
    // // fileRead >> jsonfileRead;
    // // std::cout << jsonfileRead;
    // fileRead.close();

    return 0;
}