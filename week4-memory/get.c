// Dangerously gets a string from user using scanf with array
#include <stdio.h>

int main(void)
{
    char s[4]; // Declare a char array to store a string (limited to 3 characters + null terminator)
    printf("s: "); // Prompt user for input
    scanf("%s", s); // Read string input into s (dangerous: no bounds checking)
    printf("s: %s\n", s); // Print the stored string
}

// Final result was: "Segmentation fault (core dumped)"
