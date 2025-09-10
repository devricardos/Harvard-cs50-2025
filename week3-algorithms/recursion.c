// Draws a pyramid using recursion (function that calls itself)
// CS50x 2025 - Lecture 3 - Algorithms
// https://youtu.be/iCx3zwK8Ms8?list=PLhQjrBD2T383q7Vn8QnTsVgSvyLpsqL_R&t=6158

#include <cs50.h>
#include <stdio.h>

// Function to draw a pyramid of height n
void draw(int n);

int main(void)
{
    // Prompt user for the pyramid's height
    int height = get_int("Height: ");

    // Call function to draw the pyramid
    draw(height);

    return 0;
}

// Recursively draws a right-aligned pyramid of hashtags
void draw(int n)
{
    // Base case is always necessary when using recursion function: if height is 0, stop recursion
    if (n == 0)
    {
        return; //  Doesn´t print (pyramid of height 0)
    }

    // Recursively draw a smaller pyramid of height n-1
    draw(n - 1);

    // Print a row of n hashtags followed by a newline
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
