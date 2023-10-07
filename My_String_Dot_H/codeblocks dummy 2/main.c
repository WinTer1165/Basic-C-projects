#include <stdio.h>
#include "betterstring.c"
#define SIZE 100

int main()
{
    // stringLength() - Returns the length of the string: alternative - strlen()
    char str1[SIZE] = "123456789";
    printf("MAIN STRING: %s\n", str1);
    printf("String Length is %d\n", stringLength(str1));

    // stringLengthCompare() - Compares two strings: alternative - strcmp()
    char str2[SIZE] = "Hello World!";
    char str3[SIZE] = "Bye World!";
    printf("First String Length is %d\n", stringLength(str2));
    printf("Second String Length is %d\n", stringLength(str3));
    if (stringLengthCompare(str2, str3) == 0)
    {
        printf("Both strings are equal\n");
    }
    else if (stringLengthCompare(str2, str3) == 1)
    {
        printf("First string is larger\n");
    }
    else if (stringLengthCompare(str2, str3) == -1)
    {
        printf("Second string is larger\n");
    }

    // stringConcatenate() - Concatenates two strings: alternate - strcat()
    char str4[SIZE] = "How are you? ";
    char str5[SIZE] = "I am fine, thank you for asking.";
    printf("FIRST STRING: %s\n", str4);
    printf("SECOND STRING: %s\n", str5);
    stringConcatenate(str4, str5);
    printf("CONCATENATED STRING: %s\n", str4);

    // stringSizeConcatenate() - Concatenates first n characters of one string to another: alternate - strncat ()
    char str6[SIZE] = "123456789";
    char str7[SIZE] = "Welcome to C Programming!";
    printf("FIRST STRING: %s\n", str6);
    printf("SECOND STRING: %s\n", str7);
    stringSizeConcatenate(str7, str6, 3);
    printf("CONCATENATED STRING UPTO %d VALUE: ", 3);
    puts(str7);

    // stringCopy - Copy one string to another: alternate - strcpy()
    char str8[SIZE] = "Don't copy in exam!";
    char str9[SIZE];
    printf("MAIN STRING: %s\n", str8);
    stringCopy(str9, str8);
    printf("COPIED STRING: ");
    puts(str9);

    // stringSizeCopy() - Copy first n characters of one string to another: alternate - strncpy()
    char str10[SIZE] = "123456789";
    char str11[SIZE];
    printf("MAIN STRING: %s\n", str10);
    stringSizeCopy(str11, str10, 5);
    printf("PRINTED UPTO %d VALUE: ", 5);
    puts(str11);

    // stringReverse() - Reverses the given string: alternate - strrev ()
    char str12[SIZE] = "Hello World!";
    printf("MAIN STRING: %s\n", str12);
    stringReverse(str12);
    printf("REVERSED STRING: ");
    puts(str12);

    // stringSplit() - Split the given string into tokens based on some character as a delimiter: alternate - strtok()
    char str13[SIZE] = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z";
    printf("MAIN STRING: %s\n", str13);
    printf("STRING AFTER SPLITTING ',': ");
    stringSplit(str13, ',');

    // stringUpper() - Converts string to uppercase: alternate - strupr()
    // stringLower() - Converts string to uppercase: alternate - strlwr()
    char str14[SIZE] = "C was developed at Bell Laboratories in 1972 by Dennis Ritchie.";
    printf("\nMAIN STRING: %s\n", str14);
    stringUpper(str14);
    printf("TURNING A STRING TO ALL UPPERCASE: ");
    puts(str14);
    stringLower(str14);
    printf("TURNING A STRING TO ALL LOWERCASE: ");
    puts(str14);
}