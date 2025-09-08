// Problem Set Details - week2 - https://cs50.harvard.edu/x/psets/2/caesar/
// Include necessary libraries
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if the user provided exactly 1 command-line argument (the key).
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; // Exit with error if no key or too many arguments are given
    }

    // Check if argv[1] contains only digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key (key must be a number)\n");
            return 1; // Exit with error if any character is not a digit
        }
    }

    // Convert the key (command-line argument 2) from a string to an integer.
    // atoi = ASCII to integer (from stdlib.h).
    int key = atoi(argv[1]);

    // Make sure the key is a positive integer.
    if (key < 0)
    {
        printf("Key must be a positive integer.\n");
        return 1; // Exit with error if key is negative.
    }

    // Ask the user for the text they want to encrypt.
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Loop through each character of the plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Accessing the characters
        // Retrieves the character at index i from plaintext and stores it in variable c
        char c = plaintext[i];

        // If character is an uppercase letter
        if (isupper(c))
        {
            // Our main concept: shift it by the key, wrapping around with modulo 26
            // ASCII values for A–Z are contiguous
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
        // If character is a lowercase letter
        else if (islower(c))
        {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        }
        // If character is not a uppercase or lowercase letter, leave it unchanged
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0; // Exit with success!
}
