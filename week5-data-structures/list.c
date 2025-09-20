// This program demonstrates how to create a list of numbers using a dynamically sized array in C.
// It starts with a list of 3 numbers, resizes it to hold 4 numbers using realloc, and prints the result.

// Include standard libraries for input/output and memory allocation
#include <stdio.h>   // Provides printf for printing to the console
#include <stdlib.h>  // Provides malloc, realloc, and free for dynamic memory allocation

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
        // Exit the program with error code 1
        return 1;
    }

    // Step 3: Initialize the list with 3 numbers
    // Assign values to the first three positions in the array
    list[0] = 1;  // First element
    list[1] = 2;  // Second element
    list[2] = 3;  // Third element

    // Step 4: Resize the list to hold 4 integers using realloc
    // realloc takes the original pointer (list) and new size (4 integers)
    // It copies the old data to the new memory and returns a pointer to the new memory
    int *tmp = realloc(list, 4 * sizeof(int));
    
    // Step 5: Check if realloc failed
    // If realloc returns NULL, the original list is still valid, but we couldn't resize
    if (tmp == NULL)
    {
        // Free the original list to avoid a memory leak
        free(list);
        // Exit the program with error
        return 1;
    }

    // Step 6: Update 'list' to point to the new memory
    // realloc may have moved the memory to a new location, so we update 'list'
    list = tmp;

    // Step 7: Add a new number to the fourth position in the resized list
    // The first 3 numbers (1, 2, 3) are already copied by realloc
    list[3] = 4;  // The list now has 1, 2, 3, 4

    // Step 8: Print all numbers in the list
    // Loop through the 4 elements and print each one
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);  // Print the i-th element followed by a newline
    }

    // Step 9: Free the memory used by the list
    // This prevents a memory leak by releasing the memory back to the system
    free(list);

    // Step 10: Return 0 to indicate the program ran successfully
    return 0;
}
