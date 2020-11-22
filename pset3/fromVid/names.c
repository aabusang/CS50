#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string names[4] = {"EMMA", "RODRIGO", "DAVID", "BRIAN"};

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(names[i], "EMMA"))
        {
            printf("Found\n");
            return 0;
        }
    }

    return 1;

}