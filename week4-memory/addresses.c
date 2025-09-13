// Prints substrings via pointer arithmetic
#include <stdio.h>

int main(void)
{
    char *s = "HI!"; // Declares a char pointer 's' and assigns it the address of the string literal "HI!", which is stored in read-only memory.
    printf("%s\n", s); // Prints the entire string starting at the address stored in 's' ("HI!").
    printf("%s\n", s + 1); // Prints the string starting at the address 's + 1', which points to the second character ("I!").
    printf("%s\n", s + 2); // Prints the string starting at the address 's + 2', which points to the third character ("!").
}
