#include <cs50.h>  // Include CS50 library for string type and other utilities
#include <stdio.h> // Include standard input/output library for printf

int main(int argc, string argv[])  // Main function with argument count (argc) and argument vector (argv)
{
    // Check if the number of command-line arguments is not exactly 2 (program name + 1 argument)
    if (argc != 2)
    {
        // Print error message if argument is missing
        printf("Missing command-line argument\n");
        // Return 1 to indicate an error
        return 1;
    }

    // If we have exactly 2 arguments, print "hello, " followed by the first argument
    printf("hello, %s\n", argv[1]);
    // Return 0 to indicate successful execution
    return 0;
}
