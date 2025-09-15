// Saves names and numbers to a CSV file
// https://youtu.be/kcRdFGbzR1I?t=8172

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open a CSV file named "phonebook.csv" in append mode ("a")
    // Week 4 Concept: File I/O
    // - fopen() opens a file; "a" mode means append, so new data is added to the end of the file
    // - If the file doesn't exist, it will be created
    // - FILE is a special data type in C for handling file streams
    FILE *file = fopen("phonebook.csv", "a");

    // Get user input for name and number using get_string from CS50 library
    // Week 4: Dynamic memory allocation
    // - get_string dynamically allocates memory for the input string and returns a pointer
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Write the name and number to the file in CSV format
    // Week 4: File writing
    // - fprintf writes formatted data to the file (similar to printf but for files)
    // - Format string "%s,%s\n" creates a CSV row: name, number, followed by a newline
    // - This ensures each entry is on a new line in the format "name,number"
    fprintf(file, "%s,%s\n", name, number);

    // Close the file
    // Week 4: Resource management
    // - fclose releases the file resource, ensuring data is flushed to disk
    // - Failing to close a file can lead to data loss or memory leaks
    fclose(file);

    return 0;
}
