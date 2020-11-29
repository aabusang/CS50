#include <cs50.h>
#include <stdio.h>

int conjecture(int n);

int main(void)
{
    int n = get_int("Number: ");

    int res = conjecture(n);
    printf("%d \n", res);
}

int conjecture(int n)
{
    int steps = 0;
    if (n == 1)
    {
        return 0;
    }
    if (n % 2 == 0)
    {
        steps++;
        return 1 + conjecture(n / 2);
    }
    if (n % 2 != 0)
    {
        steps++;
        return 1 + conjecture( (3*n) + 1);
    }

    return steps;
}