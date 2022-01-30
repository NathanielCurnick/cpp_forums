#include <iostream>
using std::cin;
using std::cout;

// A nice easy problem here - we will use an if-else block to solve the problem

int main()
{
    // cout is how we can print to the console - notice the << pointing to the cout
    cout << "Please enter your test score";

    // Here we define score as an int but don't yet assign it a value
    int score;
    // We define that value with cin which allows us to take input from the console - notice the >> pointing away from cin
    cin >> score;

    // The main block of the program - we simply check score against the set values and print out the message that matches
    if (score >= 0 && score <= 59)
        cout << "You got an F";
    else if (score >= 60 && score <= 69)
        cout << "You got a D";
    else if (score >= 70 && score <= 79)
        cout << "You got a C";
    else if (score >= 80 && score <= 89)
        cout << "You got a B";
    else if (score >= 90)
        cout << "You got an A \n";

    if (score >= 100)
        cout << "You got a perfect score, great job";
}