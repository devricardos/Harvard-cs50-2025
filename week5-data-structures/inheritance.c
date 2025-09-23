// Simulate genetic inheritance of blood type - CS50 Pset 5
// https://cs50.harvard.edu/x/psets/5/inheritance/
// This program creates a family tree with 3 generations, where each person inherits blood type
// alleles (A, B, or O) from their parents. Concepts: structs (to represent people), pointers (to
// link parents), recursion (to build the tree), and dynamic memory (malloc/free).

#define _DEFAULT_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent a person (Week 5: Structs)
// Each person has two parents (pointers to other person structs) and two alleles (blood type genes)
typedef struct person
{
    struct person *parents[2]; // Array of pointers to two parent structs
    char alleles[2];           // Array for two alleles (e.g., 'A', 'B', or 'O')
} person;

const int GENERATIONS = 3;   // Number of generations to create (child + parent  + grandparent)
const int INDENT_LENGTH = 4; // Spaces for indentation when printing the family tree

// Function prototypes (declaring functions we'll define later)
person *create_family(int generations);       // Creates the family tree
void print_family(person *p, int generation); // Prints the family tree
void free_family(person *p);                  // Frees memory used by the family tree
char random_allele();                         // Returns a random blood type allele (A, B, or O)

int main(void)
{
    // Seed the random number generator (Week 5: Using time to make random numbers less predictable)
    srandom(time(0));

    // Create a family tree with 3 generations (Recursion to build the tree)
    person *p = create_family(GENERATIONS);

    // Print the family tree, starting from generation 0 (the child)
    print_family(p, 0);

    // Free the memory used by the family tree (Avoid memory leaks with free())
    // https://youtu.be/9p7ddI3ozTY?t=279
    free_family(p);

    return 0;
}

// Create a new individual with `generations` levels of ancestors (Recursion and dynamic memory)
// This function builds the family tree recursively, creating parents for each person until the
// specified number of generations is reached. https://youtu.be/9p7ddI3ozTY?t=375
person *create_family(int generations)
{
    // Allocate memory for a new person (malloc to create a struct dynamically)
    person *new_person = malloc(sizeof(person));
    if (new_person == NULL) // Check if memory allocation failed
    {
        return NULL; // Return NULL if we can't allocate memory
    }

    // If there are still generations left to create (parents or grandparents)
    if (generations > 1)
    {
        // Recursively create two parents (Recursion to build the tree upward)
        // https://youtu.be/9p7ddI3ozTY?t=401
        new_person->parents[0] = create_family(generations - 1); // Create first parent
        new_person->parents[1] = create_family(generations - 1); // Create second parent

        // Randomly assign alleles based on parents' alleles (Week 5: Using pointers to access
        // parent data) Each parent contributes one random allele to the child
        new_person->alleles[0] =
            new_person->parents[0]->alleles[random() % 2]; // Pick one of parent0's alleles
        new_person->alleles[1] =
            new_person->parents[1]->alleles[random() % 2]; // Pick one of parent1's alleles
    }
    // Base case: no more generations to create (top-level ancestors)
    else
    {
        // Set parent pointers to NULL (no parents for top-level ancestors)
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        // Randomly assign alleles for this person
        new_person->alleles[0] = random_allele(); // First allele
        new_person->alleles[1] = random_allele(); // Second allele
    }

    // Return the newly created person (Week 5: Returning a pointer to the struct)
    return new_person;
}

// Free memory for a person and all their ancestors
// https://youtu.be/9p7ddI3ozTY?t=515
void free_family(person *p)
{
    // Base case: if person is NULL, nothing to free
    if (p == NULL)
    {
        return;
    }

    // Recursively free both parents (Recursion to traverse the tree)
    free_family(p->parents[0]); // Free first parent
    free_family(p->parents[1]); // Free second parent

    // Free the current person (release memory)
    free(p);
}

// Print each family member and their alleles (Week 5: Recursion to traverse and print the tree)
void print_family(person *p, int generation)
{
    // Base case: if person is NULL, stop
    if (p == NULL)
    {
        return;
    }

    // Print indentation based on generation (more indentation for higher generations)
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print the person's role and blood type based on their generation
    if (generation == 0)
    {
        // Child (generation 0) is the root of the tree
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0],
               p->alleles[1]);
    }
    else if (generation == 1)
    {
        // Parents (generation 1)
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0],
               p->alleles[1]);
    }
    else
    {
        // Grandparents or great-grandparents (generation 2 or higher)
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-"); // Add "Great-" for each generation beyond grandparents
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0],
               p->alleles[1]);
    }

    // Recursively print both parents (Recursion to traverse the tree)
    print_family(p->parents[0], generation + 1); // Print first parent
    print_family(p->parents[1], generation + 1); // Print second parent
}

// Randomly choose a blood type allele (A, B, or O)
char random_allele()
{
    // Generate a random number between 0 and 2
    int r = random() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
