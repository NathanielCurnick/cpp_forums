// Dungeon crawler

#include <iostream>
#include <time.h>
using std::cin;
using std::cout;

char *make_board()
{
    static char board[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            board[j][i] = '0';
        }
    }
    return *board;
}

void draw_board(char *board)
{
    for (int i = 0; i < 100; i += 10)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << *(board + (i + j));
        }
        cout << std::endl;
    }
}

void set_traps(char *board)
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        *(board + rand() % 100) = 'T';
    }
}

int set_player(char *board)
{
    srand(time(NULL));
    int place = rand() % 100;
    *(board + place) = 'G';
    return place;
}

void move_player(int place, char *board)
{
    bool moving = true;
    int choice;

    while (moving)
    {
        cout << "Choose your move" << std::endl;
        cout << "1 - up | 2 - down | 3 - left | 4 - right" << std::endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (place - 10 < 0)
            {
                cout << "Sorry that is naht a valid choice \n";
                break;
            }
            else
            {
                *(board + place) = '0';
                place = place - 10;
                *(board + place) = 'G';
                // TODO
            }
        }
    }
}

int main()
{
    char *board = make_board();
    set_traps(board);
    int place = set_player(board);
    draw_board(board);
}
