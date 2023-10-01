#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// ROW and COLUMN for array
#define ROW_SIZE 7
#define COLUMN_SIZE 7
// for welcome message
#define MAX_CHAR_ARRAY_SIZE 200

// clear terminal
void clear_screen()
{
    system("@cls||clear");
    // Alternate: system("cls");
}

// printing a little interaction for user in main function
void commands_text()
{
    printf("Enter a command for our little bot (w/a/s/d): ");
}

// display welcome message with animation
void welcome_message_delay()
{
    char message[MAX_CHAR_ARRAY_SIZE] = {"\t  Welcome to the Robot Command Center!\nThis robot (1) is programmed to move upon receiving commands.\n    You can command it to move up, down, left, right."};
    for (int i = 0; i < MAX_CHAR_ARRAY_SIZE; i++)
    {
        printf("%c", message[i]);
        Sleep(20);
    }
}

// display welcome message without animation
void welcome_message()
{
    char message[MAX_CHAR_ARRAY_SIZE] = {"\t  Welcome to the Robot Command Center!\nThis robot (1) is programmed to move upon receiving commands.\n    You can command it to move up, down, left, right."};
    for (int i = 0; i < MAX_CHAR_ARRAY_SIZE; i++)
    {
        printf("%c", message[i]);
    }
}

// for making easy \n lines
void new_line()
{
    printf("\n");
}

// printing board
int gaming_board(int function_game_board[ROW_SIZE][COLUMN_SIZE])
{
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            printf("%d ", function_game_board[i][j]);
        }
        new_line();
    }
    return function_game_board[ROW_SIZE][COLUMN_SIZE];
}

// up command for robot
int up(int function_game_board[ROW_SIZE][COLUMN_SIZE], int function_row, int function_column, int function_bot)
{
    function_game_board[function_row][function_column] = 0;
    function_game_board[function_row - 1][function_column] = function_bot;

    return function_game_board[ROW_SIZE][COLUMN_SIZE];
}

// down command for robot
int down(int function_game_board[ROW_SIZE][COLUMN_SIZE], int function_row, int function_column, int function_bot)
{
    function_game_board[function_row][function_column] = 0;
    function_game_board[function_row + 1][function_column] = function_bot;
    return function_game_board[ROW_SIZE][COLUMN_SIZE];
}

// right command for robot
int right(int function_game_board[ROW_SIZE][COLUMN_SIZE], int function_row, int function_column, int function_bot)
{
    function_game_board[function_row][function_column] = 0;
    function_game_board[function_row][function_column + 1] = function_bot;
    return function_game_board[ROW_SIZE][COLUMN_SIZE];
}

// left command for robot
int left(int function_game_board[ROW_SIZE][COLUMN_SIZE], int function_row, int function_column, int function_bot)
{

    function_game_board[function_row][function_column] = 0;
    function_game_board[function_row][function_column - 1] = function_bot;
    return function_game_board[ROW_SIZE][COLUMN_SIZE];
}

// checks if user is going outside of map
int check_board_size(int function_row, int function_column)
{
    if (function_row < 0 || function_row == ROW_SIZE || function_column < 0 || function_column == COLUMN_SIZE)
    {
        system("@cls||clear");
        printf("Ops! You went outside the map so, your robot got destroyed.\n");
        printf("                   GAME OVER!!!\n");
        printf("                      (T_T)");
        exit(0);
    }
    else
        return 0;
}

// all user defined function running in main function
int main()
{
    clear_screen();
    char command;
    int game_board[ROW_SIZE][COLUMN_SIZE] = {0};
    welcome_message_delay();
    new_line();
    printf("Here's the current sandbox: \n");

    int row_position = 3, column_position = 3, robot = 1;
    game_board[row_position][column_position] = robot;
    gaming_board(game_board);

    commands_text();

    while (1)
    {
        scanf("%c", &command);

        switch (command)
        {
        case 'w':
        case 'W':
            clear_screen();
            up(game_board, row_position, column_position, robot);
            welcome_message();
            new_line();
            printf("Last command w/W for moving up!\n");
            gaming_board(game_board);
            commands_text();
            row_position--;
            break;

        case 's':
        case 'S':
            clear_screen();
            down(game_board, row_position, column_position, robot);
            welcome_message();
            new_line();
            printf("Last command s/S for moving down!\n");
            gaming_board(game_board);
            commands_text();

            row_position++;
            break;

        case 'a':
        case 'A':
            clear_screen();
            left(game_board, row_position, column_position, robot);
            welcome_message();
            new_line();
            printf("Last command a/A for moving left!\n");
            gaming_board(game_board);
            commands_text();
            column_position--;
            break;

        case 'd':
        case 'D':
            clear_screen();
            right(game_board, row_position, column_position, robot);
            welcome_message();
            new_line();
            printf("Last command d/D for moving right!\n");
            gaming_board(game_board);
            commands_text();
            column_position++;
            break;
        }
        check_board_size(row_position, column_position);
    }
}