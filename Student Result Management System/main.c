#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student Result Management System.
// Record marks for students across five subjects, then let the program do
// the maths: total, average, a letter grade, and who the class topper is.
// Results are saved to a file so they stay around between runs.
//
// Tip: run this program from inside its own folder so it can find results.txt.

#define MAX_STUDENTS 200
#define SUBJECTS 5
#define FILE_NAME "results.txt"

// the five subjects every student is graded on
const char *subject_names[SUBJECTS] = {
    "Math", "Physics", "Chemistry", "English", "Programming"};

struct student
{
    int roll;
    char name[50];
    float marks[SUBJECTS];
};

struct student students[MAX_STUDENTS];
int student_count = 0;

// turn an average mark into a simple letter grade
char grade_from_average(float average)
{
    if (average >= 80) return 'A';
    if (average >= 70) return 'B';
    if (average >= 60) return 'C';
    if (average >= 50) return 'D';
    return 'F';
}

float total_marks(struct student *s)
{
    float total = 0;
    for (int i = 0; i < SUBJECTS; i++)
    {
        total += s->marks[i];
    }
    return total;
}

void load_students()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        return;
    }

    while (student_count < MAX_STUDENTS)
    {
        struct student *s = &students[student_count];

        // roll and name are on one line, then the five marks on the next
        if (fscanf(fp, "%d %49[^\n]\n", &s->roll, s->name) != 2)
        {
            break;
        }
        for (int i = 0; i < SUBJECTS; i++)
        {
            fscanf(fp, "%f", &s->marks[i]);
        }
        fscanf(fp, "\n");

        student_count++;
    }

    fclose(fp);
}

void save_students()
{
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL)
    {
        printf("Could not save results to file.\n");
        return;
    }

    for (int i = 0; i < student_count; i++)
    {
        fprintf(fp, "%d %s\n", students[i].roll, students[i].name);
        for (int j = 0; j < SUBJECTS; j++)
        {
            fprintf(fp, "%.2f ", students[i].marks[j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int find_student(int roll)
{
    for (int i = 0; i < student_count; i++)
    {
        if (students[i].roll == roll)
        {
            return i;
        }
    }
    return -1;
}

void add_student()
{
    if (student_count >= MAX_STUDENTS)
    {
        printf("\nNo room for more students.\n");
        return;
    }

    struct student *s = &students[student_count];

    printf("Enter roll number: ");
    scanf("%d", &s->roll);

    if (find_student(s->roll) != -1)
    {
        printf("A student with that roll number already exists.\n");
        return;
    }

    getchar();
    printf("Enter name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    for (int i = 0; i < SUBJECTS; i++)
    {
        printf("Enter marks for %s (0-100): ", subject_names[i]);
        scanf("%f", &s->marks[i]);
    }

    student_count++;
    save_students();
    printf("Student added.\n");
}

// print one student's full result card
void print_result_card(struct student *s)
{
    float total = total_marks(s);
    float average = total / SUBJECTS;

    printf("\nRoll: %d   Name: %s\n", s->roll, s->name);
    for (int i = 0; i < SUBJECTS; i++)
    {
        printf("   %-12s : %.2f\n", subject_names[i], s->marks[i]);
    }
    printf("   Total   : %.2f\n", total);
    printf("   Average : %.2f\n", average);
    printf("   Grade   : %c\n", grade_from_average(average));
}

void display_all()
{
    if (student_count == 0)
    {
        printf("\nNo students recorded yet.\n");
        return;
    }

    for (int i = 0; i < student_count; i++)
    {
        print_result_card(&students[i]);
    }
}

void search_student()
{
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    int index = find_student(roll);
    if (index == -1)
    {
        printf("No student with that roll number.\n");
        return;
    }

    print_result_card(&students[index]);
}

void show_topper()
{
    if (student_count == 0)
    {
        printf("\nNo students recorded yet.\n");
        return;
    }

    int top = 0;
    for (int i = 1; i < student_count; i++)
    {
        if (total_marks(&students[i]) > total_marks(&students[top]))
        {
            top = i;
        }
    }

    printf("\nClass topper:\n");
    print_result_card(&students[top]);
}

void delete_student()
{
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    int index = find_student(roll);
    if (index == -1)
    {
        printf("No student with that roll number.\n");
        return;
    }

    for (int i = index; i < student_count - 1; i++)
    {
        students[i] = students[i + 1];
    }
    student_count--;

    save_students();
    printf("Student deleted.\n");
}

int main()
{
    int choice;

    load_students();
    printf("\n. . . . . STUDENT RESULT MANAGEMENT SYSTEM . . . . .\n");

    while (1)
    {
        printf("\n1. Add a student\n");
        printf("2. Show all results\n");
        printf("3. Search by roll number\n");
        printf("4. Show class topper\n");
        printf("5. Delete a student\n");
        printf("6. Exit\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nGoodbye!\n");
            break;
        }

        switch (choice)
        {
        case 1: add_student();    break;
        case 2: display_all();    break;
        case 3: search_student(); break;
        case 4: show_topper();    break;
        case 5: delete_student(); break;
        case 6:
            printf("\nGoodbye!\n");
            return 0;
        default:
            printf("Please pick a number between 1 and 6.\n");
        }
    }

    return 0;
}
