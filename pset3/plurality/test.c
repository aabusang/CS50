#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = 1;
    printf("X is %d\n", (x = x + 1));
}