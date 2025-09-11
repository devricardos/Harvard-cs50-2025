// Problem Set Details - week3 - https://cs50.harvard.edu/x/psets/3/plurality/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Learning: Validate command-line arguments to ensure at least one candidate is provided
    // If argc < 2, only the program name was given (no candidates), which is invalid
    if (argc < 2)
    {
        printf("Usage: ./plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Get number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Learning: This function teaches string comparison, iterating over an array of structs,
// and handling invalid inputs. It updates the vote count for a candidate if their name matches
// the input, returning true for a valid vote and false for an invalid one.
bool vote(string name)
{
    // Iterate through all candidates to find a match
    for (int i = 0; i < candidate_count; i++)
    {
        // Use strcmp to compare the input name with each candidate's name
        // Learning: strcmp (from string.h) compares two strings and returns 0 if they are equal
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Increment the candidate's vote count and return true for a successful vote
            candidates[i].votes++;
            return true;
        }
    }
    // If no match is found, return false to indicate an invalid vote
    // Learning: This handles edge cases like voting for a non-existent candidate
    return false;
}

// Learning: This function teaches how to find the maximum value in an array of structs
// and handle ties (multiple candidates with the same max votes). It avoids sorting to keep
// the algorithm efficient (O(n) instead of O(n log n)) and prints the winner(s).
void print_winner(void)
{
    // Step 1: Find the maximum number of votes
    int max_votes = 0;
    // Learning: Linear search to find the highest vote count by iterating through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Step 2: Print all candidates with the maximum number of votes
    // Learning: Handles ties by checking all candidates again and printing those with max_votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            // Print the candidate's name followed by a newline
            // Learning: Follows the output specification precisely
            printf("%s\n", candidates[i].name);
        }
    }
    // Learning: No explicit return needed since the function is void
    return;
}
