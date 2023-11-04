#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 4

void clear_screen()
{
    system("@cls || clear");
    system("cls");
}

char loading_box(char box[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        printf("                                                                                 ");
        for (int j = 0; j < COL; j++)
        {
            printf("\033[1;32m");
            printf("%c", box[i][j]);
            printf("\033[0m");
        }
        printf("\n");
    }
    return box[ROW][COL];
}

char up(char box[ROW][COL], int function_row, int function_column, int function_bot)
{
    box[function_row][function_column] = ' ';
    box[function_row - 1][function_column] = function_bot;
    return box[ROW][COL];
}

char down(char box[ROW][COL], int function_row, int function_column, int function_bot)
{
    box[function_row][function_column] = ' ';
    box[function_row + 1][function_column] = function_bot;
    return box[ROW][COL];
}

char right(char box[ROW][COL], int function_row, int function_column, int function_bot)
{
    box[function_row][function_column] = ' ';
    box[function_row][function_column + 1] = function_bot;
    return box[ROW][COL];
}

char left(char box[ROW][COL], int function_row, int function_column, int function_bot)
{
    box[function_row][function_column] = ' ';
    box[function_row][function_column - 1] = function_bot;
    return box[ROW][COL];
}

int loading_value()
{
    srand(time(NULL));
    int temp_load = rand() % 6;
    return temp_load;
}

void brand_name()
{
    printf("\033[1;31m");
    printf("_ _  _ ___ ____ ____ ____ _ ___ _   _    ___  _  _ ____    ____ ____ ____ _  _ _ ____ ____\n");
    printf("| |\\ |  |  |___ |__/ |    |  |   \\_/     |__] |  | [__     [__  |___ |__/ |  | | |    |__\n");
    printf("| | \\|  |  |___ |  \\ |___ |  |    |      |__] |__| ___]    ___] |___ |  \\  \\/  | |___ |___\n\n");
    printf("\033[0m");
}

void developer_logo()
{
    char punch_line[50] = "The happy bus for happy people :)";
    char developer[50] = "powered by cat transportation system";
    printf("                                                     ");
    printf("\033[1;35m");
    for (int i = 0; i < 50; i++)
    {
        
        printf("%c", developer[i]);
        Sleep(18);
    }
    printf("\n");
    printf("                           ");
    printf("\033[0m");
    printf("\033[1;33m");
    for (int i = 0; i < 50; i++)
    {
        printf("%c", punch_line[i]);
        Sleep(20);
    }
    printf("\033[0m");
}

void splash_screen()
{

    char box[ROW][COL] = {
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}};
    char bot = 'O';
    int start_row = 0;
    int start_col = 0;
    box[start_row][start_col] = 'O';
    int sum = 0;
    loading_box(box);
    while (1)
    {
        right(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_col++;
        right(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_col++;
        right(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_col++;

        down(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_row++;
        down(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_row++;

        left(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_col--;
        left(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_col--;
        left(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_col--;

        up(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_row--;
        up(box, start_row, start_col, bot);
        clear_screen();
        brand_name();
        loading_box(box);
        sum += loading_value();
        if (sum >= 100)
        {
            printf("\n                                                                         Loading...100/100");
            break;
        }
        printf("\n                                                                          Loading...%d/100", sum);
        Sleep(150);
        start_row--;
    }
    Sleep(50);
    clear_screen();
    brand_name();
    developer_logo();
    Sleep(50);
}