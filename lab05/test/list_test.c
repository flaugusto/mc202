#include <stdio.h>
#include "lista.h"

int main () {

    p_node list = create_list();
    Block test = create_block(0,8);

    list = insert_sorted(test, list);
    list = insert_sorted(create_block(4,10), list);
    list = insert_sorted(create_block(3,1), list);
    // list = insert_sorted(create_block(3,5), list);
    // list = insert_sorted(create_block(4,10), list);
    // list = insert_sorted(create_block(5,1), list);
    // list = insert_sorted(create_block(6,5), list);

    printf("heap:\n");
    print(list);

    set_size(10, &test);
    set_start(225, &test);

    printf("heap:\n");
    print(list);

    return 0;
}