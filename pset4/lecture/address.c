#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%d\n", n);
    printf("%p\n", p);

    char *s = "EMMA";
    printf("%s\n", s);
    printf("%c \n\n",  s[0]);
    printf("%c\n", *s);
    printf("%c\n", *(s+1));//...
}