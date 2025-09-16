// Copies a file
// https://youtu.be/kcRdFGbzR1I?t=8306

#include <stdio.h>
#include <stdint.h>

// Define BYTE as an alias for uint8_t (8-bit unsigned integer)
// Week 4: Type definitions: https://youtu.be/kcRdFGbzR1I?t=8534
// - typedef allows creating custom type names
// - uint8_t ensures exactly 8 bits (1 byte)
typedef uint8_t BYTE;

// Main function with command-line arguments
int main(int argc, char *argv[])
{
    // Open source file in binary read mode ("rb")
    // Week 4: File I/O (Binary mode)
    // - fopen opens a file; "rb" mode reads the file as binary data (byte-by-byte)
    // - argv[1] is the first command-line argument (source file name)
    FILE *src = fopen(argv[1], "rb");

    // Open destination file in binary write mode ("wb"): https://youtu.be/kcRdFGbzR1I?t=8517
    // - "wb" mode creates or overwrites the file for binary writing
    // - argv[2] is the second command-line argument (destination file name)
    FILE *dst = fopen(argv[2], "wb");

    // Declare a single byte variable to hold data read from the source
    // Week 4 Concept: Working with bytes
    // - BYTE (uint8_t) is used to read and write exactly one byte at a time
    // - This ensures precise control when copying binary files (e.g., images, not just text)
    BYTE b;

    // Read one byte at a time from the source file until end-of-file (EOF)
    // Week 4: File reading and looping
    // - fread reads data from src into the address of b (&b)
    // - Parameters: pointer to store data (&b), size of each element (sizeof(b)=1), number of elements (1), file pointer (src)
    // - fread returns the number of elements read; 0 indicates EOF or error
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        // Write the byte to the destination file
        // Week 4: File writing
        // - fwrite writes the byte from &b to dst
        // - Same parameters as fread: pointer to data (&b), size (1 byte), count (1), file pointer (dst)
        fwrite(&b, sizeof(b), 1, dst);
    }

    // Close the destination file
    // Week 4: Resource management
    // - fclose ensures all buffered data is written to the file and releases resources
    fclose(dst);

    // Close the source file - Ensures proper cleanup of file resources
    fclose(src);

    return 0;
}
