#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int arr[3][3] = { {0, 1, 0},
                      {0, 0, 0},
                      {1, 1, 0}};
    printf("Vertical...\n");
    int counter;
    int j;
    for (int i = 0; i < 3; i++)
    {

        counter = 0;
        for (j = 0; j < 3; j++)
        {
            if (arr[j][i] == 0)
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            printf("Candidate %d won", i);
        }
    }
    printf("\n");
    // printf("Horizontal...\n");
    // for (int i = 0; i < 3; i++)
    // {
    //     // printf("%d ", arr[0][i]);
    //     if (arr[0][i] == 2)
    //     {
    //         printf("Found\n");
    //         continue;
    //     }
    // }
    // printf("\n");

}