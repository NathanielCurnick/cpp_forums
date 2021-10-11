#include <iostream>
#include <time.h>
using std::cin;
using std::cout;

int human_guessing() {
    srand(time(NULL));
    int goal = rand() % 100 + 1;
    int guess;
    do {
        cout << "Guess the number (1 to 100) \n";
        
        cin >> guess;
        if (guess < goal) cout << "The goal number is higher \n";
        else if (goal < guess) cout << "The goal number is lower \n";
    } while (goal != guess);

    cout << "You guessed the number (" << goal << ")";
}

int computer_guessing() {
    srand(time(NULL));
    bool guessing = true;
    cout << "Think of a number between 0 and 100 \n";
    int computer_guess = 50;
    int user_input;
    while (guessing) {
        cout << "My guess is " << computer_guess << " is this right? \n";
        cout << "1 - yes \n 2 - higher \n 3 - lower";
        cin >> user_input;

        switch (user_input) {
            case 1:
                cout << "I won!";
                guessing = false;
                break;
            case 2:
            // TODO
        }
    }
}

int main() {
    
}