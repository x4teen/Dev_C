#include <stdio.h>

void swap (int *a, int *b);

int main(int argc, char const *argv[]) {
  /* code */
  int a = 10;
  int *b = &a;

  printf("a =%d, &a =%p, b= %p, *b = %d, \n", a, &a, b, *b);
  printf("sizeof a = %lu, sizeof b = %lu\n\n", sizeof a, sizeof b);

  *b = 5;
  printf("a =%d, &a =%p, b= %p, *b = %d, \n", a, &a, b, *b);

  int x = 7;
  int y = 9;

  printf("Value before swap x=%d and y=%d\n", x, y);
  swap (&x, &y);
  printf("Value after swap x=%d and y=%d\n", x, y);

  return 0;
}


void swap(int *a, int *b) {
  /* code */
  int temp = *a;
  *a = *b;
  *b = temp;
}
