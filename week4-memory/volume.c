// Modifies the volume of an audio file
// Problem Set Details - week4 - https://cs50.harvard.edu/x/psets/4/volume/

// declarations of a number of other types that allow us to very precisely define the size (in bits)
// and sign (signed or unsigned) of an integer.
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Done: Copy header from input file to output file
    uint8_t header[HEADER_SIZE]; // Declare an array to store the WAV file header (44 bytes)
    fread(header, HEADER_SIZE, 1,
          input); // Read HEADER_SIZE bytes from the input file into the header array
    fwrite(header, HEADER_SIZE, 1, output); // Write the header to the output file

    // Done: Read samples from input file and write updated data to output file
    // Create a buffer for a single sample (2 byte sample)
    int16_t buffer;

    // Read single sample from input into buffer while there are samples left to read
    // read 1 sample of 2 bytes (16 bits - one int16_t sample) into buffer; loop continues until end
    // of file
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Update volume of sample with the factor (from command-line argument)
        buffer *= factor; // Scale the sample's amplitude to adjust volume (e.g., factor = 2.0
                          // doubles volume)

        // Write updated sample to new file (output)
        fwrite(&buffer, sizeof(int16_t), 1, output); // Write 2 bytes to the output file
    }

    // Week 4: Resource management
    // Close files
    fclose(input);
    fclose(output);
}
