#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
    char ch = ':';
    if (ispunct(ch))
    {
        printf("Yes ");
        printf("%c\n", ch);
    }
    else
        printf("No\n");
}