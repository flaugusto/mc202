#include <math.h>
#include <stdio.h>
#include <string.h>

int hash(char* key, int m);

int main() {

    char a[4] = "AAAA";
    char b[4] = "AAAC";
    char c[4] = "SPOT";
    char d[4] = "TAGC";

    int m = 8;

    
    printf("%d\n", hash(a, m));
    printf("%d\n", hash(b, m));
    printf("%d\n", hash(c, m));
    printf("%d\n", hash(d, m));
    return 0;
}



int hash(char* key, int m) {
    double a = (sqrt(5) - 1) / 2;
    long double x = 0;
    for (int i = 0; i < strlen(key); i++) {
        x = (256 * x + key[i]) * a;
        x = x - (int)x; // mod % 1
    }
    return floor(m * x);
}
