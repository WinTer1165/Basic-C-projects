#include <stdio.h>

// A simple menu-driven calculator.
// It keeps running until the user chooses to exit, so you can do
// one calculation after another without restarting the program.

void welcome_message()
{
    printf("\n. . . . . SIMPLE CALCULATOR . . . . .\n");
}

// print the menu of operations
void show_menu()
{
    printf("\nChoose an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
    printf("Your choice: ");
}

int main()
{
    int choice;
    double first_number, second_number;

    welcome_message();

    while (1)
    {
        show_menu();

        // read the menu choice; if it is not a number, stop the program
        if (scanf("%d", &choice) != 1)
        {
            printf("\nThat was not a valid choice. Goodbye!\n");
            break;
        }

        if (choice == 5)
        {
            printf("\nThanks for using the calculator. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 5)
        {
            printf("\nPlease pick a number between 1 and 5.\n");
            continue;
        }

        printf("Enter the first number: ");
        scanf("%lf", &first_number);
        printf("Enter the second number: ");
        scanf("%lf", &second_number);

        switch (choice)
        {
        case 1:
            printf("Result: %.2lf\n", first_number + second_number);
            break;
        case 2:
            printf("Result: %.2lf\n", first_number - second_number);
            break;
        case 3:
            printf("Result: %.2lf\n", first_number * second_number);
            break;
        case 4:
            // guard against dividing by zero
            if (second_number == 0)
            {
                printf("You cannot divide by zero.\n");
            }
            else
            {
                printf("Result: %.2lf\n", first_number / second_number);
            }
            break;
        }
    }

    return 0;
}
