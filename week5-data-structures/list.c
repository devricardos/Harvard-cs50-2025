// This program demonstrates how to create a linked list in C by prepending nodes.
// A linked list is a data structure where each element (node) contains data and a pointer to the next node.

// Include necessary libraries
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
// A node contains an integer (number) and a pointer to the next node
typedef struct node
{
    int number;          // The data stored in this node (an integer)
    struct node *next;   // Pointer to the next node in the list
} node;                  // Name of the structure is 'node'

// The main function is where the program starts
int main(void)
{
    // Step 1: Initialize an empty linked list
    // 'list' is a pointer to the first node; set to NULL since the list is empty
    node *list = NULL;

    // Step 2: Loop to create 3 nodes and add them to the list
    // We'll ask the user for 3 numbers and prepend each as a new node
    for (int i = 0; i < 3; i++)
    {
        // Step 3: Allocate memory for a new node
        // malloc reserves space for one node (size of the node structure)
        node *n = malloc(sizeof(node));

        // Step 4: Check if memory allocation failed
        if (n == NULL)
        {
            // Exit the program with error code 1
            return 1;
        }

        // Step 5: Initialize the new node
        // Ask the user for a number and store it in the node's 'number' field
        n->number = get_int("Number: ");
        // Set the node's 'next' pointer to NULL (no next node yet)
        n->next = NULL;

        // Step 6: Prepend the new node to the list
        // Make the new node's 'next' pointer point to the current head of the list
        n->next = list;
        // Update the head of the list to point to the new node
        list = n;
    }

    // Step 7: Return 0 to indicate the program ran successfully
    return 0;
}
