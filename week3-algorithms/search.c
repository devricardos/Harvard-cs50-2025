// Implements linear search for integers - just as lockers sample

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // An array of integers, no need to set its length
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // Search for number "7" fixed loops (magic number)
    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0; // Exit Success
        }
    }
    printf("Not found\n");
    return 1; // Exit Failure
}
