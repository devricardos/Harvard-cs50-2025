//https://youtu.be/kcRdFGbzR1I?t=4134

// Include necessary libraries
#include <cs50.h>
#include <ctype.h>   // Provides toupper() to capitalize characters
#include <stdio.h>
#include <stdlib.h>  // Provides malloc() and free() for heap memory management
#include <string.h>  // Provides strlen() and strcpy() for string operations

int main(void)
{
    // Get a string
    // This string is dynamically allocated on the heap by get_string()
    char *s = get_string("s: ");

    // Check if get_string() failed (returns NULL if it can't allocate memory)
    // This prevents dereferencing a NULL pointer
    if (s == NULL)
    {
        return 1; // Exit with error code 1
    }

    // Allocate memory on the heap for a new string 't'
    // strlen(s) gives the length of s (excluding the null terminator)
    // Add 1 to include space for the null terminator ('\0')
    char *t = malloc(strlen(s) + 1);

    // Check if malloc() failed to allocate memory (returns NULL if it fails)
    // This ensures we don't try to use invalid memory
    if (t == NULL)
    {
        return 1; // Exit with error code 1
    }

    // Copy the contents of string s into the newly allocated memory for t
    // strcpy() copies the entire string, including the null terminator
    strcpy(t, s);

    // Capitalize the first character of the copied string t
    // Check if the string length is greater than 0 to avoid accessing empty strings
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]); // Convert the first character to uppercase
    }

    // Print both the original string (s) and the modified copy (t)
    // s remains unchanged, t has its first character capitalized
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Free the heap memory allocated for t to prevent a memory leak
    // Note: We don't free s because get_string() manages its memory (CS50-specific)
    free(t);

    // Return 0 to indicate successful program execution
    return 0;
}
