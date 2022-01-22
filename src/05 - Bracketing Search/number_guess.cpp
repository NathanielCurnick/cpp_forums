#include <iostream>
#include <time.h>
using std::cin;
using std::cout;

void human_guessing()
{
    srand(time(NULL));
    int goal = rand() % 100 + 1;
    int guess;
    do
    {
        cout << "Guess the number (1 to 100) \n";

        cin >> guess;
        if (guess < goal)
            cout << "The goal number is higher \n";
        else if (goal < guess)
            cout << "The goal number is lower \n";
    } while (goal != guess);

    cout << "You guessed the number (" << goal << ")\n";
}

void computer_guessing()
{
    srand(time(NULL));
    bool guessing = true;
    cout << "Think of a number between 0 and 100 \n";
    int computer_guess = 50;
    int user_input;
    int current_high = 100;
    int current_low = 0;
    while (guessing)
    {
        cout << "My guess is " << computer_guess << "; is this right? \n";
        cout << "1 - yes \n 2 - higher \n 3 - lower";
        cin >> user_input;

        switch (user_input)
        {
        case 1:
            cout << "I won!\n";
            guessing = false;
            break;
        case 2:
            current_low = computer_guess;
            computer_guess = (current_high + current_low) / 2;
            break;
        case 3:
            current_high = computer_guess;
            computer_guess = (current_high + current_low) / 2;
            break;
        default:
            break;
        }
    }
}

int main()
{
    cout << "Welcome to the guessing game!\n";
    cout << "First you will guess the computer number, then it will guess yours\n";

    human_guessing();
    computer_guessing();
}