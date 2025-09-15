// Demonstrates memory errors via valgrind
// Usage: valgrind ./memory
// https://youtu.be/kcRdFGbzR1I?t=5168

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Error 1: should start with x[0]
    // Error 2: should free memory after usage
    int *x = malloc(3 * sizeof(int));
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
    // free (x);
}
