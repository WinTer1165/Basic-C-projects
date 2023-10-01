#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define NUM_ARRAY_SIZE 10
#define SC_ARRAY_SIZE 12
#define ALPHA_ARRAY_SIZE 52

void welcome_message()
{
    printf("\n. . . . . WELCOME TO PASSWORD GENERATOR . . . . . \n");
}

int random_digits(int function_number_array[NUM_ARRAY_SIZE], int function_user_range)
{
    srand(time(NULL));
    for (int i = 0; i < function_user_range; i++)
    {
        function_number_array[i] = function_number_array[rand() % NUM_ARRAY_SIZE];
    }
    return function_number_array[function_user_range];
}

int random_alphabet(char function_alphabet_array[ALPHA_ARRAY_SIZE], int function_user_range)
{
    srand(time(NULL));
    for (int i = 0; i < function_user_range; i++)
    {
        function_alphabet_array[i] = function_alphabet_array[rand() % ALPHA_ARRAY_SIZE];
    }
    return function_alphabet_array[function_user_range];
}

int random_special_character(char function_special_character_array[SC_ARRAY_SIZE], int function_user_range)
{
    srand(time(NULL));
    for (int i = 0; i < function_user_range; i++)
    {
        function_special_character_array[i] = function_special_character_array[rand() % SC_ARRAY_SIZE];
    }
    return function_special_character_array[function_user_range];
}

int generatePassword(int function_number_array[NUM_ARRAY_SIZE], char function_alphabet_array[ALPHA_ARRAY_SIZE], char function_special_character_array[SC_ARRAY_SIZE], int func_user_number, int func_user_alpha, int func_user_special_ch, int func_total_digits)
{
    random_digits(function_number_array, func_user_number);
    random_alphabet(function_alphabet_array, func_user_alpha);
    random_special_character(function_special_character_array, func_user_special_ch);
    int j = 0, n = 1;
    for (int i = 0; i < func_total_digits; i++)
    {
        while (j < n)
        {
            if (j < func_user_number)
            {
                printf("%d", function_number_array[j]);
                Sleep(1);
            }
            if (j < func_user_special_ch)
            {
                printf("%c", function_special_character_array[j]);
                Sleep(1);
            }
            if (j < func_user_alpha)
            {
                printf("%c", function_alphabet_array[j]);
                Sleep(1);
            }
            j++;
            n++;
        }
    }
    return 0;
}

int replay(int func_user_replay)
{
    if (func_user_replay == 1)
    {
        printf("\n. . . . . PASSWORD GENERATOR ENDED . . . . . ");
        return 1;
    }
    return 0;
}

int passwordStrength(int func_total_digits)
{
    printf("\n");
    if (func_total_digits <= 4)
    {
        printf("[Warning] Very Weak Password!!!");
    }
    else if (func_total_digits <= 10)
    {
        printf("[Warning] Weak Password!!!");
    }
    else if (func_total_digits <= 18)
    {
        printf("Strong Password!!!");
    }
    else if (func_total_digits <= 24)
    {
        printf("Very Strong Password!!!");
    }
    else if (func_total_digits <= 28)
    {
        printf("Super Strong Password!!!");
    }
    else if (func_total_digits <= 100)
    {
        printf("Super-duper password Password!!!");
    }
    printf("\n");
    printf("\n");
    return 0;
}

int main()
{
    int user_replay, user_number, user_alpha, user_special_ch, total_digits = 0;
    while (1)
    {

        int numbers[NUM_ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        char alphabets[ALPHA_ARRAY_SIZE] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
        char special_characters[SC_ARRAY_SIZE] = {"@#!&_[]?,()"};
        welcome_message();
        printf("How many digits you want?: ");
        scanf("%d", &user_number);
        printf("How many alphabets you want?: ");
        scanf("%d", &user_alpha);
        printf("How many special characters you want?: ");
        scanf("%d", &user_special_ch);

        total_digits = user_number + user_alpha + user_special_ch;
        if (total_digits >= 100)
        {
            printf("\n[Total character should be less than 100]\n\n");
            printf("\n. . . . .  EXCEED PROGRAM LIMITS . . . . . . ");
            printf("\n. . . . . PASSWORD GENERATOR ENDED . . . . . ");

            break;
        }
        printf("\nHere is your %d characters password: ", total_digits);

        generatePassword(numbers, alphabets, special_characters, user_number, user_alpha, user_special_ch, total_digits);

        passwordStrength(total_digits);
        printf("\n\n");

        printf("Type '2' for new password again and '1' for stopping the program: ");
        scanf("%d", &user_replay);
        if (user_replay == 1)
        {
            replay(user_replay);
            break;
        }

        else
            continue;
    }
}