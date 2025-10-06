#include <iostream>

int main() {
    int number = 1;

    while (number <= 100) {
        if (number % 2 == 0) {
            std::cout << number << " is even.\n";
        }
        else {
            std::cout << number << " is odd.\n";
        }
        number++;
    }

    return 0;
}