#include <cs50.h>  // Include CS50 library for input/output
#include <stdio.h> // Include standard input/output library

// Function prototype to calculate string length
int string_length(string s);

int main(void)
{
    string name = get_string("Enter a Name: "); // Get input string from user
    int length = string_length(name);   // Call function to get length of the string
    printf("%i\n", length);             // Print the length of the string
}

int string_length(string s)
{
    int n = 0;           // Initialize counter for string length
    while (s[n] != '\0') // Loop until null terminator is reached
    {
        n++; // Increment counter for each character
    }
    return n; // Return the total length
}
