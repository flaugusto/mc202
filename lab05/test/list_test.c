#include <stdio.h>
#include "lista.h"

int main () {

    p_node list = create_list();
    Block test = create_block(0,8);

    list = insert(list, test);
    list = insert(list, create_block(9,10));
    list = insert(list, create_block(19,1));
    list = insert(list, create_block(20,5));

    printf("heap:\n");
    print(list);

    return 0;
}