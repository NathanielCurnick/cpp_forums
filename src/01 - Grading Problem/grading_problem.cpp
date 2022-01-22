#include <iostream>
using std::cout;
using std::cin;

int main(){
    cout << "Please enter your test score";
    int score;
    cin >> score;

    if (score >= 0 && score <= 59) cout << "You got an F";
    else if (score >= 60 && score <= 69) cout << "You got a D";
    else if (score >= 70 && score <= 79) cout << "You got a C";
    else if (score >= 80 && score <= 89) cout << "You got a B";
    else if (score >= 90) cout << "You got an A \n";

    if (score >= 100) cout << "You got a perfect score, great job";
}