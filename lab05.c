/*
 * Лабораторная №5
 * Аккузин Илья (ПИН-2022-1)
 *
 * Вариант 1:
 * Среди чисел 1, 1 + 1/2, 1 + 1/2 + 1/3, …  найти первое, большее числа n.
 *
 * $ gcc lab05.c -o lab05
 * */
#include <stdio.h>


int main() {
  printf("[IN] n: ");
  double n;
  scanf("%lf", &n);

  double x = 1;
  double divisor = 2;
  while(x <= n) {
    x += 1 / divisor;
    divisor++;
  }

  printf("[RES] %lf\n", x);

  return 0;
}
