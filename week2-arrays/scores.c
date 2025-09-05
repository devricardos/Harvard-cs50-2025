#include <cs50.h>
#include <stdio.h>

// Prototype for the function that calculates the average
float average(int length, int array[]);

int main(void)
{
    // Ask the user how many scores they want to enter
    int N = get_int("How many scores do you want to enter? ");

    // Create an array of size N
    int scores[N];

    // Collect scores from the user
    int d = 0;
    for (int i = 0; i < N; i++)
    {
        d = d + 1;
        scores[i] = get_int("Score %d: ", d);
    }

    // Calculate and print the average with 2 decimal places
    printf("Average of %i scores: %.2f\n", N, average(N, scores));
}

// Function to calculate the average of an array of integers
float average(int length, int array[])
{
    int sum = 0;

    // Add all values in the array
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    // Return the average (casting to float to avoid truncation)
    return sum / (float) length;
}
