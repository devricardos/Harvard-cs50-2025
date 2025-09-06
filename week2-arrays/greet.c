#include <cs50.h>  // Include CS50 library for input/output
#include <stdio.h> // Include standard input/output library

int main(int argc, string argv[])
{
    if (argc == 2)     // Check if exactly one command-line argument is provided (plus the program name)
    {
        printf("hello, %s\n", argv[1]); // Print "hello," followed by the first argument if provided (second inside the array)
    }
    else               // If the number of arguments is not 2 (e.g., 1 or more than 2)
    {
        printf("hello, world\n"); // Print "hello, world" as the default message
    }
}
