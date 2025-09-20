// This program demonstrates how to create a list of numbers using a dynamically sized array in C.
// It starts with a list of 3 numbers, resizes it to hold 4 numbers, and then prints the result.

// Include standard libraries for input/output and memory allocation
#include <stdio.h>   // Provides printf for printing to the console
#include <stdlib.h>  // Provides malloc and free for dynamic memory allocation

int main(void)
{
    // Step 1: Create a list that can hold 3 integers
    // malloc allocates memory for 3 integers (each integer size is sizeof(int))
    // The pointer 'list' will point to this memory
    int *list = malloc(3 * sizeof(int));
    
    // Step 2: Check if memory allocation failed
    // If malloc returns NULL, it means there wasn't enough memory
    if (list == NULL)
    {
        // If allocation fails, exit the program with error
        return 1;
    }

    // Step 3: Initialize the list with 3 numbers
    // Assign values to the first three positions in the array
    list[0] = 1;  // First element
    list[1] = 2;  // Second element
    list[2] = 3;  // Third element

    // Step 4: Create a new list to hold 4 integers
    // Allocate memory for 4 integers and store the pointer in 'tmp'
    int *tmp = malloc(4 * sizeof(int));
    
    // Step 5: Check if the new memory allocation failed
    if (tmp == NULL)
    {
        // If allocation fails, free the original list to avoid memory leaks
        free(list);
        return 1;
    }

    // Step 6: Copy the 3 numbers from the old list to the new list
    // Use a loop to copy each element one by one
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];  // Copy the i-th element from 'list' to 'tmp'
    }

    // Step 7: Add a new number to the fourth position in the new list
    tmp[3] = 4;  // The new list now has 1, 2, 3, 4

    // Step 8: Free the original list
    // Since we copied the numbers to 'tmp', we no longer need the old 'list'
    free(list);

    // Step 9: Update 'list' to point to the new list
    // Now 'list' refers to the memory that 'tmp' points to (the list with 4 numbers)
    list = tmp;

    // Step 10: Print all numbers in the new list
    // Loop through the 4 elements and print each one
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);  // Print the i-th element followed by a newline
    }

    // Step 11: Free the memory used by the new list
    // This prevents a memory leak by releasing the memory back to the system
    free(list);

    // Step 12: Return 0 to indicate the program ran successfully
    return 0;
}
