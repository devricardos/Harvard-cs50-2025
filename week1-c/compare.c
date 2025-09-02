#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user to input two integers
    int x = get_int("What´s x? ");
    int y = get_int("What´s y? ");

    // Compare values
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}
