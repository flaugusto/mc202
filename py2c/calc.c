#include <stdio.h>

int main() {
    float a, b, res;
    char op;

    scanf("%f %c %f", &a, &op, &b);

    if (op == '/') {
        res = a / b;
        printf("%f\n", res);
    } else {
        printf("Erro: operador não reconhecido.\n");
    }
    return 0;
}