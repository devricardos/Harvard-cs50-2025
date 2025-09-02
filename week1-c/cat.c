#include <cs50.h>
#include <stdio.h>

// Call the functions, specify if they have inputs and outputs
int get_positive_int(void);
void meow(int n);

int main(void)
{
    // Ask for a positive count
    int times = get_positive_int();
    // Then meow that n times
    meow(times);
}

// Create our positive number function
int get_positive_int(void)
{
    // Loop until we get a positive number
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    // Return the integer number the function asked for
    return n;
}

// Create our function to print cat´s sound n times
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
