// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50000;

// Hash table
node *table[N];

//Dictionary Word count
unsigned int word_count = 0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hash_index = hash(word);
    //use for loop in case there is a collision
    for (node *tmp = table[hash_index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hashcode = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        //tolower makes function case insensitive
        hashcode = pow((hashcode * 33), tolower(word[i]));
    }
    //mod to make sure hashcode b/n 0 and N - 1
    hashcode = hashcode % N;
    return hashcode;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char Word[LENGTH + 1];
    while (fscanf(file, "%s", Word) != EOF)
    {
        word_count++;
        //make new node for given word and pointer
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        //copy word to new node's word
        strcpy(new_node->word, Word);

        // insert node into the hash table
        int index = hash(new_node->word);

        new_node->next = table[index];
        table[index] = new_node;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    int index = 0;
    while (table[index] != NULL)
    {
        node *list = table[index];
        while (list != NULL)
        {
            node *tmp = list->next;
            free(list);
            list = tmp;
        }
        //increament to go to next link
        index++;
    }
    return true;
}
