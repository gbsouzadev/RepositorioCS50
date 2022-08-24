#include <cs50.h>
#include <stdio.h>
#include <string.h>

int string_lengh(string s)

int main(void)
{
    string name = get_string("Name: ");
    int lenght = strlen(name);
    printf("%i\n", lenght);
}
