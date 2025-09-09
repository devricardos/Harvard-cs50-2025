// Revamp the code to implement linear search for strings

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // An array of strings (with text now)
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // Search for string
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        // Where magic happens: strcmp to compare strings from string.h
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0; // Success
        }
    }
    printf("Not found\n");
    return 1; // Error
}
