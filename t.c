#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10

int main() {

  char* c_ptr;
  char c_arr[N] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', };

  c_ptr = c_arr;
  printf("%li\n", strlen(c_ptr)); // 10

  int c_ptr_size = 20;
  c_ptr = malloc(sizeof(char) * c_ptr_size);
  memset(c_ptr, 'a', sizeof(char) * c_ptr_size);
  c_ptr[c_ptr_size] = '\0';

  printf("%s\n", c_ptr);
  printf("%li\n", strlen(c_ptr)); // 20

  const char* name = "a";
  name = "s";

  return 0;
}
