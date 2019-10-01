#include <stdio.h>
#include "lista.h"

int main () {

    p_node list = create_list();
    Block test = create_block(0,8);

    list = push(test, list);
    list = push(create_block(9,10), list);
    list = push(create_block(19,1), list);
    list = push(create_block(20,5), list);

    printf("heap:\n");
    print(list);

    set_size(10, &test);
    set_start(225, &test);

    printf("heap:\n");
    print(list);

    return 0;
}