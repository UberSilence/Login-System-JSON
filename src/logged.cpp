#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "include/login.h"
#include "include/database.h"
#include "include/logged.h"

int logged(char* userLogin, char* userPassword) {
    int choice;
    std::cout << "\nWhat do you want to do next?\n1 - Check your account info\n2 - Reset the database\n3 - Exit\nChoice: ";
    std::cin >> choice;
    switch(choice) {
        case 1:
            std::cout << "\n************ACCOUNT DETAILS************\n* Username: " << userLogin << "\n* Password: " << userPassword << "\n* Register time: SOON\n***************************************";
            logged(userLogin, userPassword);
            break;
        case 2:
            reset();
            logged(userLogin, userPassword);
            break;
        case 3:
            return 0;
            break;
        default:
            std::cout << "Not an option.\n";
            logged(userLogin, userPassword);
            break;
    }
    return 0;
}

void reset() {
    std::ofstream inputFile("db.json");
    inputFile << "[]";
    inputFile.close();
}