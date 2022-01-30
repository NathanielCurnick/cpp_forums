#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

// This is the first file in the set where things stop being quite so obvious

// Here we define a struct - this is a data type composed of two other data types
// The intention here is to store the # person and the number of pancakes they ate
struct Pancakes
{
    int person;
    int num;
};

// This function is helpful for us. It allows us to do something tedious over and over again without typing it out
// The & means the function will take a reference to the vector - this is important for memory efficiency!
void print_pancakes(vector<Pancakes> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << "Perosn " << vec.at(i).person << " ate " << vec.at(i).num << " pancakes" << endl;
    }
}

// This function is used to sort the vector. There isn't scope to explain sort here, but do note how we access the num field of the Pancake struct
bool pancake_sort(Pancakes p1, Pancakes p2)
{
    return p1.num > p2.num;
}

int main()
{
    vector<Pancakes> data = {};

    for (int i = 1; i <= 10; i++)
    {
        cout << "Please enter the number of pancakes ate by person " << i << " ";
        int number_ate;
        cin >> number_ate;

        data.insert(data.end(), {i, number_ate});
    }

    sort(data.begin(), data.end(), pancake_sort);

    print_pancakes(data);
}