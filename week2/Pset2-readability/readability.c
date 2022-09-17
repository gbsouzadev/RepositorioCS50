#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_index(int letters, int words, int sentences);

int main(void)
{

    // Get input text
    string text = get_string("Text: ");

    // Get the ammount of letters
    int letters = count_letters(text);

    // Get the ammount of words
    int words = count_words(text);

    // Get the ammount of sentences
    int sentences = count_sentences(text);

    // Get the coleman index
    int index = coleman_index(letters, words, sentences);

    // Print index
    if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    printf("Grade %i\n", index);
    return 0;
}


int count_letters(string text)
{
    // Declare variables
    int count = 0;
    int len = strlen(text);

    // Loop through all chars inside text looking for alphabetics
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            // Update counter
            count++;
        }
    }
    return count;
}


int count_words(string text)
{
    // Declare variables
    int count = 1;
    int len = strlen(text);

    // Loop through all chars inside text looking for spaces
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 32)
        {
            // Update counter
            count++;
        }
    }
    return count;
}


int count_sentences(string text)
{
    // Declare variables
    int count = 0;
    int len = strlen(text);

    // Loop through all chars inside text looking for "." || "!" || "?"
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            // Update counter
            count++;
        }
    }
    return count;
}


int coleman_index(int letters, int words, int sentences)
{
    // Convert integers to float
    float fletters = letters;
    float fwords = words;
    float fsentences = sentences;

    // Apply the provided formula
    float L = fletters / fwords * 100;
    float S = fsentences / fwords * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Return the rounded index value
    return round(index);
}