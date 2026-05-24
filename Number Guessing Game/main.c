#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Number Guessing Game.
// The computer picks a secret number between 1 and 100 and you try to
// guess it. After each guess you are told whether to go higher or lower,
// and at the end the program tells you how many tries it took.

#define LOWEST 1
#define HIGHEST 100

void welcome_message()
{
    printf("\n. . . . . NUMBER GUESSING GAME . . . . .\n");
    printf("I am thinking of a number between %d and %d.\n", LOWEST, HIGHEST);
    printf("Can you guess it?\n\n");
}

int main()
{
    int secret_number, guess, attempts = 0;

    // seed the random generator so the number is different each run
    srand(time(NULL));
    secret_number = rand() % HIGHEST + LOWEST;

    welcome_message();

    while (1)
    {
        printf("Enter your guess: ");

        // if the input is not a number, end the game politely
        if (scanf("%d", &guess) != 1)
        {
            printf("\nThat was not a number. The answer was %d.\n", secret_number);
            break;
        }

        attempts++;

        if (guess < secret_number)
        {
            printf("Too low. Try a higher number.\n");
        }
        else if (guess > secret_number)
        {
            printf("Too high. Try a lower number.\n");
        }
        else
        {
            printf("\nCorrect! You guessed it in %d attempt(s).\n", attempts);
            break;
        }
    }

    return 0;
}
