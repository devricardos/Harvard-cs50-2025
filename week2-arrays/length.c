#include <cs50.h>  // Include CS50 library for input/output
#include <stdio.h> // Include standard input/output library
#include <string.h> // Included now to use the strlen function

// Function prototype to calculate string length
int string_length(string s);

int main(void)
{
    string name = get_string("Enter a Name: "); // Get input string from user
    int length = strlen(name);   // Call function strlen that comes with <string.h>
    printf("%i\n", length);             // Print the length of the string
}
