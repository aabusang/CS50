#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *name = "THenewcode";
    char *name2 ;
    printf("Name: ");
    for (int i = 0; i < strlen(name); i++)
    {

        printf("%c", tolower(name[i]));
    }
    strcpy(name2, name);
    printf("My name is %s", name2);
    printf("\n");
}