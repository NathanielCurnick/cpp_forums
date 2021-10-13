#include <iostream>
#include <time.h>
using std::cin;
using std::cout;

char *make_board()
{
    static char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    return *board;
}

void draw_board(char *board)
{
    cout << *board << "|" << *(board + 1) << "|" << *(board + 2) << std::endl;
    cout << *(board + 3) << "|" << *(board + 4) << "|" << *(board + 5) << std::endl;
    cout << *(board + 6) << "|" << *(board + 7) << "|" << *(board + 8) << std::endl;
}

int change_board(char *board, int move, bool player1_move)
{

    if (*(board + move - 1) != 'X' && *(board + move - 1) != 'O')
    {
        if (player1_move)
            *(board + move - 1) = 'X';
        else
            *(board + move - 1) = 'O';

        return 0;
    }
    else
    {
        cout << *(board + move - 1) << " " << *(board + move - 1) << std::endl;
        return 1;
    }
}

int game_won(char *board)
{
    // Return 0 if game not won
    // Return 1 if player 1 won
    // Return 2 is player 2 won
    // Game ended check
    // Winning states
    // 1,2,3
    // 4,5,6
    // 7,8,9
    // 1,4,7
    // 2,5,8
    // 3,6,9
    // 1,5,9
    // 3,5,7

    // check horizontals

    for (int i = 0; i < 9; i += 3)
    {
        if (*(board + i) == 'X' && *(board + i + 1) == 'X' && *(board + i + 2) == 'X')
        {
            return 1;
        }
        else if (*(board + i) == 'O' && *(board + i + 1) == 'O' && *(board + i + 2) == 'O')
        {
            return 2;
        }
    }

    // Check verticles

    for (int i = 0; i < 3; i++)
    {
        if (*(board + i) == 'X' && *(board + i + 3) == 'X' && *(board + i + 6) == 'X')
        {
            return 1;
        }
        else if (*(board + i) == 'O' && *(board + i + 3) == 'O' && *(board + i + 6) == 'O')
        {
            return 2;
        }
    }

    // Check diagonals

    if ((*(board) == 'X' && *(board + 4) == 'X' && *(board + 8) == 'X') || (*(board + 2) == 'X' && *(board + 4) == 'X' && *(board + 6)))
    {
        return 1;
    }
    else if ((*(board) == 'O' && *(board + 4) == 'O' && *(board + 8) == 'O') || (*(board + 2) == 'O' && *(board + 4) == 'O' && *(board + 6) == 'O'))
    {
        return 2;
    }
    return 0;
}

bool board_full(char *board)
{
    bool full = true;
    for (int i = 0; i < 9; i++)
    {
        if (*(board + i) != 'X' && *(board + i) != 'O')
        {
            full = false;
            return full;
        }
    }
    return full;
}

int computer_move(char *board, bool human_crosses)
{
    // TODO computer will block human if about to win
    // Check for corners
    // Corner spaces are 1, 3, 7, 9
    // TODO try and pick optimal corners i.e. opposite to human

    char character;
    if (human_crosses)
        character = 'O';
    else
        character = 'X';

    if (*(board) != 'X' && *(board) != 'O')
    {
        *(board) = character;
        return 0;
    }
    if (*(board + 2) != 'X' && *(board + 2) != 'O')
    {
        *(board + 2) = character;
        return 0;
    }
    if (*(board + 6) != 'X' && *(board + 6) != 'O')
    {
        *(board + 6) = character;
        return 0;
    }
    if (*(board + 8) != 'X' && *(board + 8) != 'O')
    {
        *(board + 8) = character;
        return 0;
    }

    // If no corners then edges
    // edges are 2, 4, 6, 8

    if (*(board + 1) != 'X' && *(board + 1) != 'O')
    {
        *(board + 1) = character;
        return 0;
    }
    if (*(board + 3) != 'X' && *(board + 3) != 'O')
    {
        *(board + 3) = character;
        return 0;
    }
    if (*(board + 5) != 'X' && *(board + 5) != 'O')
    {
        *(board + 5) = character;
        return 0;
    }
    if (*(board + 7) != 'X' && *(board + 7) != 'O')
    {
        *(board + 7) = character;
        return 0;
    }

    // If no edges then centre
    // centre is 5
    if (*(board + 4) != 'X' && *(board + 4) != 'O')
    {
        *(board + 4) = character;
        return 0;
    }

    return 1; // In the off chance this fails, although, it shouldn't
    // ! shouldn't and won't are two different things
}

void play_human()
{
    // State variables
    bool player1_go = true;
    bool game_running = true;
    // Create board
    char *board = make_board();

    while (game_running)
    {
        draw_board(board);

        // Get input
        if (player1_go)
        {
            cout << "Player 1, please select your move \n";
        }
        else
        {
            cout << "Player 2, please select your move \n";
        }
        int input;
        cin >> input;

        // Update board

        int board_change = change_board(board, input, player1_go);
        if (board_change == 1)
        {
            cout << "Sorry that place is already taken \n";
            continue;
        }
        else
        {
            player1_go = !player1_go;
        }
        // Check if board is full

        if (board_full(board))
        {
            draw_board(board);
            cout << "The game is over" << std::endl;
            game_running = false;
            break;
        }

        // Give message if someone wins
        int won = game_won(board);
        if (won == 1)
        {
            cout << "Player 1 wins" << std::endl;
            game_running = false;
            break;
        }
        else if (won == 2)
        {
            cout << "Player 2 wins" << std::endl;
            game_running = false;
            break;
        }
    }
}

void play_computer()
{
    // State variables
    bool human_go = true;
    bool game_running = true;
    // Create board
    char *board = make_board();

    bool human_crosses;
    srand(time(NULL));
    int goal = rand() % 100 + 1;

    if (goal > 50)
        human_crosses = true;
    else
        human_crosses = false;

    while (game_running)
    {
        draw_board(board);

        // Get input
        if (human_go)
        {
            cout << "Hooooooooooooooooman, please select your move \n";
            int input;
            cin >> input;

            // Update board

            int board_change = change_board(board, input, human_go);
            if (board_change == 1)
            {
                cout << "Sorry that place is already taken \n";
                continue;
            }
            else
            {
                human_go = !human_go;
            }
        }
        else
        {
            computer_move(board, human_crosses);
            human_go = !human_go;
        }

        // Check if board is full

        if (board_full(board))
        {
            draw_board(board);
            cout << "The game is over" << std::endl;
            game_running = false;
            break;
        }

        // Give message if someone wins
        int won = game_won(board);
        if (won == 1)
        {
            cout << "Player 1 wins" << std::endl;
            game_running = false;
            break;
        }
        else if (won == 2)
        {
            cout << "Player 2 wins" << std::endl;
            game_running = false;
            break;
        }
    }
}
int main()
{
    cout << "Welcome to tic-tac-toe \n";
    cout << "Would you like to play a human or a computer? \n";
    cout << "1 - human | 2 - computer \n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        play_human();
    }
    else if (choice == 2)
    {
        play_computer();
    }
}