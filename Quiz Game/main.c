#include <stdio.h>

// Quiz Game.
// A short multiple-choice quiz. You answer each question with a, b, c, or d,
// and at the end you get your score and a little message based on how you did.

#define TOTAL_QUESTIONS 5

int main()
{
    // the questions, their options, and the correct answer letter
    char *questions[TOTAL_QUESTIONS] = {
        "Which keyword is used to define a constant in C using the preprocessor?",
        "What is the size of a char in C (in bytes)?",
        "Which symbol is used to get the address of a variable?",
        "Which function reads formatted input from the keyboard?",
        "What does the '\\n' character do?"};

    char *options[TOTAL_QUESTIONS][4] = {
        {"a) const", "b) #define", "c) static", "d) final"},
        {"a) 1", "b) 2", "c) 4", "d) 8"},
        {"a) *", "b) &", "c) #", "d) @"},
        {"a) printf", "b) gets", "c) scanf", "d) puts"},
        {"a) Adds a tab", "b) Ends the program", "c) Moves to a new line", "d) Nothing"}};

    char answers[TOTAL_QUESTIONS] = {'b', 'a', 'b', 'c', 'c'};

    char user_answer;
    int score = 0;

    printf("\n. . . . . C PROGRAMMING QUIZ . . . . .\n");
    printf("Answer each question with a, b, c, or d.\n");

    for (int i = 0; i < TOTAL_QUESTIONS; i++)
    {
        printf("\nQuestion %d: %s\n", i + 1, questions[i]);
        for (int j = 0; j < 4; j++)
        {
            printf("   %s\n", options[i][j]);
        }

        printf("Your answer: ");
        scanf(" %c", &user_answer);

        if (user_answer == answers[i])
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Wrong. The correct answer was %c.\n", answers[i]);
        }
    }

    printf("\nYou scored %d out of %d.\n", score, TOTAL_QUESTIONS);

    if (score == TOTAL_QUESTIONS)
    {
        printf("Perfect score! You really know your C.\n");
    }
    else if (score >= TOTAL_QUESTIONS / 2)
    {
        printf("Nice work. Keep practicing!\n");
    }
    else
    {
        printf("Keep studying, you will get there.\n");
    }

    return 0;
}
