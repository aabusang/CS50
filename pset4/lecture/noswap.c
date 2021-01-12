#include <stdio.h>

void noswap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;
    printf("x is %d, y is %d\n", x, y);
    noswap(x, y);
    printf("x is %d, y is %d\n", x, y);
}

void noswap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}