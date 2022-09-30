/*
 * Лабараторная №1
 * Аккузин Илья (ПО-2022-1)
 * 
 * NOTE: Добавьте флаг `-lm` чтобы включить `math.h`
 * $ gcc lab01.c -o lab01 -lm
 * */
#include <stdio.h>
#include <math.h>

double f(double x) {
    return sqrt(
        (2 * x + sin(fabs(3 * x))) / 3.56
    );
}

int main() {

    double x;
    printf("x: ");
    scanf("%lf", &x);
    double y = f(x);
    printf("y: %lf\n", y);

    return 0;
}


