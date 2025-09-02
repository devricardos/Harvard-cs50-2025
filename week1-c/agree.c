#include <cs50.h>
#include <stdio.h>

// A short program that asks the user for a yes/no response and checks their input. It accepts both uppercase and lowercase letters. Good practice for conditionals and logical operators.

int main(void)
{ 
   // Uses || to prevent repeating myself - DRY 
    char c = get_char("Do you agree? ");
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not Agreed.\n");
    }
}
