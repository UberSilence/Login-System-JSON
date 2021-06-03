#include <iostream>
#include <iomanip>
#include <fstream>
#include "nlohmann/json.hpp"
#include "include/login.h"
#include "include/database.h"
#include "include/logged.h"

void newUser(char * userLogin, char * userPassword) {
    nlohmann::json j = {
        {
            { "login", userLogin },
            { "pass", userPassword }
        }
    };

    std::ifstream inputFile("db.json");
    nlohmann::json result = nlohmann::json::array();
    inputFile >> result;
    result.push_back(j);
    inputFile.close();

    std::ofstream file("db.json", std::ios_base::trunc | std::ios_base::out);
    file << std::setw(4) << result;
    file.close();

    std::cout << "\nSuccessfully registered!\n";
    login();
}

void checkUser(char* userLogin, char* userPassword, int attempts) {
    std::ifstream inputFile("db.json");
    nlohmann::json result = nlohmann::json::array();
    inputFile >> result;
    inputFile.close();

    // 🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉🎉 - inside joke
    for (const auto& obj : result) {

        if (obj[0].at("login") == userLogin && obj[0].at("pass") != userPassword && attempts >= 0) {
            if (attempts != 0) {
                std::cout << "\nWrong password. You have " << attempts << " attempts left.\n";
                passAgain(userLogin, attempts);
            } else {
                std::cout << "\nYou don't have any attempts left. Login failed.\n";
            }
        } else if (obj[0].at("login") == userLogin && obj[0].at("pass") == userPassword && attempts > 0) {
            std::cout << "\nSuccessfully logged in!";
            logged(userLogin, userPassword);
        }
    }
}

void passAgain (char* userLogin, int attempts) {
    attempts = attempts - 1;
    char userPassword[30];

    std::cout << "Password: ";
    std::cin >> userPassword;

    checkUser(userLogin, userPassword, attempts);
}