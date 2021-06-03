#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "include/login.h"
#include "include/database.h"
#include "include/logged.h"

int login() {
    char userLogin[30];
    char userPassword[30];
    int attempts = 3;
    int choice;

    std::cout << "Username: ";
    std::cin >> userLogin;

    std::ifstream inputFile("db.json");
    nlohmann::json result = nlohmann::json::array();
    inputFile >> result;
    inputFile.close();

    bool accountExists = false;
    for (const auto& obj : result) {
	    if (obj[0].at("login") == userLogin) {
            accountExists = true;
        }
    }

    if (accountExists == false) {
        std::cout << "\nAccount doesn't exist. Do you want to create a new one?\n1 - Yes\n2 - Exit\nChoice: ";
            std::cin >> choice;
            switch(choice) {
                case 1:
                    std::cout << std::endl;
                    reg();
                    break;
                case 2:
                    return 0;
                    break;
                default:
                    std::cout << "Not an option.";
                    login();
                    break;
            }
    }

    std::cout << "Password: ";
    std::cin >> userPassword;

    checkUser(userLogin, userPassword, attempts);
    return 0;
}

void reg() {
    char userLogin[30];
    char userPassword[30];
    char userPasswordAgain[30];

    std::ifstream inputFile("db.json");
    nlohmann::json result = nlohmann::json::array();
    inputFile >> result;
    inputFile.close();

    std::cout << "\nEnter a new username: ";
    std::cin >> userLogin;
    
    // 🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉 - inside joke
    for (const auto& obj : result) {
        while (obj[0].at("login") == userLogin) {
            std::cout << "User already exists." << std::endl;
            reg();
        }
    }

    do {
    std::cout << "Enter a new password: ";
    std::cin >> userPassword;
    std::cout << "Enter your password again: ";
    std::cin >> userPasswordAgain;
    } while (strcmp(userPassword, userPasswordAgain) != 0);
    newUser(userLogin, userPassword);
}