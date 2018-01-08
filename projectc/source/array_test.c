//Tutorials on Array
#include <stdio.h>

int main(int argc, char const *argv[]) {
  /* code */
  int grades[5];
  int count = 0;
  int total = 0;

  //assign values to grades
  grades[0] = 57;
  grades[1] = 93;
  grades[2] = 100;
  grades[3] = 83;
  grades[4] = 78;

  //print grades using a while loop
  while (count < 5) {
    /* code */
    printf("Grade %d = %d\n", count+1, grades[count]);
    total += grades[count++];
}

    printf("Class Average = %0.2f for %d students.\n", total/(count*1.0), count);

//an array of chars
    char hello[] = {'H','e','l','l','o'};
    count = 0;
    while (count < 5) {
      /* code */
      printf("%c", hello[count++]);
    }
    printf("\n");

//place the same array as a string
    char hello2[6] = "Hello2";
    printf("%s\n", hello2 );

//place the same array as a string
    char hello3[8] = "Hel\0lo2";
    printf("%s\n", hello3 );

//right wasy to declare a string
    char* helloStar = "Hello";
    printf("%s\n", helloStar);



  return 0;
}
