/*
 * Лабoраторная №2
 * Аккузин Илья (ПИН-2022-1)
 *
 * $ gcc lab02.c -o lab02
 * */
#include <stdio.h>
#include <memory.h>

#define NAME_BUFFER_MIN_SIZE 15


typedef unsigned int uint;

int main() {

  char a;
  printf("Введите символ: ");
  scanf("%c", &a);
  printf("Вы ввели: \"%c\"\n", a);


  char name[NAME_BUFFER_MIN_SIZE];
  printf("Меня зовут: ");
  scanf("%s", name);
  printf("Вы ввели: \"%s\"\n", name);
  printf("Длинна строки: %ld\n", strlen(name));


  int x, y;
  printf("Введите два целых числа... \n");
  printf("[0]: ");
  scanf("%d", &x);
  printf("[1]: ");
  scanf("%d", &y);
  printf("Вы ввели: %d, %d\n", x, y);


  float z, j;
  printf("Введите два числа с плавающей точкой...\n");
  printf("[0]: ");
  scanf("%f", &z);
  printf("[1]: ");
  scanf("%f", &j);
  printf("Вы ввели: \"%f, %f\"\n", z, j);
  printf(">> %.4e\n", z);
  printf(">> %.4e\n", j);


  uint h;
  printf("Введите положительное число...\n");
  printf("[0]: ");
  scanf("%u", &h);
  printf("Вы ввели: \"%u\"\n", h);
  printf("В восьмеричной: \"%o\"\n", h);
  printf("В шеснадцатеричной: \"%x\"\n", h);

  return 0;
}
