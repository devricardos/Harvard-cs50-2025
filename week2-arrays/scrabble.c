// Problem Set Details - week2 - https://cs50.harvard.edu/x/psets/2/scrabble/
// Include necessary libraries
#include <cs50.h>   // For get_string() to read user input
#include <ctype.h>  // For isupper() and islower() to check character case
#include <stdio.h>  // For printf() to output results
#include <string.h> // For strlen() to get string length

// Array holding Scrabble point values for letters A-Z (index 0 = A, 1 = B, ..., 25 = Z)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype to compute the score of a word
int compute_score(string word);

int main(void)
{
    // Prompt Players to enter their word
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute scores for both words by calling compute_score
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine and print the winner based on scores
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n"); // Scores are equal
    }

    return 0; // Successful program execution
}

// Function to compute the Scrabble score for a given word
int compute_score(string word)
{
    // Initialize score to 0
    int score = 0;

    // Loop through each character in the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Check if the character is uppercase
        if (isupper(word[i]))
        {
            // Calculate index (0 for A, 1 for B, etc.) and add corresponding points
            score += POINTS[word[i] - 'A'];
        }
        // Check if the character is lowercase
        else if (islower(word[i]))
        {
            // Calculate index (0 for a, 1 for b, etc.) and add corresponding points
            score += POINTS[word[i] - 'a'];
        }
        // Non-alphabetic characters are ignored (no points added)
    }

    // Return the total score for the word
    return score;
}
