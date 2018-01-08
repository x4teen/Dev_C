#include <stdio.h>

int getInt(char* prompt);
int sum(int a, int b);
int factorial(int a);


int main(int argc, char const *argv[]) {
  /* code */
  int a = getInt("Enter the first integer : ");
  int b = getInt("Enter the second integer : ");

  //print the sum
  printf("%d + %d = %d\n", a, b, sum(a, b));
  printf("\nFactorial of First integer : %d\n", factorial(a));
  printf("\nFactorial of Second integer : %d\n", factorial(b));

  return 0;
}

int getInt(char* prompt) {
  int input;
  printf("%s\n", prompt);
  scanf("%d", &input);
  return input;
}

int sum(int a, int b) {
  return a+b;
}

int factorial(int a){
  if (a==0) {
    /* code */
    return 1;
  } else {
    return a*factorial(a-1);
  }
}
