#include <stdio.h>   //for some basic function like printf(), scanf(), .... etc
#include <stdlib.h>  //for random function and clearing console
#include <time.h>    //for random function
#include <Windows.h> //for Sleep()
#include <string.h>  //for some basic function like strlen()

#define ROW 10
#define COL 10

// clearing screen
void clear_screen()
{
    system("@cls || clear");
    // Alternate: system("cls");
}

// printing welcome message
void welcome_message()
{
    printf("    _            WELCOME TO\n");
    printf("   | |                                            \n");
    printf("   | |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("   | '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("   | | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
    printf("   |_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("                       __/ |                      \n");
    printf("                      |___/  \n");
    printf("   \n");
}

// drawing hangman when user makes a mistake
void drawHangman(int wrong_counter)
{
    switch (wrong_counter)
    {
    case 7:
        printf("  +---+\n"
               "  |   |\n"
               "      |\n"
               "      |\n"
               "      |\n"
               "      |\n"
               "========\n");
        break;
    case 6:
        printf("  +---+\n"
               "  |   |\n"
               "  O   |\n"
               "      |\n"
               "      |\n"
               "      |\n"
               "========\n");
        break;
    case 5:
        printf("  +---+\n"
               "  |   |\n"
               "  O   |\n"
               "  |   |\n"
               "      |\n"
               "      |\n"
               "========\n");
        break;
    case 4:
        printf("  +---+\n"
               "  |   |\n"
               "  O   |\n"
               " /|   |\n"
               "      |\n"
               "      |\n"
               "========\n");
        break;
    case 3:
        printf("  +---+\n"
               "  |   |\n"
               "  O   |\n"
               " /|\\  |\n"
               "      |\n"
               "      |\n"
               "========\n");
        break;
    case 2:
        printf("  +---+\n"
               "  |   |\n"
               "  O   |\n"
               " /|\\  |\n"
               " /    |\n"
               "      |\n"
               "========\n");
        break;
    case 1:
        printf("  +---+\n"
               "  |   |\n"
               "  O   |\n"
               " /|\\  |\n"
               " / \\  |\n"
               "      |\n"
               "========\n");
        break;
    }
}

// returning a random value from 1 to 10
int random_position(int max)
{
    srand(time(NULL));
    int time_sleep = rand() % 100;
    Sleep(time_sleep);
    int temp_index = rand() % max;
    return temp_index;
}

// returning a string with the help of random_position() function
const char *random_word(char words[ROW][COL])
{
    int index = random_position(ROW);
    return words[index];
}

// printing blank space
char blank(int one_words_count, char space[ROW])
{

    for (int i = 0; i < one_words_count; i++)
    {
        space[i] = '-';
    }
    space[one_words_count] = '\0';
    return space[ROW];
}

// returning user value after user puts a input
char check_letters(char one_word_array[ROW], char space[ROW], char alphabet)
{
    int len = strlen(one_word_array);

    for (int i = 0; i < len; i++)
    {
        if (alphabet == space[i])
        {
            printf("[Already Typed!!! Enter a different letter, please]\n");
            break;
        }

        if (alphabet == one_word_array[i])
        {
            space[i] = alphabet;
        }
    }
    return space[ROW];
}

// checking if the user given letter is appropiate and returning for mistake count
int check_win_Condition(char one_word_array[ROW], char alphabet)
{
    int len = strlen(one_word_array);

    for (int i = 0; i < len; i++)
    {
        if (alphabet == one_word_array[i])
        {
            return 0;
            break;
        }
    }
}

// comparing game string and user string for win or lose condition
int comparison_strings(char one_word_array[ROW], char space[ROW])
{
    if (strlen(one_word_array) == strlen(space))
    {
        for (int i = 0; i < strlen(one_word_array); i++)
        {
            if (one_word_array[i] != space[i])
            {
                return 0;
                break;
            }
        }
    }
}

// main function
int main()
{
// labeling
replay:;
    clear_screen();
    int mistake_counter = 7;
    int replay_command;
    char words[ROW][COL] = {"vampire", "potato", "banana", "unicorn", "logitech", "pizza", "yellow", "north", "salad", "jupiter"};
    char space[ROW];
    char one_word_array[ROW];
    char alphabet;
    // receiving random string from random_word() function and converting it to a proper array
    const char *one_word = random_word(words);
    for (int i = 0; one_word[i] != '\0'; i++)
    {
        one_word_array[i] = one_word[i];
    }
    one_word_array[strlen(one_word)] = '\0';
    // for test
    printf("Spoiler Test: %s \n\n\n", one_word_array);

    welcome_message();
    drawHangman(mistake_counter);

    int one_word_count = strlen(one_word_array);
    blank(one_word_count, space);
    printf("\nGuess the correct letters: %s\n", space);
    // entire game logic here
    while (1)
    {
        printf("\nEnter a letter to guess:");
        scanf(" %c", &alphabet);
        clear_screen();
        welcome_message();
        drawHangman(mistake_counter);
        check_letters(one_word_array, space, alphabet);
        printf("\nGuess the correct letters: %s\n", space);
        if (check_win_Condition(one_word_array, alphabet) != 0)
        {
            mistake_counter--;
        }
        if (mistake_counter < 1)
        {
            clear_screen();
            drawHangman(1);
            printf("Ohh no, you have lost!\nRestart the game, please.");
            break;
        }
        else
            printf("You have %d guesses left", mistake_counter);

        if (comparison_strings(one_word_array, space) != 0)
        {
            clear_screen();
            printf("CONGRATULATIONS!!!\nYou have won!");
            break;
        }
    }
    // if user want to replay the game
    printf("\nType: '1' for rematch or Type: '0' for ending game: ");
    scanf("%d", &replay_command);
    if (replay_command == 1)
    {
        // calling the game for going to line 187 for replay
        goto replay;
    }
    else
        printf("You have ended the game:(");
    exit(0);
}