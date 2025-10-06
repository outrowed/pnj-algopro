#include <iostream>
#include <string>

int main() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    if (username == "admin" && password == "a1b2c3d4e5") {
        std::cout << "Access granted for admin.\n";
    }
    else if (username == "user" && password == "1a2b3c4d5e") {
        std::cout << "Access granted for user.\n";
    }
    else {
        std::cout << "Access denied.\n";
    }

    return 0;
}