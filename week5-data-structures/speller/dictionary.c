// Implements a dictionary's functionality - CS50 Pset 5
// https://cs50.harvard.edu/x/psets/5/speller/
// https://www.youtube.com/watch?v=_z57x5PGF4w&list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz

// -----------------------------------------------------------
// Basic idea:
// We'll build a hash table of linked lists to store every word from the dictionary file.
// Then check() will look up words in that hash table, load() will fill the table,
// size() returns how many words are loaded, and unload() frees memory.
// -----------------------------------------------------------

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strcpy
#include <strings.h> // for strcasecmp

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table (26 letters + apostrophe for better distribution)
// https://youtu.be/-BX4wLZRwbc?list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&t=96
const unsigned int N = 27;

// Hash table
node *table[N];

// Tracks number of words in dictionary
unsigned int word_count = 0;

// -----------------------------------------------------------
// check: Returns true if word is in dictionary, else false
// https://www.youtube.com/watch?v=qPz_Mr69yE0&list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&index=5
// -----------------------------------------------------------
bool check(const char *word)
{
    // Get hash value for the word
    unsigned int index = hash(word);

    // Traverse linked list at hash index
    // https://youtu.be/qPz_Mr69yE0?list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&t=93
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        // Case-insensitive comparison
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// -----------------------------------------------------------
// hash: Hashes word to a number (bucket index)
// https://www.youtube.com/watch?v=aFe05MQ56Rc&list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&index=3
// -----------------------------------------------------------
unsigned int hash(const char *word)
{
    // Handle apostrophe by mapping it to the last bucket
    if (word[0] == '\'')
    {
        return N - 1;
    }
    // Map first letter (case-insensitive) to 0-25
    return toupper(word[0]) - 'A';
}

// -----------------------------------------------------------
// load: loads dictionary into memory, returning true if successful, else false
// https://www.youtube.com/watch?v=-BX4wLZRwbc&list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&index=2
// -----------------------------------------------------------
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *Dictionaryfile = fopen(dictionary, "r"); // read the file
    if (Dictionaryfile == NULL)                    // check if it is null
    {
        return false;
    }

    // Buffer to store each word
    char word[LENGTH + 1]; // Plus 1 because we have the null operator in the end of the string

    // Read words from file one at a time
    // https://youtu.be/-BX4wLZRwbc?list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&t=424
    while (fscanf(Dictionaryfile, "%s", word) != EOF)
    {
        // Create new node for each word
        // https://youtu.be/-BX4wLZRwbc?list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&t=263
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            fclose(Dictionaryfile); // memory allocation failed: clean and return false
            return false;
        }

        // Copy word into node and set next pointer
        //
        strcpy(newnode->word, word);
        newnode->next = NULL;

        // Get hash index
        unsigned int index = hash(word);

        // Insert new node at the start of the linked list (head) for O(1) insertion
        // https://youtu.be/-BX4wLZRwbc?list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&t=579
        newnode->next = table[index];
        table[index] = newnode;

        // Increment word count
        word_count++;
    }

    // Close file
    fclose(Dictionaryfile);
    return true;
}

// -----------------------------------------------------------
// size: returns number of words in dictionary if loaded, else 0 if not yet loaded
// https://www.youtube.com/watch?v=3cD-_NGTw9A&list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&index=4
// -----------------------------------------------------------
unsigned int size(void)
{
    return word_count;
}

// -----------------------------------------------------------
// unload: unloads dictionary from memory, returning true if successful, else false
// https://www.youtube.com/watch?v=qkC4l0pUvCk&list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&index=6
// -----------------------------------------------------------
bool unload(void)
{
    // Iterate through each bucket
    for (int i = 0; i < N; i++)
    {
        // Free linked list in each bucket
        node *cursor = table[i];
        while (cursor != NULL)
        {
            // https://youtu.be/qkC4l0pUvCk?list=PLhQjrBD2T382T4b6jjwX_qbU23E_Unwcz&t=48
            // tmp = cursor to keep the adress of the last node while freeing them
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    return true;
}
