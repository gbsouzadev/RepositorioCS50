#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


string tocipher(string plaintext, int k);

int main(int argc, string argv[])
{
    //Garants right amount of command-line input arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Garants positive integer as command-line input arguments
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //Convert argv[1] to an integer as key
    int k = atoi(argv[1]);

    //plaintext input from user
    string plaintext = get_string("plaintext:  ");

    //Output
    printf("ciphertext: ");

    //Concatenate ciphertext
    tocipher(plaintext, k);
}


//Rotate function
string tocipher(string plaintext, int k)
{
    for (int i = 0; i < plaintext[i]; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 65 + k) % 26 + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 97 + k) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}