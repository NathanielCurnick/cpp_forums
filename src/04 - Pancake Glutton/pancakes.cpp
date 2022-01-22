#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

struct Pancakes
{
    int person;
    int num;
};
// TODO

void print_pancakes(vector<Pancakes> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << "Perosn " << vec.at(i).person << " ate " << vec.at(i).num << " pancakes" << endl;
    }
}

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