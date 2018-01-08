#include <stdio.h>

void wedge_01 (char what, int thisLine, int totalLines);
void wedge_02 (char what, int thisLine, int totalLines);

//demonstartion of functions to create wedges
int main(int argc, char const *argv[]) {
  /* code */
  char what = '#';
  int totalLines = 20;
  for (int i = 1; i <= totalLines; i++) {
    wedge_01(what, i, totalLines);
    printf("   ");
    wedge_01(what, totalLines-i+1, totalLines);

    printf("   ");
    wedge_02(what, i, totalLines);
    printf("   ");
    wedge_02(what, totalLines-i+1, totalLines);

    printf("\n");
  }

  return 0;
}

//Function declarations
void wedge_01 (char what, int thisLine, int totalLines){

  //print symbol
  for (int i = 1; i <= thisLine; i++) {
    /* code */
    printf("%c", what);
  }

  //print blank space
  for (int i = 0; i <(totalLines-thisLine); i++) {
    /* code */
    printf(" ");
  }
}

//Function declarations
void wedge_02 (char what, int thisLine, int totalLines){

  //print blank space
  // for (int i = 0; i > totalLines-thisLine; i++) {
  //   /* code */
  //   printf(" ");
  // }

  //print symbol
  for (int i = 1; i <= thisLine; i++) {
    /* code */
    printf("%c", what);
  }

}
