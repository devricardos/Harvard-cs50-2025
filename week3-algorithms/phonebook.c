// Implements a phone book without structs
// CS50x 2025 - Lecture 3 - Algorithms
// https://youtu.be/iCx3zwK8Ms8?list=PLhQjrBD2T383q7Vn8QnTsVgSvyLpsqL_R&t=3003

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Arrays of strings name and numbers
    string names[] = {"Yuliia", "David", "John"};
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        // strcmp from string.h to compare strings, inputed name vs names array
        if (strcmp(names[i], name) == 0)
        {
            // Return the number from the same location of the name array
            printf("Found %s\n", numbers[i]);
            return 0; // Success
        }
    }
    printf("Not found\n");
    return 1; // Error
}
