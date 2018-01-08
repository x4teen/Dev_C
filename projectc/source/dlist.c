/*
  Program: dlist.c
  Author: Ryan Khan
  Describe: Tutorial for double linked list.
  Date: 2018-01-06
*/

#include <stdio.h>
#include <stdlib.h>

//double-linked node definition
typedef struct node {
  char* name;
  int   account;
  int   balance;
  struct node *pNext;
  struct node *pPrev;
} node;

//GLOBAL LIST POINTERS
node *pHead = NULL;
node *pTail = NULL;
node *pCurrent = NULL;

//LIST FUNCTION MANIPULATION prototypes
void add(char* name, int account);
void delete();
void printCurrent();
void printList();
void prev();
void next();


int main(int argc, char const *argv[]) {
  add("Ryan Khan", 123987);
  add("Yasmeen Khan", 568987);
  printCurrent();
  add("Maya Khan", 568988);
  add("Amrita Khan", 568989);
  printf("%s\n", "@@@@@ Print the Full List @@@@@" );
  printList();

  prev();
  prev();
  delete();
  printf("%s\n", "***** After deleting one item ******" );
  printList();
  printCurrent();
  delete();
  printList();
  delete();
  printList();
  delete();
  printList();
  printCurrent();
  delete();
  printList();
  printCurrent();
  return 0;
}

void add(char* name, int account){
//adds a new node to the end of the Queue
//create a new Node
  node *pNew = malloc(sizeof(node));
  pNew -> name = name;
  pNew -> account = account;
  pNew -> balance = 0;    //all accounts opens with a 0 balance
  pNew -> pPrev = NULL;   //last item on the LIST
  pNew -> pNext = NULL;

  //in case it is the first node
  if (pHead == NULL) {
    pHead = pNew;
    pTail = pNew;
    pCurrent = pNew;
  } else {
    //ADD to the end
    pTail -> pNext = pNew;
    pNew -> pPrev = pTail;
    pTail = pNew;
    pCurrent = pNew;
  }
}

void delete() {
  // Deletes the current Node
  node *pTarget = pCurrent;

  if (pTarget == NULL) {
    /* There is nothing to delete */
    printf("%s\n", "Error: Nothing to delete." );
    return;
  }

  if ((pTarget==pHead) && (pTarget->pNext == NULL)) {
    /* WHEN WE ARE DELETING THE ONE AND ONLY NODE */
    pHead = NULL;
    pTail = NULL;
    pCurrent = NULL;
  } else if (pTarget == pHead) {
    /* The first node of the list */
    pTarget->pNext->pPrev = NULL;
    pHead = pCurrent = pTarget->pNext;

  } else if (pTarget == pTail) {
    /* The last node of the list */
    pTarget->pPrev->pNext = NULL;
    pTail = pCurrent = pTarget->pPrev;

  } else {
    //deleting a node in the middle
    pTarget->pPrev->pNext = pCurrent = pTarget->pNext;
    pTarget->pNext->pPrev = pTarget->pPrev;
  }

  free(pTarget);
}


void printCurrent() {
  if (pCurrent != NULL) {
    printf("Name: %s\t", pCurrent -> name);
    printf("Account: %d\t", pCurrent -> account);
    printf("Balance: %d\n", pCurrent -> balance);
  } else {
    printf("%s\n", "There is nothing to print");
  }
}

void printList() {
  node *pThisNode = pHead;

  while (pThisNode != NULL) {
    printf("Name: %s\t", pThisNode -> name);
    printf("Account: %d\t", pThisNode -> account);
    printf("Balance: %d\n", pThisNode -> balance);
    pThisNode = pThisNode -> pNext;
  }
}

void prev() {
  if (pCurrent!=pHead) {
    pCurrent = pCurrent->pPrev;
  }
}

void next() {
  if (pCurrent != pTail) {
    pCurrent = pCurrent->pNext;
  }
}
