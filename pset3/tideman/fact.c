#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int n = get_int("Number: ");

    int res = fact(n);
    printf("%d\n", res);
}


int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}