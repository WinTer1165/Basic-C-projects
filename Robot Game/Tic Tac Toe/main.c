#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 3
#define COLUMN_SIZE 8

// clear terminal
void clear_screen()
{
    system("@cls||clear");
    // Alternate: system("cls");
}

// printing to next line
void next_line()
{
    printf("\n");
}

// little welcome message
void welcome_message()
{
    printf("    WELCOME TO SIMPLE TIC TAC TOE!!!\n");
    printf("Enter number of rows according to num-pad\n");
    printf("   Player One goes first and is 'X'\n");
}

// draw game board
char game_board(char function_array_board[ROW_SIZE][COLUMN_SIZE])
{

    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            printf("%c", function_array_board[i][j]);
        }
        if (i == 0 || i == 1)
        {
            printf("\n--+--+--\n");
        }
    }
    return function_array_board[ROW_SIZE][COLUMN_SIZE];
}

// draw player 1 move in game board
char playerOne(char function_array_board[ROW_SIZE][COLUMN_SIZE], int function_player_one_move)
{
    switch (function_player_one_move)
    {
    case 1:
        function_array_board[0][0] = 'X';
        break;
    case 2:
        function_array_board[0][3] = 'X';
        break;
    case 3:
        function_array_board[0][6] = 'X';
        break;
    case 4:
        function_array_board[1][0] = 'X';
        break;
    case 5:
        function_array_board[1][3] = 'X';
        break;
    case 6:
        function_array_board[1][6] = 'X';
        break;
    case 7:
        function_array_board[2][0] = 'X';
        break;
    case 8:
        function_array_board[2][3] = 'X';
        break;
    case 9:
        function_array_board[2][6] = 'X';
        break;
    }
    return function_array_board[ROW_SIZE][COLUMN_SIZE];
}

// draw player 2 move in game board
char playerTwo(char function_array_board[ROW_SIZE][COLUMN_SIZE], int function_player_two_move)
{
    switch (function_player_two_move)
    {
    case 1:
        function_array_board[0][0] = 'O';
        break;
    case 2:
        function_array_board[0][3] = 'O';
        break;
    case 3:
        function_array_board[0][6] = 'O';
        break;
    case 4:
        function_array_board[1][0] = 'O';
        break;
    case 5:
        function_array_board[1][3] = 'O';
        break;
    case 6:
        function_array_board[1][6] = 'O';
        break;
    case 7:
        function_array_board[2][0] = 'O';
        break;
    case 8:
        function_array_board[2][3] = 'O';
        break;
    case 9:
        function_array_board[2][6] = 'O';
        break;
    }
    return function_array_board[ROW_SIZE][COLUMN_SIZE];
}

// checks win condition for 3 in a row
int checkWinConditions(char function_array_board[ROW_SIZE][COLUMN_SIZE])
{
    if ((function_array_board[0][0] == 'X' && function_array_board[0][3] == 'X' && function_array_board[0][6] == 'X') || (function_array_board[1][0] == 'X' && function_array_board[1][3] == 'X' && function_array_board[1][6] == 'X') || (function_array_board[2][0] == 'X' && function_array_board[2][3] == 'X' && function_array_board[2][6] == 'X') || (function_array_board[0][0] == 'X' && function_array_board[1][3] == 'X' && function_array_board[2][6] == 'X') || (function_array_board[0][6] == 'X' && function_array_board[1][3] == 'X' && function_array_board[2][0] == 'X') || (function_array_board[0][0] == 'X' && function_array_board[1][0] == 'X' && function_array_board[2][0] == 'X') || (function_array_board[0][3] == 'X' && function_array_board[1][3] == 'X' && function_array_board[2][3] == 'X') || (function_array_board[0][6] == 'X' && function_array_board[1][6] == 'X' && function_array_board[2][6] == 'X'))
    {
        return 1;
    }
    else if ((function_array_board[0][0] == 'O' && function_array_board[0][3] == 'O' && function_array_board[0][6] == 'O') || (function_array_board[1][0] == 'O' && function_array_board[1][3] == 'O' && function_array_board[1][6] == 'O') || (function_array_board[2][0] == 'O' && function_array_board[2][3] == 'O' && function_array_board[2][6] == 'O') || (function_array_board[0][0] == 'O' && function_array_board[1][3] == 'O' && function_array_board[2][6] == 'O') || (function_array_board[0][6] == 'O' && function_array_board[1][3] == 'O' && function_array_board[2][0] == 'O') || (function_array_board[0][0] == 'O' && function_array_board[1][0] == 'O' && function_array_board[2][0] == 'O') || (function_array_board[0][3] == 'O' && function_array_board[1][3] == 'O' && function_array_board[2][3] == 'O') || (function_array_board[0][6] == 'O' && function_array_board[1][6] == 'O' && function_array_board[2][6] == 'O'))
    {
        return 1;
    }
    return 0;
}

// checks draw conditions if all moves are given
int checkDrawConditions(int function_player_move_counter)
{
    if (function_player_move_counter == 8)
    {
        return 1;
    }
    return 0;
}

// main function
int main()
{
    clear_screen();
    char array_board[ROW_SIZE][COLUMN_SIZE] = {{"  |  |  "}, {"  |  |  "}, {"  |  |  "}};
    int playerOneMove, playerTwoMove;
    int i = 1, counter = 0;

    game_board(array_board);
    while (i <= 9)
    {

        if (i % 2 != 0)
        {
            next_line();
            welcome_message();
            next_line();
            printf("Enter your move, Player 1: ");
            scanf("%d", &playerOneMove);
            playerOne(array_board, playerOneMove);
            clear_screen();
            game_board(array_board);
            if (checkWinConditions(array_board) == 1)
            {
                printf("\n\nPlayer One Wins");
                break;
            }
            if (checkDrawConditions(counter) == 1)
            {
                printf("\n\nDraw!!! No one won!");
                break;
            }
        }

        else if (i % 2 == 0)
        {
            next_line();
            welcome_message();
            next_line();
            printf("Enter your move, Player 2: ");
            scanf("%d", &playerTwoMove);
            playerTwo(array_board, playerTwoMove);
            clear_screen();
            game_board(array_board);
            if (checkWinConditions(array_board) == 1)
            {
                printf("\n\nPlayer Two Wins");
                break;
            }
            if (checkDrawConditions(counter) == 1)
            {
                printf("\n\nDraw!!! No one won!");
                break;
            }
        }
        counter++;
        i++;
    }
}