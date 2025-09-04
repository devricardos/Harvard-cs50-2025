#include <cs50.h>
#include <stdio.h>

// Function declarations to let the compiler know these functions exist
bool is_valid_card(long credit_card); // Checks if the card number is valid using Luhn's algorithm
string get_card_brand(long credit_card); // Check the card brand based on starting digits and length

int main(void)
{
    // This ensures the input is a valid long integer (cs50's get_long function)
    long credit_card = get_long("Please Enter Credit Card Number: ");

    // Check if the card number passes the Luhn algorithm
    if (!is_valid_card(credit_card))
    {
        // If the card number is invalid (fails Luhn's algorithm), exit with error code 0
        printf("INVALID\n");
        return 0;
    }

    // If the card is valid, get the brand (VISA, AMEX, MASTERCARD, or INVALID)
    string brand = get_card_brand(credit_card);

    // Print the brand name (or "INVALID" if the brand doesn't match known patterns)
    printf("%s\n", brand);

    // Exit the program successfully with code 0
    return 0;
}

// Function to validate the credit card number using Luhn's algorithm
bool is_valid_card(long credit_card)
{
    // Initialize variables:
    // sum: Keeps track of the total sum for Luhn's algorithm
    int sum = 0;
    // is_alternate: Tracks whether we're processing an alternate (every second) digit
    bool is_alternate = false;

    // Process each digit of the credit card number from right to left
    while (credit_card > 0)
    {
        // Extract the last digit using modulo 10
        int digit = credit_card % 10;

        // Check if this is an alternate (second-from-right) digit
        if (is_alternate)
        {
            // Double the digit for alternate positions
            int doubled = digit * 2;
            // Add (sum) the digits of the doubled number (e.g., 14 becomes 1 + 4 = 5)
            // doubled / 10 gives the tens place (e.g., 1 for 14)
            // doubled % 10 gives the units place (e.g., 4 for 14)
            sum += (doubled / 10) + (doubled % 10);
        }
        else
        {
            // For non-alternate digits, add the digit directly to the sum
            sum += digit;
        }

        // Toggle is_alternate to process the next digit differently
        // (false -> true, true -> false)
        is_alternate = !is_alternate;

        // Remove the last digit by dividing by 10 (integer division)
        credit_card /= 10;
    }

    // The card is valid if the total sum is divisible by 10
    return sum % 10 == 0;
}

// Function to determine the card brand based on starting digits and length
string get_card_brand(long credit_card)
{
    // Create a temporary copy of the credit card number to manipulate
    long temp = credit_card;

    // Count the number of digits in the credit card number
    int length = 0;
    while (temp > 0)
    {
        length++;   // Increment length for each digit
        temp /= 10; // Remove the last digit
    }

    // Reset temp to the original credit card number
    temp = credit_card;

    // Extract the first two digits by dividing until we have a two-digit number
    while (temp >= 100)
    {
        temp /= 10; // Remove the last digit until only two digits remain
    }
    int first_two_digits = temp;

    // Extract the first digit by dividing the first two digits by 10
    int first_digit = first_two_digits / 10;

    // Check card brand based on starting digits and length
    // American Express: Starts with 34 or 37, must be 15 digits
    if ((first_two_digits == 34 || first_two_digits == 37) && length == 15)
    {
        return "AMEX";
    }
    // MasterCard: Starts with 51, 52, 53, 54, or 55, must be 16 digits
    else if (first_two_digits >= 51 && first_two_digits <= 55 && length == 16)
    {
        return "MASTERCARD";
    }
    // Visa: Starts with 4, must be 13 or 16 digits
    else if (first_digit == 4 && (length == 13 || length == 16))
    {
        return "VISA";
    }
    // If none of the above conditions match, the brand is invalid
    else
    {
        return "INVALID";
    }
}
