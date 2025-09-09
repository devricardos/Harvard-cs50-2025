// Implements a phone book with structs
// CS50x 2025 - Lecture 3 - Algorithms
// https://youtu.be/iCx3zwK8Ms8?list=PLhQjrBD2T383q7Vn8QnTsVgSvyLpsqL_R&t=3410

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// create a struct called person, with name and number inside.
typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[3];

    // New operator "."
    people[0].name = "Yuliia";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        // strcmp from string.h to compare strings, inputed name vs names array
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found number %s\n", people[i].number);
            return 0; // Success
        }
    }
    printf("Not found\n");
    return 1; // Error
}
