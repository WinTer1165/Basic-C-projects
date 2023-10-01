/*
Weather Station:
Write a program that reads:
        1. Temperature from user for 7 days
        2. Calculates and prints:
                a. Average Temperature
                b. Hottest Day of the week
                c. Coldest Day of the week
#CHALLENGE: SOLVE USING FUNCTION
*/

#include <stdio.h>
// defining multiple constant value with #define (NAME) (VALUE)
#define ARRAY_SIZE 7
#define CHAR_SIZE 10

// creating an array in this function inputData()
// using loop to input each value individually
// returning array values to main function
double inputData(double array_func_temp[ARRAY_SIZE])
{
    printf("\n");
    printf("  WELCOME TO WEATHER STATION\n");
    printf("ENTER LAST WEEK'S TEMPERATURES\n");
    printf("\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {

        if (i == 0)
        {
            printf("Enter Sunday Temperature    : ");
        }
        else if (i == 1)
        {
            printf("Enter Monday Temperature    : ");
        }
        else if (i == 2)
        {
            printf("Enter Tuesday Temperature   : ");
        }
        else if (i == 3)
        {
            printf("Enter Wednesday Temperature : ");
        }
        else if (i == 4)
        {
            printf("Enter Thursday Temperature  : ");
        }
        else if (i == 5)
        {
            printf("Enter Friday Temperature    : ");
        }
        else if (i == 6)
        {
            printf("Enter Saturday Temperature  : ");
        }
        scanf("%lf", &array_func_temp[i]);
    }
    return array_func_temp[ARRAY_SIZE];
}

// getting average temperature from averageTemp() function
// using loop to calculate sum of array values
// returning average to main() function
double averageTemp(double array_func_temp[ARRAY_SIZE])
{

    double average, sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum += array_func_temp[i];
    }
    average = (sum / ARRAY_SIZE);
    return average;
}

// getting hottest day and temperature by running array items in a loop and
// using if condition for finding maximum value
// printing hottest day
// returning max temperature to main() function
double hottestDay(double array_func_temp[ARRAY_SIZE])
{
    double max = array_func_temp[0];
    int index = 0;
    char array_DAYS[ARRAY_SIZE][CHAR_SIZE] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (array_func_temp[i] > max)
        {
            max = array_func_temp[i];
            index = i;
        }
    }
    printf("\nHottest day is %s.", array_DAYS[index]);
    return max;
}

// getting coldest day and temperature by running array items in a loop and
// using if condition for finding maximum value
// printing coldest day
// returning min temperature to main() function
double coldestDay(double array_func_temp[ARRAY_SIZE])
{
    double min = array_func_temp[0];
    int index = 0;
    char array_DAYS[ARRAY_SIZE][CHAR_SIZE] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (array_func_temp[i] < min)
        {
            min = array_func_temp[i];
            index = i;
        }
    }
    printf("\nColdest day is %s.", array_DAYS[index]);
    return min;
}

// main() function connected with all other user defined function
int main()
{
    // making array
    double array_Temperature[ARRAY_SIZE];
    // calling array to main function
    // you can call it a small oop
    inputData(array_Temperature);
    // printing arrays for no reason at all
    printf("\nAll temperature in array: {");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%.2lf  ", array_Temperature[i]);
    }
    printf("}");
    // you already know whats happening here
    printf("\n\n\nAverage Temperature: %.2lf Celsius.\n", averageTemp(array_Temperature));
    printf("\nHottest day temperature: %.2lf Celsius.\n", hottestDay(array_Temperature));
    printf("\nColdest day temperature: %.2lf Celsius.", coldestDay(array_Temperature));
}