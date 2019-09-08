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

void readArr(int arr[], int arrlen)
{
    int i;
    for (i = 0; i < arrlen; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        printf("%d", arr[i]);
}

int main() 
{
    int test[5];
    readArr(test, 5);
    printArr(test, 5);
    return 0;
}
