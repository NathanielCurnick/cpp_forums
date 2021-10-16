#include <iostream>
using std::cin;
using std::cout;
using std::string;

int main()
{
    string first, last;

    cout << "Enter first name \n";
    cin >> first;

    cout << "Enter last name \n";
    cin >> last;

    string full = first + " " + last;

    cout << "Your name is " << full << std::endl;

    for (int i = 0; i < full.length(); i++)
    {
        if (full[i] == 'a' || full[i] == 'A' || full[i] == 'e' || full[i] == 'E' || full[i] == 'i' || full[i] == 'I' || full[i] == 'o' || full[i] == 'O' || full[i] == 'u' || full[i] == 'U')
        {
            full[i] = 'z';
        }
    }

    cout << "Your name is now " << full << std::endl;

    int length = full.length();
    string reverse = full;

    for (int i = length - 1; i >= 0; i--)
    {
        reverse[length - 1 - i] = full[i];
    }

    cout << "Your reversed name is " << reverse << std::endl;
}