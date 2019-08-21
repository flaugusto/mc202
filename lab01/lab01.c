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

void genSnail(double arr[], int arrlen, double matrix[][MAX], int m, int n)
{
    int x = 0, i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            matrix[i][j] = arr[x];
            x++;
        }
        
    
}

void printMatrix(double matrix[][MAX], int cols, int lines)
{
    int i, j;
    for (i = 0; i < lines-1; i++)
        for (j = 0; j < cols; j++)
            printf("%lf ", matrix[i][j]);
    printf("%lf", matrix[i][j]);
}

int main()
{
    // Declaração incial e leitura da ordem e tamanho do vetor
    int m, n;
    scanf("%d %d", &m, &n);
    // Leitura do vetor de números
    int len = m * n;
    double nums[len];
    readArr(nums, len);
    // Geração da matriz caracol
    double snail[len][len];
    genSnail(nums, len, snail, m, n);
    // Exibição
    printMatrix(snail, m, n);

    return EXIT_SUCCESS;
}
