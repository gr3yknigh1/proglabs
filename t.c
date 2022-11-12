#include <stdio.h>

int main() {

  const int m = 12;
  const int n = 4;

  int count = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      count++;
    }
  }

  printf("%d", count); // 48
  printf("%d", m * n); // 48
}
