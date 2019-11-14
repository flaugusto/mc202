#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

#define MAX_SIZE 100

void print_stack(p_stack stack);
void print_list(p_node head);
int to_int(char c);

int main() {
    int lines, count, x;

    scanf("%d ", &lines);

    for (int i = 0; i < lines; i++) {
        // Início de uma sequência
        char seq[MAX_SIZE];
        scanf("%s",seq);
        scanf("%d", &count);
        printf("Dig: %d\n", count);

        int len = strlen(seq);
        p_stack result = create_stack();
        

        int j = 0;
        for (; j < len && count != 0; j++) {
            x = to_int(seq[j]);
            printf("%d\n", x);

            if (empty(result)) {
                push(x, result);
                continue;
            }
            while (!empty(result) && x > peek(result)) {
                pop(result);
                count--;
            }
            push(x, result);
            printf("Stack: ");
            print_stack(result);
        }

        if (count != 0) {
            x = pop(result);
            count--;
            while (count != 0 && x <= peek(result)) {
                x = pop(result);
                count--;
            }
        }

        // Se ainda sobrou números na sequencia, adiciona na pilha
        for (; j < len; j++) {
            push(to_int(seq[j]), result);
        }

        print_stack(result);
        destroy_stack(result);
        
    }

    return EXIT_SUCCESS;
}

void print_stack(p_stack stack) {
    if (!empty(stack)) {
        print_list(get_top(stack));
        printf("\n");
    }
}

void print_list(p_node head) {
    if (head) {
        print_list(get_next(head));
        printf("%d", get_value(head));
    }
}

int to_int(char c) {
    return c - '0';
}