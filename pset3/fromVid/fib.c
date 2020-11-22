#include <stdio.h>
#include <cs50.h>

int fibo(int n);

int main(void)
{
    int n = get_int("Fib Number: ");
    int res = fibo(n);
    printf("Fib of %d is %d \n", n, res);
}

int fibo(int n)
{
    if (n == 2)
    {
        return 3;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}