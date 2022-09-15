// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 2000;

// Hash table
node *table[N];

// Variables
unsigned int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];

    // Check linked list
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    //Ref. Source: adapted from brian@heli Engineer Man https://www.youtube.com/watch?v=wg8hZxMRwcw
    unsigned long int value = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        //Do several rounds of multiplication
        value = value * 37 + tolower(word[i]);
    }

    //make sure value is 0 <= value < N
    value = value % N;
    return value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    //Declare variables
    int index;
    char word[LENGTH + 1];

    //Open file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    //Loop through file gathering words
    while (fscanf(file, "%s", word) != EOF)
    {

        // Declare a node and allocate memory for it
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Assign a index to word, defined by the hash funtion
        index = hash(word);

        // Input word into the node
        strcpy(n->word, word);

        // Point the actual node to the bucket's first node
        n->next = table[index];

        // Point the bucket to the actual node
        table[index] = n;

        // Update word counter
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    // Check through all buckets
    for (int i = 0; i < N; i++)
    {
        //  Declare a node pointing to bucket[i]'s first element
        node *cursor = table[i];

        // Loop through all nodes of that bucket while cursor != NULL
        while (cursor != NULL)
        {
            // Declare a temporary node to receive cursor
            node *tmp = cursor;

            //  Point cursor to the next node
            cursor = cursor->next;

            // Free the node
            free(tmp);
        }

        // Make sure all nodes have been freed
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
