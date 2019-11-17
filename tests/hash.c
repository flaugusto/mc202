#include <math.h>
#include <stdio.h>
#include <string.h>

int hash(char* key, int m);
int isPrime(int n);
int nextPrime(int n);

int main() {

    char word[1000];

    int m,x;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        scanf(" %s", word);
        // scanf("%d", &x);
        // printf("hash: %d\n", hash(word, nextPrime(m * 2)));
        printf("%d: %s\n", i, word);
        // printf("next prime: %d", nextPrime(x));
    }
    
    return 0;
}

int nextPrime(int n) {
    for (int i = n; i < 2 * n; ++i) {
        if (isPrime(i))
            return i;
    }
    return -1; // nunca chega aqui
}
/**
 * Retorna se um número é primo (1) ou não (0)
 * */
int isPrime(int n) {
    
    if (n <= 1)
        return 0;

    // Bertrand's postulate (teorema pra achar primos)
    for (int j = 2; j <= n / 2; j++) {
        if ((n % j) == 0) {
            return 0;
        }
    }
    return 1;
}

int hash(char* key, int m) {
    long int x = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        char c = key[i];
        x = ((x * 26) % m + (c - 'A' + 1)) % m;
    }
    return x;
}
