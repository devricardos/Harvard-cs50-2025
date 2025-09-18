// Filter More
// Problem Set - Week 4 - https://cs50.harvard.edu/x/psets/4/filter/more/
// https://www.youtube.com/watch?v=vsOsctDernw&list=PLhQjrBD2T382OwvMbZuaMGtD9wZkhnhYj&index=1

#include "helpers.h"
#include "math.h"
#include "stdlib.h"

// Convert image to grayscale: https://www.youtube.com/watch?v=ry6mY60W8fI
// How to run: ./filter -g infile.bmp outfile.bpm
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each row of the image: https://youtu.be/ry6mY60W8fI?t=169
    for (int row = 0; row < height; row++)
    {
        // Iterate over each pixel in the current row: ◻◼◻◻◻◻◻◻
        for (int column = 0; column < width; column++)
        {
            // Calculate the average of red, green, and blue values for the current pixel
            float average = (image[row][column].rgbtRed + image[row][column].rgbtGreen + image[row][column].rgbtBlue) / 3.0;

            // Round the average to the nearest integer: https://youtu.be/ry6mY60W8fI?t=148
            int grayscale = round(average);

            // Set the red, green, and blue values to the same gray value
            image[row][column].rgbtRed = grayscale;
            image[row][column].rgbtGreen = grayscale;
            image[row][column].rgbtBlue = grayscale;
        }
    }
    return;
}

//////////////////////////////////////////////////////////////////////////////////////
// Reflect image horizontally: https://www.youtube.com/watch?v=AuS7oAZbHhg
// How to run: ./filter -r infile.bmp outfile.bpm
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each row of the image
    for (int row = 0; row < height; row++)
    {
        // Iterate over the first half of each row to avoid redundant swaps
        // hint: https://youtu.be/AuS7oAZbHhg?list=PLhQjrBD2T382OwvMbZuaMGtD9wZkhnhYj&t=62
        // We do not modify the middle pixel in rows with odd width, if present
        for (int column = 0; column < width / 2; column++)
        {
            // Create a temporary variable to store the pixel at position j
            RGBTRIPLE temporary = image[row][column];

            // Swap the pixel at column with the pixel at (width - 1 - j)
            image[row][column] = image[row][width - 1 - column];

            // Place the original pixel from position column into the mirrored position (the end) (width - 1 - j)
            image[row][width - 1 - column] = temporary;
        }
    }
    return;
}

//////////////////////////////////////////////////////////////////////////////////////
// Blur image: https://www.youtube.com/watch?v=dxNO-hCjT0w
// How to run: ./filter -b infile.bmp outfile.bpm
void blur(int height, int width, RGBTRIPLE image[height][width])
{
        // Create a temporary 2D array to store the blurred image
        // TemporaryBlurredCopy is a pointer to an array of RGBTRIPLE structs (uint8_t red green blue)
        // malloc function dynamically allocates memory on the heap (better for unknown data size)
        RGBTRIPLE (*TemporaryBlurredCopy)[width] = malloc(height * sizeof(RGBTRIPLE[width]));
            // avoid crashes or undefined behavior if memory allocation fails
            if (TemporaryBlurredCopy == NULL)
                    return;

    // Iterate over each pixel in the image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Initialize sums for red, green, blue, and count of valid pixels (max=9)
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            int validPixelCounter = 0;

            // Check 3x3 grid around the current pixel (including itself)
            // rowOffset and colOffset represent relative positions (-1, 0, +1)
            // Iterate over the rows of a 3x3 grid around the current pixel (above, same, below)
            for (int rowOffset = -1; rowOffset <= 1; rowOffset++)
            {
                // Iterate over the columns of a 3x3 grid around the current pixel (left, same, right)
                for (int colOffset = -1; colOffset <= 1; colOffset++)
                {
                    // Calculate neighbor's coordinates (around current pixel)
                    int neighborRow = row + rowOffset;
                    int neighborCol = col + colOffset;

                    // Check if neighbor is within image bounds (if true the pixel is valid)
                    // Remove lopin
                    if (neighborRow >= 0 && neighborRow < height && neighborCol >= 0 && neighborCol < width)
                    {
                        // Add neighbor's RGB values to the sums (from valid 3x3 grid)
                        totalRed += image[neighborRow][neighborCol].rgbtRed;
                        totalGreen += image[neighborRow][neighborCol].rgbtGreen;
                        totalBlue += image[neighborRow][neighborCol].rgbtBlue;
                        validPixelCounter++; // Increment count of valid neighbors to divide later
                    }
                }
            }

            // Calculate average RGB values and round to nearest integer
            TemporaryBlurredCopy[row][col].rgbtRed = round((float)totalRed / validPixelCounter);
            TemporaryBlurredCopy[row][col].rgbtGreen = round((float)totalGreen / validPixelCounter);
            TemporaryBlurredCopy[row][col].rgbtBlue = round((float)totalBlue / validPixelCounter);
        }
    }

    // Copy blurred values from temp array back to original image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = TemporaryBlurredCopy[row][col];
        }
    }

    // Free the temporary array
    free(TemporaryBlurredCopy);
    return;
}

//////////////////////////////////////////////////////////////////////////////////////
// Detect edges: https://www.youtube.com/watch?v=PnVQN4vzC4U
// How to run: ./filter -e infile.bmp outfile.bpm
// How to run: ./filter -e images/courtyard.bmp courtyard-edge.bmp
// Detects edges highlighting areas with significant color changes
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image buffer to store the new pixel values
    RGBTRIPLE temporaryImage[height][width];

    // Loop through each pixel in the image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Initialize variables to store the gradient sums for red, green, and blue chanel
            // Int = 0 = black color: https://youtu.be/PnVQN4vzC4U?list=PLhQjrBD2T382OwvMbZuaMGtD9wZkhnhYj&t=488
            // GradientX (Gx) and GradientY (Gy) are the horizontal and vertical gradients for each color
            int redGradientX = 0, redGradientY = 0; // pure black
            int greenGradientX = 0, greenGradientY = 0; // pure black
            int blueGradientX = 0, blueGradientY = 0; // pure black

            // Detecting edges (3x3 matrices)
            // https://youtu.be/PnVQN4vzC4U?list=PLhQjrBD2T382OwvMbZuaMGtD9wZkhnhYj&t=428
            // Gx convolutional matrix: Detects horizontal color changes (left to right):
            int convolutionalGx[3][3] = {
                {-1, 0, 1},
                {-2, 0, 2},
                {-1, 0, 1}
            };
            // Gy convolutional matrix: Detects vertical color changes (top to bottom):
            int convolutionalGy[3][3] = {
                {-1, -2, -1},
                { 0,  0,  0},
                { 1,  2,  1}
            };

            // Check the 3x3 grid around the current pixel
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    // Calculate the neighboring pixel's coordinates
                    int neighborRow = row + i;
                    int neighborCol = col + j;

                    // Skip if the neighbor is outside the image boundaries
                    // If any of the condition below are true, it skips the loop and the value will be the original zero
                    if (neighborRow < 0 || neighborRow >= height || neighborCol < 0 || neighborCol >= width)
                    {
                        continue;
                    }

                    // Get the weights for this neighbor
                    int gxWeight = convolutionalGx[i + 1][j + 1];
                    int gyWeight = convolutionalGy[i + 1][j + 1];

                    // Add weighted color values to the gradients for each channel
                    redGradientX += image[neighborRow][neighborCol].rgbtRed * gxWeight;
                    redGradientY += image[neighborRow][neighborCol].rgbtRed * gyWeight;
                    greenGradientX += image[neighborRow][neighborCol].rgbtGreen * gxWeight;
                    greenGradientY += image[neighborRow][neighborCol].rgbtGreen * gyWeight;
                    blueGradientX += image[neighborRow][neighborCol].rgbtBlue * gxWeight;
                    blueGradientY += image[neighborRow][neighborCol].rgbtBlue * gyWeight;
                }
            }

            // Calculate the final gradient magnitude for each color channel
            // Use the formula: sqrt(Gx^2 + Gy^2) and round to the nearest integer
            // Squaring the number to make sure we end up with a positive value
            // https://youtu.be/PnVQN4vzC4U?list=PLhQjrBD2T382OwvMbZuaMGtD9wZkhnhYj&t=532
            int redFinal = (int) round(sqrt(redGradientX * redGradientX + redGradientY * redGradientY));
            int greenFinal = (int) round(sqrt(greenGradientX * greenGradientX + greenGradientY * greenGradientY));
            int blueFinal = (int) round(sqrt(blueGradientX * blueGradientX + blueGradientY * blueGradientY));

            // Cap the color values we get at 255 (maximum for RGB)
            // https://youtu.be/PnVQN4vzC4U?list=PLhQjrBD2T382OwvMbZuaMGtD9wZkhnhYj&t=583
            if (redFinal > 255) redFinal = 255;
            if (greenFinal > 255) greenFinal = 255;
            if (blueFinal > 255) blueFinal = 255;

            // Store the new pixel values in the temporary image
            temporaryImage[row][col].rgbtRed = redFinal;
            temporaryImage[row][col].rgbtGreen = greenFinal;
            temporaryImage[row][col].rgbtBlue = blueFinal;
        }
    }

    // Copy the processed pixels from temporaryImage back to the original image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = temporaryImage[row][col];
        }
    }
}
