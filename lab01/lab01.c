#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void readArr(double arr[], int arrlen) 
{
   int i;
   for (i = 0; i < arrlen; i++)
   {
      scanf("%lf", &arr[i]);
   }
}

void genSnail(double arr[MAX][MAX], int m, int n)
{
   
}

int main()
{
   int m, n;
   scanf("%d %d", &m, &n);

   int len = m * n; 
   double nums[len];
   readArr(nums, len);
   
   /*
   double snail[len][len];
   genSnail(nums, snail);

   printMatrix(snail); */

   return EXIT_SUCCESS;
}
