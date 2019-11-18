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

/** Printa heaps **/
void print_h(p_heap h, char* msg) {
    printf("Heap %s: ", msg);
    for (int i = 0; i < h->i; i++)
    {
        printf("v[%d]: %s ", i, h->v[i].code);
    }
    printf("\n");
    
}

void printHash(Item **arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("v[%d]: ", i);
        if (arr[i])
            printf("{%s: %d}\n", arr[i]->key, arr[i]->value);
        else
            printf("NULL\n");
    }
}