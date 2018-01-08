#include <stdio.h>

//program demonstrates pointer to POINTERS

int main(int argc, char const *argv[]) {
  int var = 789;
  int *ptr_01;
  int **ptr_02;
  int ***ptr_03;

  ptr_01 = &var;
  ptr_02 = &ptr_01;
  ptr_03 = &ptr_02;

  printf("Value of var = %d\n", var);
  printf("Value of ptr_01 = %d, address = %p\n", *ptr_01, ptr_01);
  printf("Value of ptr_02 = %d, address = %p\n", **ptr_02, *ptr_02);
  printf("Value of ptr_01 = %d, address = %p\n", ***ptr_03, **ptr_03);

  return 0;
}
