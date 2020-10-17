#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validKey(string s);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./substitution key...\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key my be 26 characters\n");
        return 1;
    }
    else if (!validKey(key))
    {
        printf("Key may not repeat and may contain only alphabetic characters\n");
        return 1;
    }
    else
    {
        printf("success so far\n");
        string plaintext = get_string("plaintext: ");
        printf("Under construction\n");
        
        /**
         * take the key and map it to a normal alphabetic order with their indexes
         * jkfhs
         * abcde
         * how will I get a as j?
         * have jkfhs as an array indexed 0 to 26
         * take the plaintext, see whether a given char is lower or upper case
         * convert all letter of key to one case, lower or upper
         * if plaintext[i] is an alpha, what is its normal position in the alphabets,
         * I can see if they are upper, then I sub 'A' or 'a' if they are lower to get their normal index
         * then look at the key which character is at that index and do the substitution
         * */
         
        /**
         * 
        **/
        
    }
    
    
    
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

