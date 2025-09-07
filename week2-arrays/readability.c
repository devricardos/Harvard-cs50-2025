// Problem Set Details - week2 - https://cs50.harvard.edu/x/psets/2/readability/
// Include necessary libraries
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Ask the user to type a text
    string text = get_string("Text: ");

    // Count how many letters, words, and sentences the text has
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute average letters and sentences per 100 words
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Apply the Coleman–Liau formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round to nearest whole number
    int grade = round(index);

    // Print the grade level depending on the result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Count how many alphabetic characters are in the text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i])) // only letters count, not digits or punctuation
        {
            count++;
        }
    }
    return count;
}

// Count words by counting spaces + 1 (cuz the last word has no space after it)
int count_words(string text)
{
    int count = 1; // start at 1 because the first word doesn’t need a space before it
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Count sentences by checking for these: '.', '!', or '?'
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
