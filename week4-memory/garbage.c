// https://youtu.be/kcRdFGbzR1I?t=5556
// Showing garbage (undefined) values stored in memory
// Teach usage of " | less" command line, to show only values that fit screen
// tap space to show more, and "q" to quit

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declare an array of 1024 integers with automatic storage duration
    // Since it's not initialized, the values in the array are undefined (garbage)
    int scores[1024];

    // Loop through the array and print each element
    for (int i = 0; i < 1024; i++)
    {
        // Printing the value of scores[i]
        // These values are garbage (undefined) because the array was not initialized
        printf("%i\n", scores[i]);
    }

    return 0;
}
