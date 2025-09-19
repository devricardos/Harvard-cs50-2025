// Recover
// Problem Set - Week 4 - https://cs50.harvard.edu/x/psets/4/recover/
// https://www.youtube.com/watch?v=ooL0r_8N9ms
/* Pseudocode:
    Open memory card
    Repeat until end of card:
      Read 512 bytes into a buffer
        If start of new JPEG
            If first JPEG
                ...
            Else
                ...
        Else
            If already found JPEG
                ...
    Close any remaining files
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define the block size for reading the memory card (512 bytes as per FAT file system)
// Capital letters for BLOCK SIZE constant
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument https://cs50.harvard.edu/x/psets/4/recover/#hints
    if (argc != 2)
    {
        // Print how to use message and return 1 to indicate an error
        printf("Usage: ./recover FILE NAME.EXTENSION\n");
        return 1;
    }

    // Open the problematic image file for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        // If file cannot be opened, print error and return 1
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    // Buffer to store one block (512 bytes) of data from the memory card
    uint8_t buffer[BLOCK_SIZE];

    // Pointer to the output JPEG file (initially NULL as no file is open yet)
    FILE *output = NULL;

    // Counter for naming JPEG files (e.g., 000.jpg, 001.jpg, etc.)
    int jpeg_filename_counter = 0;

    // Buffer to store the filename (###.jpg, including null terminator, needs 8 chars: 3 digits +
    // .jpg + \0)
    char filename[8];

    // **switch control** to track if we are currently writing to a JPEG file
    bool writing_jpeg = false;

    // While there's still data left to read from the memory card
    // Read the input file 512 bytes at a time until no more data is available
    // https://youtu.be/ooL0r_8N9ms?t=537
    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        // Check for JPEG signature: first three bytes are 0xff, 0xd8, 0xff
        // https://youtu.be/ooL0r_8N9ms?t=337
        // Fourth byte's first four bits are 1110 (check if it’s one of 0xe0, 0xe1, ..., 0xef)
        // If all conditions are true, it recognizes the start of a new JPEG file and begins writing
        // it to a new file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If we were already writing a JPEG, close the previous file
            if (writing_jpeg)
            {
                fclose(output);
            }

            // Create a new filename using the format ###.jpg (000.jpg and so on)
            // https://youtu.be/ooL0r_8N9ms?t=455
            sprintf(filename, "%03i.jpg", jpeg_filename_counter);

            // Open a new file for writing the JPEG/ ´w´ for writing now
            output = fopen(filename, "w");
            if (output == NULL)
            {
                // If file cannot be opened, clean up and exit
                fclose(input);
                printf("Could not create output file %s\n", filename);
                return 1;
            }

            // Increment the JPEG counter for the next file
            jpeg_filename_counter++;

            // **switch control** to indicate we are now writing a JPEG
            writing_jpeg = true;
        }

        // If we are currently writing a JPEG, write the current block to the output file
        // https://youtu.be/ooL0r_8N9ms?t=480
        if (writing_jpeg)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }

    // Close any open files
    if (writing_jpeg)
    {
        fclose(output);
    }
    fclose(input);

    // Return 0 to indicate successful execution
    return 0;
}
