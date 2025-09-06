#include <cs50.h>  // Bring in the CS50 library to help with easy input/output
#include <stdio.h> // Include the standard input/output library for basic printing
#include <string.h> // Add the string library to use the strlen function

int main(void)
{
    string s = get_string("Input:  "); // Ask the user to type something and store it as a string
    printf("Output: ");             // Show "Output: " to prepare for printing the result

    for (int i = 0, n = strlen(s); i < n; i++) // Loop through each character: start at 0, go up to the string length
    {
        printf("%c", s[i]);         // Print each character one by one
    }
    printf("\n");                   // New line just to look better
}
