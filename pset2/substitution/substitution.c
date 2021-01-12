#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validKey(string key);

int main(int argc, string argv[])
{
    string plaintext;

    string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./substitution key...\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else if (!validKey(key))
    {
        printf("Key may not repeat and may \ncontain only alphabetic characters\n");
        return 1;
    }
    else
    {
        plaintext = get_string("plaintext: ");
    }

    /**
     *
    **/
    char cipher;
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char p = plaintext[i];
        // char k = key[i];

        if (isalpha(p)){
            if (isupper(p))
            {
                int index = p - 'A';
                printf("%c", (key[index] - 32)); // - 32 to bring it back to upper case as all keys were changes to lower case
            }
            else
            {
                int index = p - 'a';
                printf("%c", (key[index]));
            }
        }
        else
        {
            printf("%c", p);
        }
    }
    printf("\n");
}










/**
 * the key should not repeated any characters not even in upper and lower case
 * we want key to be case sensitive so if there is a and A it's a duplicate
 * adding 32 will turn any upper case letter to its lower case form.
 * if s[i] == s[j] and i != j then there is a repeated character
 * */

bool validKey(string key)
{
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
         {
             return false;
         }
        if (isupper(key[i])) //making all key[i]s lower case
        {
            key[i] = key[i] + 32;
        }
         for (int j = 0; j < 26; j++)
         {
             if (isupper(key[j]))  //converting all to lower case
                 key[j] = key[j] + 32;
             {
                 if ( (key[i] == key[j]) && i != j) //comparing to make sure there is not repetitions
                 {
                     return false;
                 }
             }
         }
    }
    return true;
}

