#include <stdio.h>

int main() {

  // Если под матрицей имеется ввиду двумерный массив, то вот:

  int matrix[3][3] = {
    { 9, 2, 3 },
    { 3, 2, 1 },
    { 5, 6, 1 },
  };

  int* ptr = *matrix;
  printf("%d\n", *ptr); // - «9»

  return 0;
}

