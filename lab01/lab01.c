#include <stdio.h>
#include <stdlib.h>
#define MAX 150
#define PUSH_TO_MATRIX matrix[i][j] = arr[x]; x++;
#define BREAK if (x >= m*n) break;

void readArr(double arr[], int arrlen)
{
    int i;
    for (i = 0; i < arrlen; i++)
    {
        scanf("%lf", &arr[i]);
    }
}

void genSnail(double arr[], double matrix[][MAX], int m, int n)
{

    int k = 1, x = 0;
    int i, j;
    while (x < m*n) {
        i = m - k;
        j = n - k;
        // Sobe (subtrai na linha i)
        for (; i > k - 1; i--) {
            PUSH_TO_MATRIX;
        }
        BREAK;
        // Esquerda (subtrai na coluna j)
        for (; j > k - 1; j--) {
            PUSH_TO_MATRIX;
        }
        BREAK;
        // Desce (incrementa na linha i)
        for (; i < m - k; i++) {
            PUSH_TO_MATRIX;
        }
        BREAK;
        // Direita (incrementa na coluna j)
        for (; j < n - k; j++) {
            PUSH_TO_MATRIX;
        }
        if ((m * n) - x == 1) {
            i--;
            j--;
            PUSH_TO_MATRIX;
            break;
        }
        k++;
    }
}

void printMatrix(double matrix[][MAX], int lines, int cols)
{
    int i, j;
    for (i = 0; i < lines; i++) {
        for (j = 0; j < cols-1; j++)
            printf("%.1lf ", matrix[i][j]);
        printf("%.1lf\n", matrix[i][j]);
    }
    printf("\n");
}

int main()
{
    // Declaração incial e leitura da ordem e tamanho do vetor
    int m, n;
    scanf("%d %d", &m, &n);
    // Tamanho do vetor
    int len = m * n;
    double nums[MAX];
    readArr(nums, len);
    // Geração da matriz caracol
    double snail[MAX][MAX];
    genSnail(nums, snail, m, n);
    // Exibição
    printMatrix(snail, m, n);

    return 0;
}
