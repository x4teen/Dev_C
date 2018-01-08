#include <stdio.h>

int main(int argc, char const *argv[]) {
  /* code */
  int count = 0;

  //while loop
  printf("%s\n", "While Loop");

  while (count < 10) {
    /* code */
    printf("%d\t", count++);
  }
  printf("\n\n");

  //do while loop
  printf("%s\n", "Do While Loop");
  
  do {
    /* code */
    printf("%d\t", count++);
  } while (count <10);

  printf("\n\n");

  //for Loop
  printf("%s\n", "For Loop");

  for (int i = 0; i < 10; i+=2) {
    /* code */
    printf("%d\t", i);
  }

  printf("\n\n");

  return 0;
}
