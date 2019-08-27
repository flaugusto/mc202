#include <stdio.h>
#define MAX 10

void printMatrix(double matrix[][MAX], int cols, int lines)
{
    int i, j;
    for (i = 0; i < lines-1; i++)
        for (j = 0; j < cols; j++)
            printf("%lf ", matrix[i][j]);
    printf("%lf", matrix[i][j]);
}

void readArr(double arr[], int arrlen)
{
    int i;
    for (i = 0; i < arrlen; i++)
    {
        scanf("%lf", &arr[i]);
    }
}

int main() 
{
    
    return 0;
}
