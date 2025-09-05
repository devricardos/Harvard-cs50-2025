#include <cs50.h> // Include CS50 library to use get_int for user input
#include <stdio.h> // Include standard input/output library for printf

// Function prototype to tell the compiler about print_column before it's used
void print_column(int height);

int main(void)
{
    // Ask the user for a height value and store it in variable h
    int h = get_int("Height: ");
    // Call the print_column function, passing the user-provided height
    print_column(h);
}

// Function to print a column of # characters
void print_column(int height)
{
    // Loop to print a # character on a new line, height+1 times
    // Note: the loop is buggy because it should be < height, not <= height
    for (int i = 0; i <= height; i++)
    {
        printf("#\n"); // Print a single # followed by a newline
    }
}
