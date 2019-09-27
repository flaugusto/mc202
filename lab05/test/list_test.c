#include <stdio.h>
#include "lista.h"

int main () {

    p_node list = create_list();

    list = insert(list, 12);
    list = insert(list, 2);
    list = insert(list, 3);
    list = insert(list, 70);

    print(list);

    return 0;
}