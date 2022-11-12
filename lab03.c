/*
 * Лабораторная №3
 * Аккузин Илья (ПИН-2022-1)
 *
 * Вариант №1:
 * С клавиатуры вводятся 4 целых числа: a, b, c, d. Найти среди пару чисел с минимальной
 * по модулю разностью. Операторы цикла в программе не использовать.
 *
 * $ gcc lab03.c -o lab03 -lm
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CHECK_DIFF(m, x, y) \
  if (abs(x - y) < m) {     \
    m = abs(x - y);         \
  }                         \


int input(const char* message) {
  printf("%s", message);
  int x;
  scanf("%d", &x);
  return x;
}


int min(const int x, const int y) {
  return x > y ? y : x;
}


int main() {

  const int a = input("a: ");
  const int b = input("b: ");
  const int c = input("c: ");
  const int d = input("d: ");

  // @NOTE: решение без if-else
  int min_diff = abs(a - b);
  min_diff = min(min_diff, abs(a - c));
  min_diff = min(min_diff, abs(a - d));
  min_diff = min(min_diff, abs(b - c));
  min_diff = min(min_diff, abs(b - d));
  min_diff = min(min_diff, abs(c - d));
  printf("%d\n", min_diff);

  // @NOTE: решение с макросом
  min_diff = abs(a - b);
  CHECK_DIFF(min_diff, a, c);
  CHECK_DIFF(min_diff, a, d);
  CHECK_DIFF(min_diff, b, c);
  CHECK_DIFF(min_diff, b, d);
  CHECK_DIFF(min_diff, c, d);
  printf("%d\n", min_diff);

  // @NOTE: решение с if-else
  min_diff = abs(a - b);
  if (abs(a - c) < min_diff) { min_diff = abs(a - c); }
  if (abs(a - d) < min_diff) { min_diff = abs(a - d); }
  if (abs(b - c) < min_diff) { min_diff = abs(b - c); }
  if (abs(b - d) < min_diff) { min_diff = abs(b - d); }
  if (abs(c - d) < min_diff) { min_diff = abs(c - d); }
  printf("%d\n", min_diff);

  return 0;
}

