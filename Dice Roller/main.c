#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dice Roller.
// Rolls one or more six-sided dice and draws each result as a little dice
// face made of text. Roll again as many times as you like.

// draw a single dice face (1 to 6) using ASCII art
void draw_dice(int value)
{
    // each row of the face, chosen based on the rolled value
    char *top[7] =    {"", "         ", "  o      ", "  o      ", "  o   o  ", "  o   o  ", "  o   o  "};
    char *middle[7] = {"", "    o    ", "         ", "    o    ", "         ", "    o    ", "  o   o  "};
    char *bottom[7] = {"", "         ", "      o  ", "      o  ", "  o   o  ", "  o   o  ", "  o   o  "};

    printf(" ---------\n");
    printf("|%s|\n", top[value]);
    printf("|%s|\n", middle[value]);
    printf("|%s|\n", bottom[value]);
    printf(" ---------\n");
}

int main()
{
    int dice_count, again;

    srand(time(NULL));

    printf("\n. . . . . DICE ROLLER . . . . .\n");

    do
    {
        printf("\nHow many dice do you want to roll? ");
        scanf("%d", &dice_count);

        if (dice_count < 1)
        {
            printf("Please roll at least one die.\n");
            continue;
        }

        int total = 0;
        for (int i = 0; i < dice_count; i++)
        {
            int roll = rand() % 6 + 1; // a number from 1 to 6
            total += roll;
            printf("\nDie %d rolled a %d:\n", i + 1, roll);
            draw_dice(roll);
        }

        printf("\nTotal: %d\n", total);

        printf("\nRoll again? (1 = yes, 0 = no): ");
        scanf("%d", &again);

    } while (again == 1);

    printf("\nThanks for playing!\n");

    return 0;
}
