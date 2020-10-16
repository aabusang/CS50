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
                 char current = plaintext[i] - 65;
                 char c = (current + key) % 26;
                 printf("%c", (c + 65));
             }
             else if (islower(plaintext[i]))
             {
                 char current = plaintext[i] - 97;
                 char c = (current + key) % 26;
                 printf("%c", (c+97));
             }

         }
         else
         {
             printf("%c", plaintext[i]);
         }
     }
     printf("\n");
}
