/*
 * Лабораторная №4
 * Аккузин Илья (ПИН-2022-1)
 *
 * Вариант №1:
 * a) Задан массив А(20). Определить знакопеременную сумму а2 + а3 – а4 + ...
 * б) Просуммировать элементы матрицы Х(6,8), сумма индексов которых равна заданной
 * константе К.
 *
 * $ gcc lab04.c -o lab04
 * */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int randint(int min, int max) {
  /*
   * Values in range: [min; max]
   * */
  return min + rand() % (max + 1 - min);
}


const int* randint_arr(const int size, const int min, const int max) {
  int* array = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    array[i] = randint(min, max);
  }
  return array;
}


void print_int_array(const int* array, const int size) {
  printf("{ ");
  const char* sep = ", ";
  for (int i = 0; i < size; i++) {
    printf("%d", array[i]);
    if (i != size - 1) {
      printf("%s", sep);
    }
  }
  printf(" }\n");
}


void a() {
  const int ARRAY_SIZE = 20;
  const int* array = randint_arr(ARRAY_SIZE, 0, 20);

  printf("Generated array: ");
  print_int_array(array, ARRAY_SIZE);

  int dynamic_sign_sum = 0;
  for (int i = 0; i < ARRAY_SIZE; i ++) {
    dynamic_sign_sum += ( i % 2 ? 1 : -1 ) * array[i];
  }

  printf("Dynamic sign sum: %d\b", dynamic_sign_sum);
}


typedef struct Vector2 {
  int x;
  int y;
} Vector2;


typedef struct Matrix2 {
  const Vector2 shape;
  const int* data;
} Matrix2;


const int get_mat_size(Matrix2* matrix) {
  return matrix->shape.x * matrix->shape.y;
}


void b() {
  Matrix2 X = (Matrix2) {
    .shape = (Vector2) { 6, 8 },
    .data  = randint_arr(6 * 8, 0, 20),
  };
}


int main() {
  // @NOTE: Random seed initalization
  srand(time(NULL));

  a();
  b();
  return 0;
}

