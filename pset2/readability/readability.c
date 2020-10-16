#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int readability(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0, words = 1, sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ' && text[i + 1] != ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        else
            continue;

    }
    //L = letters per100Words
    //S = sentencesPer100Words
    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;
    float index = round(0.0588 * L - 0.296 * S - 15.8);


    if(index < 1)
        printf("Before Grade 1\n");
    else if(index >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %.0f\n", index);
}
