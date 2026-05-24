#include <stdio.h>
#include <ctype.h>

// Caesar Cipher.
// One of the oldest ways to hide a message: shift every letter forward
// by a fixed amount. With a shift of 3, 'a' becomes 'd', 'b' becomes 'e',
// and so on. To decrypt, you just shift back by the same amount.

#define MAX_TEXT 1000

// shift a single line of text by 'shift' positions.
// letters wrap around the alphabet; anything else is left untouched.
void caesar_shift(char text[MAX_TEXT], int shift)
{
    // keep the shift inside 0..25 and handle negative shifts cleanly
    shift = ((shift % 26) + 26) % 26;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (islower(c))
        {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        }
        else if (isupper(c))
        {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
    }
}

int main()
{
    char text[MAX_TEXT];
    int choice, shift;

    printf("\n. . . . . CAESAR CIPHER . . . . .\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    printf("Enter the shift amount: ");
    scanf("%d", &shift);

    // clear the leftover newline so fgets reads the real line
    getchar();

    printf("Enter your message: ");
    fgets(text, MAX_TEXT, stdin);

    // decrypting is just shifting in the opposite direction
    if (choice == 2)
    {
        shift = -shift;
    }

    caesar_shift(text, shift);

    printf("\nResult: %s\n", text);

    return 0;
}
