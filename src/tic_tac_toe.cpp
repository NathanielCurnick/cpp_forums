#include <iostream>
using std::cin;
using std::cout;

int* make_board() {
    static int board[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    return *board;
}

void draw_board(int *board){
    cout << *board << "|" << *(board + 1) << "|" << *(board + 2) << std::endl;
    cout << *(board + 3) << "|" << *(board + 4) << "|" << *(board + 5) << std::endl;
    cout << *(board + 6) << "|" << *(board + 7) << "|" << *(board + 8) << std::endl;
}

int main() {
    // Create board
    int *board = make_board();
    draw_board(board);
    // Get input
    // Update board
    // Give message if someone wins
}