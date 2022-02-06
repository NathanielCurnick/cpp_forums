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

bool check_trap(char *board, int place)
{
    return *(board + place) == 'T';
}

int move_player(int place, char *board)
{
    bool moving = true;
    char choice;

    while (moving)
    {
        cout << "Choose your move" << std::endl;
        cout << "w - up | s - down | a - left | d - right" << std::endl;
        cin >> choice;

        switch (choice)
        {
        case 'w':
            if (place - 10 < 0)
            {
                cout << "Sorry that is naht a valid choice \n";
                break;
            }
            else
            {
                if (check_trap(board, place - 10))
                {
                    cout << "You died!\n";
                    moving = false;
                    place = -1;
                    break;
                }
                *(board + place) = '0';
                place = place - 10;
                *(board + place) = 'G';
                moving = false;
            }
            break;
        case 's':
            if (place + 10 > 99)
            {
                cout << "Sorry that is naht a valid choice \n";
            }
            else
            {
                if (check_trap(board, place + 10))
                {
                    cout << "You died!\n";
                    moving = false;
                    place = -1;
                    break;
                }
                *(board + place) = '0';
                place = place + 10;
                *(board + place) = 'G';
                moving = false;
            }
            break;
        case 'a':
            if (place % 10 == 0)
            {
                cout << "Sorry that is naht a valid choice \n";
            }
            else
            {
                if (check_trap(board, place - 1))
                {
                    cout << "You died!\n";
                    moving = false;
                    place = -1;
                    break;
                }
                *(board + place) = '0';
                place = place - 1;
                *(board + place) = 'G';
                moving = false;
            }
            break;
        case 'd':
            if (place % 10 == 9)
            {
                cout << "Sorry that is not a valid choice \n";
            }
            else
            {
                if (check_trap(board, place + 1))
                {
                    cout << "You died!\n";
                    moving = false;
                    place = -1;
                    break;
                }
                *(board + place) = '0';
                place = place + 1;
                *(board + place) = 'G';
                moving = false;
            }
            break;
        default:
            cout << "Sorry I don't know that command \n";
            break;
        }
    }

    return place;
}

// TODO turn this into full game

int main()
{
    bool running = true;
    char *board = make_board();
    set_traps(board);
    int place = set_player(board);

    while (running)
    {
        draw_board(board);

        place = move_player(place, board);

        if (place == -1)
        {
            cout << "GAME OVER\n";
            running = false;
        }
    }
}
