#include <ctype.h>
#include <stdio.h>

#define SIZE 100

// strlen()
int stringLength(char str[SIZE])
{
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
}

// strcmp()
int stringLengthCompare(char first_str[SIZE], char second_str[SIZE])
{
    if (stringLength(first_str) == stringLength(second_str))
    {
        return 0;
    }
    else if (stringLength(first_str) > stringLength(second_str))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// strcat()
char stringConcatenate(char first_str[SIZE], char second_str[SIZE])
{
    int length = stringLength(first_str) + stringLength(second_str);
    int j = 0;
    for (int i = stringLength(first_str); i < length; i++)
    {
        first_str[i] = second_str[j];
        j++;
    }
    first_str[length] = '\0';
    return first_str[SIZE];
}

// strncat ()
char stringSizeConcatenate(char first_str[SIZE], char second_str[SIZE], int index_size)
{
    int j = stringLength(first_str);
    for (int i = 0; i < index_size; i++)
    {
        first_str[j] = second_str[i];
        j++;
    }
    return first_str[SIZE];
}

// strcpy()
char stringCopy(char first_str[SIZE], char second_str[SIZE])
{
    for (int i = 0; i < stringLength(second_str); i++)
    {
        first_str[i] = second_str[i];
    }
    first_str[stringLength(second_str)] = '\0';
    return first_str[SIZE];
}

// strncpy()
char stringSizeCopy(char first_str[SIZE], char second_str[SIZE], int index_size)
{
    for (int i = 0; i < index_size; i++)
    {
        first_str[i] = second_str[i];
    }
    first_str[index_size] = '\0';
    return first_str[SIZE];
}

// strrev ()
char stringReverse(char first_str[SIZE])
{
    char reverse[SIZE];
    for (int i = 0; i < stringLength(first_str); i++)
    {
        reverse[i] = first_str[i];
    }
    int k = 0;
    for (int j = stringLength(first_str) - 1; j >= 0; j--)
    {
        first_str[j] = reverse[k];
        k++;
    }
    first_str[stringLength(first_str)] = '\0';
    return first_str[SIZE];
}

// strtok()
void stringSplit(char first_str[SIZE], char splitting_character)
{
    // printf("\n");
    for (int i = 0; i < stringLength(first_str); i++)
    {
        if (first_str[i] == splitting_character)
        {
            printf("");
        }
        else
            printf("%c", first_str[i]);
    }
}

// strupr()
char stringUpper(char first_str[SIZE])
{
    for (int i = 0; i < stringLength(first_str); i++)
    {
        first_str[i] = toupper(first_str[i]);
    }
    return first_str[SIZE];
}

// strlwr()
char stringLower(char first_str[SIZE])
{
    for (int i = 0; i < stringLength(first_str); i++)
    {
        first_str[i] = tolower(first_str[i]);
    }
    return first_str[SIZE];
}
