#include <iostream>
#include "include/login.h"

int main() {
    int choice;
    std::cout << "Do you have an account?\n1 - No\n2 - Yes\nChoice: ";
    std::cin >> choice; 
    switch(choice) {
        case 1:
            reg();
            break;
        case 2:
            login();
            break;
        default:
            std::cout << "Not an option.\n";
            break;
    }
    std::cout << "\nEnd of the program. Press ENTER to close.";
    std::cin.ignore(INT_MAX, '\n');
    std::cin.get();
    return 0;
}