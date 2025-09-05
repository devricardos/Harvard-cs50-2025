#include <cs50.h>  // Include CS50 library for input/output
#include <stdio.h> // Include standard input/output library

int main(void)
{
    string words[2];  // Declare an array of 2 strings
    words[0] = "HI!"; // Assign "HI!" to the first string
    words[1] = "BYE!"; // Assign "BYE!" to the second string

    // Proving that the strings are just arrays
    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]); // Print the first 3 characters of words[0]
    printf("%c%c%c\n", words[1][0], words[1][1], words[1][2]); // Print the first 3 characters of words[1]
}
