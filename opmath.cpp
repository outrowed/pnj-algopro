#include <iostream>

using namespace std;

int main() {
    int x = 10;
    
    cout << (x <= 10) << "\n"; // true
    cout << (x > 10) << "\n"; // false
    cout << (x == 10) << "\n"; // true
    
    x -= 5;

    cout << (x >= 10) << "\n"; // false
    cout << (x < 10) << "\n"; // true
}