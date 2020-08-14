#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


//A program to encrypt text
void encrypt(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key...\n");
        return 1;
    }

    string key = argv[1];
    int i, j, len = strlen(key);
    if (len != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    for (i = 0; i < len; i++)
    {
        if (isdigit(argv[1][i]))
        {
            printf("Key must not contain numbers\n");
            return 1;
        }
        key[i] = tolower(key[i]);
        for (j = i + 1; j < len; j++)
        {
            if ((key[i] == key[j]) && (i != j))
            {
                printf("Key must not contain dupicates\n");
                return 2;
            }
        }
    }

    // take plaintext letter by letter
    // turn all to lower case
    // substract a if lower or A if upper from current letter
    // get a number b/n 1 and 26
    // index that number to the key
    // print letter at the key index
    encrypt(key);

}

void encrypt(string key)
{
    string plaintext = get_string("plaintext: ");
    int i, index, len = strlen(plaintext);
    for (i = 0; i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
                index = plaintext[i] - 'a';
            else
                index = plaintext[i] - 'A';
            printf("%c", key[index]);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

}
