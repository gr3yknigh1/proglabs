/*
 * Лабараторная №2
 * Аккузин Илья (ПО-2022-1)
 * 
 * $ gcc lab02.c -o lab02
 * */
#include <stdio.h>


int main() {

    char a = 'A';
    printf("%c\n", a);

    char name[15];
    printf("Меня зовут ");
    scanf("%s", name);

    int x = 315;
    printf("%d\n", x);

    int y = -27;
    printf("%d\n", y);

    float z = 127.361;
    printf("%f\n", z);

    double j = -574.953;
    printf("%lf\n", j);

    long h = 2124;
    printf("%ld\n", h);

    return 0;
}
