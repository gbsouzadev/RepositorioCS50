#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (i = 0, n = strlen(s); i < n; i++)
    {
        if(islower(s[i]))
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
