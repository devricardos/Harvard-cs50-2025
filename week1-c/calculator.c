#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declares an integer x and y and assigns it the value entered by the user
    int x = get_int("x: ");
    int y = get_int("y: ");
    // Prints the result of x divided by y, cast to a float for decimal output, with up to 2 decimal places (%.2f).
    printf("%.2f\n", (float) x / y);
}
