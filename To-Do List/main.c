#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// To-Do List.
// A simple task manager that saves your tasks to a file, so they are still
// there the next time you run the program. You can add tasks, view them,
// and delete one when it is done.
//
// Tip: run this program from inside its own folder so it can find tasks.txt.

#define MAX_TASKS 100
#define MAX_LENGTH 100
#define FILE_NAME "tasks.txt"

char tasks[MAX_TASKS][MAX_LENGTH];
int task_count = 0;

// load any saved tasks from the file into memory
void load_tasks()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        // no file yet just means there are no tasks to load
        return;
    }

    while (task_count < MAX_TASKS && fgets(tasks[task_count], MAX_LENGTH, fp) != NULL)
    {
        // strip the trailing newline that fgets keeps
        tasks[task_count][strcspn(tasks[task_count], "\n")] = '\0';
        task_count++;
    }

    fclose(fp);
}

// write the current tasks back to the file
void save_tasks()
{
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL)
    {
        printf("Could not save tasks to file.\n");
        return;
    }

    for (int i = 0; i < task_count; i++)
    {
        fprintf(fp, "%s\n", tasks[i]);
    }

    fclose(fp);
}

void view_tasks()
{
    if (task_count == 0)
    {
        printf("\nYour to-do list is empty.\n");
        return;
    }

    printf("\nYour tasks:\n");
    for (int i = 0; i < task_count; i++)
    {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void add_task()
{
    if (task_count >= MAX_TASKS)
    {
        printf("\nYour list is full.\n");
        return;
    }

    printf("Enter the new task: ");
    getchar(); // clear the leftover newline before reading a full line
    fgets(tasks[task_count], MAX_LENGTH, stdin);
    tasks[task_count][strcspn(tasks[task_count], "\n")] = '\0';
    task_count++;

    save_tasks();
    printf("Task added.\n");
}

void delete_task()
{
    int number;

    view_tasks();
    if (task_count == 0)
    {
        return;
    }

    printf("Which task number do you want to delete? ");
    scanf("%d", &number);

    if (number < 1 || number > task_count)
    {
        printf("That task number does not exist.\n");
        return;
    }

    // shift every task after the deleted one up by a position
    for (int i = number - 1; i < task_count - 1; i++)
    {
        strcpy(tasks[i], tasks[i + 1]);
    }
    task_count--;

    save_tasks();
    printf("Task deleted.\n");
}

int main()
{
    int choice;

    load_tasks();
    printf("\n. . . . . TO-DO LIST . . . . .\n");

    while (1)
    {
        printf("\n1. View tasks\n");
        printf("2. Add task\n");
        printf("3. Delete task\n");
        printf("4. Exit\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nGoodbye!\n");
            break;
        }

        switch (choice)
        {
        case 1:
            view_tasks();
            break;
        case 2:
            add_task();
            break;
        case 3:
            delete_task();
            break;
        case 4:
            printf("\nGoodbye!\n");
            return 0;
        default:
            printf("Please pick a number between 1 and 4.\n");
        }
    }

    return 0;
}
