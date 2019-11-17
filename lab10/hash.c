#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "hash.h"

p_item create_item(char *key, int value) {
    p_item new;
    new = malloc(sizeof(Item));
    if (new == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    return new;
}

p_ht new_hash_table(int size) {
    p_ht new;
    new = malloc(sizeof(p_ht));
    new->set = malloc(size * sizeof(p_item));
    if (new->set == NULL) {
        printf("Nao ha memoria suficiente!\n");
       exit(1);
    }
    for (int i = 0; i < size; i++) {
        new->set[i] = NULL;
    }
    new->size = size;
    return new;
}

void ht_destroy(p_ht table);

void ht_insert(p_ht table, char *key, int value) {
    int pos = hash(key, table->size);
    while (table->set[pos]) {
        pos++;
    }
    table->set[pos] = create_item(key, value);
}

int ht_search(p_ht table, char* key) {
    int pos = hash(key, table->size);
    while (table->set[pos]) {
        if (strcmp(table->set[pos]->key, key) == 0)
            return 1;
        pos++;
    }
    return 0;
}

int hash(char* key, int m) {
    double a = (sqrt(5) - 1) / 2;
    long double x = 0;
    for (int i = 0; i < strlen(key); i++) {
        x = ((256 * x + key[i]) * a) - (int)x;
        x = x - (int)x; // mod 1
    }
    return floor(m * x);
}