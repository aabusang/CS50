#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int n;

   do
   {
        n = get_int("Height: ");
   }while(n < 1 ||  n > 8);

   int row, a, mid, b, c;
   for ( row = 1; row <= n; row++)
   {
      for (a = n; a > row; a--) //decreasing blank triangle
      {
         printf(" ");
      }
      for (b = 1; b <= row; b++) //increasing leftward triangle
      {
         printf("#");
      }
      for (mid = 1; mid < 2; mid++) //middle space
      {
         printf("  ");
      }
      for (c = 1; c <= row; c++) //increasing rightward triangle
      {
         printf("#");
      }

      printf("\n");
   }
}

// Troubles I had in this problem

// I struggle to make the downward blank decreasing triangle
// The secret: was that I compare the "a" w/ 0 instead of no of rows
//