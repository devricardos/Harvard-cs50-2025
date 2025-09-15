// Fails to swap two integers
// https://youtu.be/kcRdFGbzR1I?t=5948

#include <stdio.h>

// Function prototype for swap, which takes two integers
void swap(int a, int b);

int main(void)
{
    int x = 1; // Initialize x to 1
    int y = 2; // Initialize y to 2

    printf("x is %i, y is %i\n", x, y); // Print initial values
    swap(x, y); // Call swap to attempt swapping x and y
    printf("x is %i, y is %i\n", x, y); // Print values after swap (unchanged due to pass-by-value)
}

// Attempts to swap two integers, but doesn't work because C uses pass-by-value
// swap values, just like the glasses of water on class
void swap(int a, int b)
{
    int tmp = a; // Store a in temporary variable
    a = b;       // Assign b's value to a
    b = tmp;     // Assign tmp (original a) to b
    // Changes are local to a and b, so x and y in main are unaffected
}
