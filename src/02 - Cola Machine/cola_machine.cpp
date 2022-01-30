#include <iostream>
using std::cin;
using std::cout;

int main()
{
    // Note the use of \n to mean newline. If we didn't use it all of these would be on the same line!
    cout << "Please select your drink \n";
    cout << "1: Cola \n";
    cout << "2: Water \n";
    cout << "3: Sprite \n";
    cout << "4: Tea \n";
    cout << "5: Coffee \n";

    int choice;

    cin >> choice;
    // Rather than use an if-else statement we use a switch-case statement in this example. This can be helpful with more discrete cases
    switch (choice)
    {
    case 1:
        cout << "Here is your Cola!";
        break;
    case 2:
        cout << "Here is your water!";
        break;
    case 3:
        cout << "Here is your Sprite!";
        break;
    case 4:
        cout << "Here is your tea!";
        break;
    case 5:
        cout << "Here is your coffee!";
        break;
    default:
        "Uh-oh we don't sell that!";
    }
}