#include <iostream>
using std::cout;
using std::cin;

int main() {
    int i = 0;
    bool running = true;
    while (running) {
        cout << "DON'T enter the number " << i;
        int input;
        cin >> input;
        if (input == i) {
            cout << "I told you not to enter that!";
            running = false;
        }
        if (i == 10) {
            cout << "You beat me!";
            running = false;
        }
        i++;
    }
}