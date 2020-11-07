#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
// #include <math.h>


int main(int argc, string argv[])
{
    int key;
    if (argc != 2){
        printf("USAGE: ./caesar key...\n");
        return 1;
    }else
    {
        for (int i = 0; argv[1][i] != '\0'; i++){
            if(!isdigit(argv[1][i])){
                printf("USAGE: ./caesar key ...\n");
                return 2;
            }else{
                key = atoi(argv[1]);
            }
        }
    }

    string plaintext = get_string("plaintext: ");


     printf("ciphertext: ");
     for (int i = 0; plaintext[i] != '\0'; i++)
     {
         //char c = plaintext[i];
         if (isalpha(plaintext[i]))
         {
             if (isupper(plaintext[i]))
             {
                 //char current = plaintext[i] - 65;
                 char c = (((plaintext[i] - 'A') + key) % 26) + 'A';
                 printf("%c", c);
             }
             else if (islower(plaintext[i]))
             {
                 //char current = plaintext[i] - 97;
                 char c = ( ((plaintext[i] - 'a') + key) % 26) + 'a';
                 printf("%c", c);
             }

         }
         else
         {
             printf("%c", plaintext[i]);
         }
     }
     printf("\n");
}

/**
 * Mistake I was doing that made the whole project take a longer time
 * I wa substraction 'a' or "A" for the index i like plaintext[i - a or A]
 * instead of substracting it from the character
 *
 * so basically I should substract from the character not it index.
 *
 * */