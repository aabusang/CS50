#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string name = get_string("Name: ");
    for (int i = 0; i < 4; i++)
    {
        char c = name[i];
        if (isupper(c))
        {
            printf("%d\n", (c + 32));
        }
        else
        {
            printf("%d\n", c);
        }
    }
}