// Swap two integers by reference (pass-by-reference/ pass-by-address)
// https://youtu.be/kcRdFGbzR1I?t=6757
// Real use of pointers and pointee (Blinky video: https://youtu.be/kcRdFGbzR1I?t=5753)

#include <stdio.h>

// Function prototype for swap, which takes two integer pointers
void swap(int *a, int *b);

int main(void)
{
    int x = 1; // Initialize x to 1
    int y = 2; // Initialize y to 2

    printf("x is %i, y is %i\n", x, y); // Print initial values
    swap(&x, &y); // Call swap with addresses of x and y to swap their values
    printf("x is %i, y is %i\n", x, y); // Print values after swap (x and y are swapped)
}

// Swaps two integers using pointers to modify the original variables
void swap(int *a, int *b)
{
    int tmp = *a; // Store value at address a in temporary variable
    *a = *b;      // Assign value at address b to address a
    *b = tmp;     // Assign tmp (original value of a) to address b
    // Changes affect the original variables in main via pointers
}
