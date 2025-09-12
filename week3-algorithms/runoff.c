// Problem Set Details - week3 -  https://cs50.harvard.edu/x/psets/3/runoff/
// Student: Ricardo Delfino

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Get number of voters
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
// Preference is the position where the candidate's name was inputed in the argv.
bool vote(int voter, int rank, string name)
{
    // Problem 1: https://youtu.be/-Vc5aGywKxo?t=316
    // Loop through all candidates to find a match for the provided name
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare the input name with candidate names, if they are the same strcmp return 0
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Record the candidate's index in the preferences matrix for this voter and rank
            // [Voters = rows] [Preference rank = collums]
            preferences[voter][rank] = i;
            return true;
        }
    }
    // Return false if no candidate matches the provided name
    return false;
}

// Tabulate votes for each of the non-eliminated candidates
void tabulate(void)
{
    // Problem 2: https://youtu.be/-Vc5aGywKxo?t=578
    // Loop through each voter
    for (int i = 0; i < voter_count; i++)
    {
        // Loop through each voter's preferences in order
        for (int j = 0; j < candidate_count; j++)
        {
            // Get the candidate index for this voter's jth preference
            int candidate_index = preferences[i][j];
            // If the candidate j in preferences[i][j] is not (!) eliminated (== true), increment
            // their vote count
            if (!candidates[candidate_index].eliminated)
            {
                // increment candidate´s vote count by 1
                candidates[candidate_index].votes++;
                break; // Stop after counting the top non-eliminated candidate. Return to the i
                       // loop.
            }
        }
    }
}

// Print the winner of the election, if there is one already (more than half of the votes)
bool print_winner(void)
{
    // Problem 3: https://youtu.be/-Vc5aGywKxo?t=706
    // Calculate the majority threshold (more than half of total voters)
    int majority = 1 + voter_count / 2;

    // Loop through candidates to check for a majority winner
    for (int i = 0; i < candidate_count; i++)
    {
        // Skip eliminated candidates
        if (!candidates[i].eliminated)
        {
            // If a candidate has more than half the votes, they win
            if (candidates[i].votes >= majority)
            {
                // print winners name that has more than 50% of votes
                printf("%s\n", candidates[i].name);
                return true;
            }
        }
    }
    // No winner found
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Problem 4: https://youtu.be/-Vc5aGywKxo?t=777
    // Initialize min_votes to a high value
    int min_votes = MAX_VOTERS + 1;

    // Loop through candidates to find the lowest vote count among non-eliminated candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            // tracks the smallest vote count candidates
            min_votes = candidates[i].votes;
        }
    }
    // This will return the number of votes that were minimum, It can be from a single candidate or
    // many.
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Problem 5: https://youtu.be/-Vc5aGywKxo?t=857
    // Loop through candidates to check if all non-eliminated candidates have the same vote count
    for (int i = 0; i < candidate_count; i++)
    {
        // If both conditions are true (the candidate is not eliminated and their vote count is not
        // equal to min), it means at least one non-eliminated candidate has a different number of
        // votes, so it is not tied.
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            // If any non-eliminated candidate has a different vote count, it's not a tie
            return false;
        }
    }
    // All non-eliminated candidates have the same vote count (min). So it is a tie.
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Problem 6: https://youtu.be/-Vc5aGywKxo?t=919
    // Loop through candidates and eliminate those with the minimum vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
