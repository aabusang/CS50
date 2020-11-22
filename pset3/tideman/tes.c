#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    int A[] = {20, 10, 12, 1, 3 ,5, 2, 34, 15, 78, 10, 0, 17};
    int n = 13;
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (A[j] < A[j + 1])
            {
                temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        printf("%d \n", A[k]);
    }
}