/*
  maxmin.c
  Find the max and min value in an array
  using pointer arithmetic

  Dangerous code that
*/
#include <stdio.h>
#include <limits.h>   //for maximum and minimum values

int max(int *array, int count);
int min(int *array, int count);
void walkWithChars(int *array, int count);

int main(int argc, char const *argv[]) {

  int numbers[] = {3, -4, 79, 0, 5, 8, 42, 109, 85};

  //show the equivalency of [] and pointer notation:
  printf("numbers[0] :%d and *numbers : %d\n", numbers[0], *numbers);
  printf("numbers[4] :%d and *(numbers+4) : %d\n", numbers[4], *(numbers+4));

  //print out the max and the min of the array
  printf("The max is %d\n", max(numbers, 9));
  printf("The min is %d\n", min(numbers, 9));

  //using mismatched array
  walkWithChars(numbers, 9);

  return 0;
}


int max(int *array, int count) {
  int maxNum = *array;
  int i = 0;

  while (i < count) {
    /* code */
    if (*(array+i)> maxNum) {
      /* code */
      maxNum = *(array+i);
    }
    i++;
  }
  return maxNum;
}



int min(int *array, int count){
  int minNum = *array;
  int i = 0;

  while (i < count) {
    /* code */
    if (*(array+i)< minNum) {
      /* code */
      minNum = *(array+i);
    }
    i++;
  }
  return minNum;
}

void walkWithChars(int *array, int count) {
  /* code */
  char *pNumber = array;    //pointer to int is assigned pointer to chars
  for (int i = 0; i < count; i++) {
    printf("char at array[%d] : %d\n", i, *(pNumber + i));
    pNumber++;
  }

}
