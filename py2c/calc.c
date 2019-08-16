#include <stdio.h>

int main() {
    int nop, i;
    float a, b, res;
    char op;

    scanf("%d", &nop);
    
    for (i = 0; i < nop; i++) {
        scanf("%f %c %f", &a, &op, &b);
        switch (op) {
            case '/':
                res = a / b;
                printf("%f\n", res);
                break;
            case '+':
                res = a + b;
                printf("%f\n", res);
                break;
            case '*':
                res = a * b;
                printf("%f\n", res);
                break;
            case '-':
                res = a - b;
                printf("%f\n", res);
                break;
            default:
                printf("Erro: operador não reconhecido.\n");
                break;
        }
    }
    
    
    return 0;
}