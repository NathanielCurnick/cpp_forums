#include <iostream>
// #include <cstddef>
#include <time.h>
using std::cin;
using std::cout;
using std::string;

struct Bunny
{
    bool male;
    string colour;
    int age;
    string name;
    bool radioactive_mutant_vampire_bunny;
    Bunny *next;
};

typedef Bunny *BunnyCollection;

bool get_male()
{
    int num = rand() % 2;
    switch (num)
    {
    case 0:
        return true;
    case 1:
        return false;
    }
    return true; // Although the case statement should never fail, it's good to have a default return (or our program would break in many unusual ways)
}

string get_colour()
{
    int num = rand() % 4;
    switch (num)
    {
    case 0:
        return "White";
    case 1:
        return "Brown";
    case 2:
        return "Black";
    case 3:
        return "Spotted";
    }
    return "White";
}

string get_name()
{
    int num = rand() % 5;
    switch (num)
    {
    case 0:
        return "Snowball";
    case 1:
        return "Thumper";
    case 2:
        return "Hopper";
    case 3:
        return "Midnight";
    case 4:
        return "Snoop";
    }
    return "Bailey";
}

bool get_radioactive_mutant_vampire_bunny()
{
    int num = rand() % 100 + 1;

    if (num > 98)
    {
        return true;
    }
    return false;
}

void add_rand_bunny(BunnyCollection &bc)
{
    Bunny *new_bunny = new Bunny;
    new_bunny->age = 0;
    new_bunny->male = get_male();
    new_bunny->colour = get_colour();
    new_bunny->name = get_name();
    new_bunny->radioactive_mutant_vampire_bunny = get_radioactive_mutant_vampire_bunny();
    new_bunny->next = bc;
    bc = new_bunny;
}

void add_born_bunny(BunnyCollection &bc, string colour)
{
    Bunny *new_bunny = new Bunny;
    new_bunny->age = 0;
    new_bunny->male = get_male();
    new_bunny->colour = colour;
    new_bunny->name = get_name();
    new_bunny->radioactive_mutant_vampire_bunny = get_radioactive_mutant_vampire_bunny();
    new_bunny->next = bc;
    bc = new_bunny;
}

void init_bunny(BunnyCollection &bc)
{
    Bunny *new_bunny = new Bunny;
    new_bunny->age = 0;
    new_bunny->male = get_male();
    new_bunny->colour = get_colour();
    new_bunny->name = get_name();
    new_bunny->radioactive_mutant_vampire_bunny = get_radioactive_mutant_vampire_bunny();
    new_bunny->next = NULL;
    bc = new_bunny;
}

void print_bunnies(BunnyCollection &bc)
{
    Bunny *loop_ptr = bc;
    while (loop_ptr != NULL)
    {
        cout << "---------------------" << std::endl;
        cout << "Name: " << loop_ptr->name << std::endl;
        cout << "Age: " << loop_ptr->age << std::endl;
        cout << "Sex :";
        if (loop_ptr->male == true)
        {
            cout << " Male" << std::endl;
        }
        else
        {
            cout << " Female" << std::endl;
        }
        cout << "Colour: " << loop_ptr->colour << std::endl;
        cout << "Radioactive Mutant: " << loop_ptr->radioactive_mutant_vampire_bunny << std::endl;
        loop_ptr = loop_ptr->next;
    }
}

void age_bunnies(BunnyCollection &bc)
{
    Bunny *loop_ptr = bc;
    while (loop_ptr != NULL)
    {
        loop_ptr->age = loop_ptr->age + 1;
        loop_ptr = loop_ptr->next;
    }
}

void breed_bunnies(BunnyCollection &bc)
{
    bool male_older_than_two = false;
    Bunny *loop_ptr = bc;

    while (loop_ptr != NULL)
    {
        if (loop_ptr->male == true && loop_ptr->age >= 2)
        {
            male_older_than_two = true;
            break;
        }
        loop_ptr = loop_ptr->next;
    }

    if (male_older_than_two)
    {
        Bunny *loop_ptr = bc;
        while (loop_ptr != NULL)
        {
            if (loop_ptr->male == false && loop_ptr->age >= 2)
            {
                add_born_bunny(bc, loop_ptr->colour);
            }
            loop_ptr = loop_ptr->next;
        }
    }
}

void del_bunny(Bunny *before)
{
    if (before->next != NULL)
    {
        Bunny *temp = before->next;
        before->next = temp->next;
        cout << "About to delete" << std::endl;
        delete temp;
    }
}

void kill_elderly(BunnyCollection &bc)
{
    // Bunnies older than 10 will die
    Bunny *loop_ptr = bc;
    while (loop_ptr != NULL)
    {
        Bunny *temp = loop_ptr->next;
        cout << "made temp" << std::endl;
        if (temp->age > 4)
        {
            del_bunny(loop_ptr);
        }

        loop_ptr = loop_ptr->next;
    }
}

int main()
{
    BunnyCollection bc;
    init_bunny(bc);

    for (int i = 0; i < 4; i++)
    {
        add_rand_bunny(bc);
    }
    cout << "Initial Bunnies!" << std::endl;
    print_bunnies(bc);

    for (int i = 0; i < 10; i++)
    {
        cout << "=====================" << std::endl;
        cout << "Turn " << i << std::endl;
        cout << "=====================" << std::endl;
        age_bunnies(bc);
        cout << "Successfully aged" << std::endl;
        breed_bunnies(bc);
        cout << "Successfully bred" << std::endl;
        kill_elderly(bc);
        cout << "Successfully culled" << std::endl;
        print_bunnies(bc);
    }
}