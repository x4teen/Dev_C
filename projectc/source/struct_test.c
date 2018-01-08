#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  //using typedef to define an alias for char*
  typedef char* string;

  //define a new type called book
  typedef struct {
    string title;
    string author;
    short pages;
  } Book;

  //create a book on the stack
  Book book_01;
  book_01.title = "The C Programming Language";
  book_01.author = "Dennis Ritchie & Brian Kernighan";
  book_01.pages = 288;

  //create a pointer to book_02 on the heap
  Book *book_02 = malloc(sizeof(Book));
  book_02 -> title = "Algorithms to Live By";
  book_02 -> author = "Brian Christian";
  book_02 -> pages = 369;

  //pring book titles
  printf("%s by %s\n", book_01.title, book_01.author);
  printf("%s by %s\n", book_02 -> title, book_02 -> author);

  free(book_02);
  return 0;
}
