// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
const unsigned int N = 26;

// Hash table
node *table[N];
int count =0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //TODO
    node *check = table[hash(word)];

    while (check != NULL)
    {
        if (strcasecmp(check->word, word) == 0)
        {
            return true;
        }
        check = check->next;
    }

    return false;
}

// Hashes word to a number
// coded hash function, thanks to CS50 Study (https://video.cs50.io/nvzVHwrrub0?start=386)
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int n=0;

    for(int i = 0; word[i]!='\0';i++)
    {
        n = n + toupper(word[i]);
    }

    return n % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialize the hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char word[LENGTH + 1];
    FILE *dicptr = fopen(dictionary, "r");

    if (dicptr == NULL)
    {
        return false; // Unable to open dictionary file
    }

    while (fscanf(dicptr, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            fclose(dicptr);
            unload();
            return false; // Memory allocation failed
        }
        else
        {
            strcpy(new_node->word, word);
            int n = hash(new_node->word);
            new_node->next = table[n];
            table[n] = new_node;
            count++;
        }
    }

    fclose(dicptr);
    return true; // Dictionary loaded successfully
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
    for (int i = 0; i < N; i++)
    {
        node *cursor;
        cursor = table[i];

        while (cursor)
        {
            node* tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    return true;
}
