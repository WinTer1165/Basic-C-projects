#include <stdio.h>
#include <ctype.h>

// Morse Code Translator.
// Turns plain English text into Morse code. Each letter and digit has a
// pattern of dots and dashes. Letters are separated by a space and words
// are separated by a slash, which is a common way to write Morse.

#define MAX_TEXT 1000

// Morse patterns for A-Z stored in order, so 'A' is index 0, 'B' is 1, etc.
const char *letters[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Morse patterns for digits 0-9, where '0' is index 0.
const char *digits[10] = {
    "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."};

int main()
{
    char text[MAX_TEXT];

    printf("\n. . . . . MORSE CODE TRANSLATOR . . . . .\n");
    printf("Enter text to translate: ");
    fgets(text, MAX_TEXT, stdin);

    printf("\nMorse code:\n");

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (isalpha(c))
        {
            printf("%s ", letters[toupper(c) - 'A']);
        }
        else if (isdigit(c))
        {
            printf("%s ", digits[c - '0']);
        }
        else if (c == ' ')
        {
            // a slash marks the gap between words
            printf("/ ");
        }
        // any other character (like punctuation) is simply skipped
    }

    printf("\n");

    return 0;
}
