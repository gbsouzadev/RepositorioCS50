#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare variable for user input
    int height;

    // Get valid input or re-prompt user
    do
    {
        height = get_int("Set the pyramid height from 1 to 8: ");
    }
    while (height < 1 || height > 8);

    // Print row
    for (int row = 1; row <= height; row++)
    {

        // Print space
        for (int spc = 1; spc <= height - row; spc++)
        {
            printf(" ");
        }

        // Print left-side hash
        for (int hsh = 1; hsh <= row; hsh++)
        {
            printf("#");
        }

        // Print gap

        printf("  ");

        // Print right-side hash
        for (int hsh = 1; hsh <= row; hsh++)
        {
            printf("#");
        }

        // New line
        printf("\n");
    }
}