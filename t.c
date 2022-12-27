#include <stdio.h>
#include "types.h"



int main() {

    int x = 10;

    printf("%d\n", x);

    int* pointer_x = &x;

    x++;

    printf("%p\n", pointer_x);

    printf("%d\n", *pointer_x);


    return 0;
}

