#include <cs50.h>
#include <stdio.h>

// Prototypes
int get_positive_int(string prompt);
void print_pyramid(int height);

int main(void)
{
    // Ask the user for the height
    int height = get_positive_int("Height up to 12: ");

    // Print the pyramid
    print_pyramid(height);
}

// Ask for a number between 1 and 8
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 12);
    return n;
}

// Print a double half-pyramid
void print_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        // Print spaces (left padding)
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Left pyramid blocks
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Middle gap (2 spaces)
        printf("  ");

        // Right pyramid blocks
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // New line
        printf("\n");
    }
}
