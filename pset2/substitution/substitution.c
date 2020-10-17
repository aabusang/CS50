#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validKey(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key...\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key my be 26 characters\n");
        return 1;
    }
    else if (!validKey(argv[1]))
    {
        printf("Key may not repeat and may contain only alphabetic characters\n");
        return 1;
    }
    else
    {
        printf("success so far\n");
        string plaintext = get_string("plaintext: ");
        printf("Under construction\n");
        
    }
    
    return 0;
}



/**
 * the key should not repeated any characters not even in upper and lower case
 * we want key to be case sensitive so if there is a and A it's a duplicate
 * adding 32 will turn any upper case letter to its lower case form.
 * if s[i] == s[j] and i != j then there is a repeated character
 * */
 
bool validKey(string s)
{
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(s[i]))
         {
             return false;
         }
        if (isupper(s[i]))
        {
            s[i] = s[i] + 32; 
        }
         for (int j = 0; j < 26; j++)
         {
             if (isupper(s[j])) 
                 s[j] = s[j] + 32; 
             {
                 if ( (s[i] == s[j]) && i != j)
                 {
                     return false;
                 }
             }
         }
    }
    return true;
}