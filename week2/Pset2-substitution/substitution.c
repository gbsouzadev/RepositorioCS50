#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
    //Garants right amount of command-line input arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Garants every chars is alphabetical
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    //Garants key contains 26 chars
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    //Garants key consists on unique alphabets only
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must contain each letter exactly once\n");
                return 1;
            }
        }
    }

    //input for plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //Rotate to cipher
    for (int i = 0; i < strlen(plaintext); i++)
    {
        //Rotate uppercases
        if (isupper(plaintext[i]))
        {
            int v = plaintext[i] - 65;
            printf("%c", toupper(key[v]));
        }

        //Rotate lowercases
        if (islower(plaintext[i]))
        {
            int v = plaintext[i] - 97;
            printf("%c", tolower(key[v]));
        }
        //Print non alphabetical characters
        else if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}