// Prints two strings

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    // char *s declares a variable 's' that points to the first character of a sequence ending with '\0'.
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Print strings
    printf("%s\n", s);
    printf("%s\n", t);

    // Print strings' addresses, we don´t ever use this, but it is possible to go there (see where they are)
    printf("%p\n", s);
    printf("%p\n", t);
}
