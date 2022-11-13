/*
 * Лабораторная №6
 * Аккузин Илья (ПИН-2022-1)
 *
 * Вариант №1:
 * a) Задан массив А(20). Определить знакопеременную сумму а2 + а3 – а4 + ...
 * б) Просуммировать элементы матрицы Х(6,8), сумма индексов которых равна заданной
 * константе К.
 *
 * $ gcc lab06.c -o lab06
 * */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

  printf("Dynamic sign sum: %d\n", dynamic_sign_sum);
}


typedef struct Vector2 {
  int x;
  int y;
} Vector2;


typedef struct Matrix2 {
  const Vector2 shape;
  int **elements;
} Matrix2;


const int get_mat_size(Matrix2* matrix) {
  return matrix->shape.x * matrix->shape.y;
}


const int get_element(const Matrix2* matrix, int x, int y) {
  if (x >= matrix->shape.x || y >= matrix->shape.y) {
    printf("Error: can't access to [%d:%d] element of matrix in %p\n", x, y, matrix);
    return 0;
  }
  return matrix->elements[x][y];
}


void print_mat(const Matrix2* matrix) {
  for (int x = 0; x < matrix->shape.x; x++) {
    for (int y = 0; y < matrix->shape.y; y++) {
      printf("%d\t", get_element(matrix, x, y));
    }
    printf("%c", '\n');
  }
}


void b() {

  Vector2 shape = (Vector2) { 6, 8 };
  int **elements = malloc(sizeof(int*) * shape.x);
  for (int i = 0; i < shape.x; i++) {
    elements[i] = malloc(sizeof(int) * shape.y);
  }

  for (int i = 0; i < shape.x; i++) {
    for (int j = 0; j < shape.y; j++) {
      elements[i][j] = randint(0, 20);
    }
  }

  Matrix2 X = (Matrix2) {
    .shape = shape,
    .elements = elements,
  };

  print_mat(&X);

  int K;
  while (true) {
    printf("K: ");
    scanf("%d", &K);
    if (K > X.shape.x + X.shape.y || K <= 0) {
      printf("K must be greater than 0 and less than %d\n", X.shape.x + X.shape.y);
      continue;
    }
    break;
  }

  int sum = 0;
  for (int x = 0; x < X.shape.x; x++) {
    for (int y = 0; y < X.shape.y; y++) {
      if (x + y == K) {
        sum += get_element(&X, x, y);
      }
    }
  }

  printf("Sum: %d", sum);
}


int main() {
  // @NOTE: Random seed initalization
  srand(time(NULL));

  a();
  b();
  return 0;
}

