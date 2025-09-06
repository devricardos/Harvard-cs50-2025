#include <cs50.h>    // Bring in the CS50 library to help with easy input/output
#include <ctype.h>   // Include the ctype library for character handling functions like toupper (NEW)
#include <stdio.h>   // Include the standard input/output library for basic printing
#include <string.h>  // Add the string library to use the strlen function

int main(void)
{
    string s = get_string("Before: "); // Ask the user to type something and store it as a string
    printf("After: ");                 // Show "After: " to prepare for printing the result

    for (int i = 0, n = strlen(s); i < n; i++) // Loop through each character: start at 0, go up to the string length
    {
        printf("%c", toupper(s[i]));    // Print each character converted to uppercase (first use of it)
    }
    printf("\n");                      // Add a new line at the end for neatness
}
