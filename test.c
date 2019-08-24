#include <stdio.h>

int main () {
    int m = 4, k = 1, i = 0;
    for (; i < m - k; i++) {
        printf("%d\n", i);
    }
    printf("%d\n", i);
}
