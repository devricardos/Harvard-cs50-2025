// Draws mario´s pyramid using iteration
// CS50x 2025 - Lecture 3 - Algorithms
// https://youtu.be/iCx3zwK8Ms8?list=PLhQjrBD2T383q7Vn8QnTsVgSvyLpsqL_R&t=5931

#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    // Get height of pyramid
    int height = get_int("Height: ");

    // Draw pyramid
    draw(height);
}

void draw(int n)
{
    // Draw pyramid of height n, i up to n
    // Loop through each row
    for (int i = 0; i < n; i++)
    {
        // Inside each row how many briks I want? Condition for each print j < i + 1
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
