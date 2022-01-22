#include <iostream>
using std::cin;
using std::cout;

void print_hello(int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << "Hello! \n";
    }
}

int product(int a, int b)
{
    return a * b;
}

void half(int a)
{
    int b = a / 2;
    cout << b << std::endl;
    if (b > 0)
    {
        half(b);
    }
}

int main()
{
    // Hello
    int num = 6;
    print_hello(num);

    // Product
    int result = product(10, 15);
    cout << result << std::endl;

    // Rescursive
    half(100);
}