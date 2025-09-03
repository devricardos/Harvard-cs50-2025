#include <stdio.h>

// Telling the compiler that this function exists, allowing it to be called before its definition
void print_row(int n);

// Our main function
int main(void)
{
    // Learning how to declares a constant integer n
    const int n = 3;

    // Print n rows
    for (int i = 0; i < n; i++)
    {
        print_row(n);
    }
}

// Definition of the print_row function we declared earlier
void print_row(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    // move to the next line after finishing one row
    printf("\n");
}
