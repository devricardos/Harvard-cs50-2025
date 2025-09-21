// Implements a sorted linked list of numbers
// https://cs50.harvard.edu/x/weeks/5/
// https://youtu.be/aV8LlSmd1E8?t=4767

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// Define a structure called 'node' to represent each element in a linked list
typedef struct node
{
    int number;         // Stores an integer value
    struct node *next;  // Pointer to the next node in the list
} node;

// Declare the unload function to free memory used by the linked list
void unload(node *list);

// Main function where the program starts
int main(void)
{
    // Create a pointer to the start of the linked list, initially set to NULL (empty list)
    node *list = NULL;

    // Loop to get 3 numbers from the user to build the linked list
    for (int i = 0; i < 3; i++)
    {
        // Allocate memory for a new node
        node *n = malloc(sizeof(node));
        // Check if memory allocation failed
        if (n == NULL)
        {
            // If allocation fails, free the existing list and exit
            unload(list);
            return 1;
        }
        // Get a number from the user and store it in the node's number field
        n->number = get_int("Number: ");
        // Set the new node's next pointer to NULL (it doesn't point to anything yet)
        n->next = NULL;

        // If the list is empty, make the new node the first node in the list
        if (list == NULL)
        {
            list = n;
        }
        // If the new number is smaller than the first number in the list
        else if (n->number < list->number)
        {
            // Make the new node point to the current list
            n->next = list;
            // Update the list to start with the new node
            list = n;
        }
        // If the new number belongs somewhere else in the list
        else
        {
            // Loop through the list to find the right place for the new node
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If we're at the end of the list
                if (ptr->next == NULL)
                {
                    // Add the new node to the end
                    ptr->next = n;
                    break; // Exit the loop since we added the node
                }
                // If the new number is smaller than the next node's number
                if (n->number < ptr->next->number)
                {
                    // Insert the new node between the current node and the next node
                    n->next = ptr->next;
                    ptr->next = n;
                    break; // Exit the loop since we added the node
                }
            }
        }
    }

    // Print all numbers in the list, they will be printed in ascending order
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        // Print the number stored in the current node
        printf("%i\n", ptr->number);
    }

    // Free the memory used by the linked list
    unload(list);
    return 0;
}

// Function to free the memory used by the linked list
void unload(node *list)
{
    // Start with the first node
    node *ptr = list;
    // Keep going until we reach the end of the list
    while (ptr != NULL)
    {
        // Save the pointer to the next node
        node *next = ptr->next;
        // Free the current node's memory
        free(ptr);
        // Move to the next node
        ptr = next;
    }
}
