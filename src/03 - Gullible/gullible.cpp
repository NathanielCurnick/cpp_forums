#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int i = 0;
    bool running = true;
    // This will loop as long as running is true.
    while (running)
    {
        cout << "DON'T enter the number " << i;
        int input;
        cin >> input;
        if (input == i)
        {
            cout << "I told you not to enter that!";
            running = false;
        }
        if (i == 10)
        {
            cout << "You beat me!";
            running = false;
        }
        // We increment i after each iteration so we can exit the program after some finite number
        i++;
    }
}