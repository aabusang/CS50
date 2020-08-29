#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int readability(string text);
int main(void)
{
    string text = get_string("Text: ");

    int letters = 0, words = 0, sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
            letters++;
        else if (text[i] == ' ' && text[i + 1] != ' ')
            words++;
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }
    //L = letters per100Words
    //S = sentencesPer100Words
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    int index = 0.0588 * L - 0.296 * S - 15.8;

    printf(" Letters is %d\n", letters);
    printf(" Words is %d\n", words);
    printf(" Sentences is %d\n", sentences);
    printf("  L is %.2f\n", L);
    printf("  S is %.2f\n", S);
    printf(" Index is %d\n", index);
    // if(index < 1)
    //     printf("Before Grade 1\n");
    // else if(index >= 16)
    //     printf("Grade 16+\n");
    // else
    //     printf("Grade %d\n", index);
}

