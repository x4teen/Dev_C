/*
   queue_test.c
*/

#include <stdio.h>
#include <stdlib.h>   //malloc and free
#include <limits.h>   // for INT_MIN

// a Queue node
typedef struct node {
  int data;
  struct node *pNext;
} node;

//pointer to End of Queue
node *pHead = NULL;
node *pEnd = NULL;

//function prototypes
  void addToQ(int value);
  int removeFromQ();
  void clear();
  void error(char* msg);
  void printQueue(char* msg);
  void add();
  void reverse();
  void swap();


int main(int argc, char const *argv[]) {
  //Create the Queue
  addToQ(1);
  addToQ(2);
  addToQ(3);
  addToQ(5);
  addToQ(8);
  addToQ(13);

  //Test Queue Functions
  printQueue("Original Queue");
  reverse();
  printQueue("Reversed");
  removeFromQ();
  // reverse();
  printQueue("Revoved First Element");
  swap();
  printQueue("Swapped");
  add();
  printQueue("Added");
  clear();
  printQueue("Cleared");

  return 0;
}

void addToQ(int value) {
  if (pHead == NULL) {
    // Queue empty, just set pEnd to a new code
    pHead = malloc(sizeof(node));
    pEnd = pHead;
    pEnd -> data = value;
    pEnd -> pNext = NULL;
  } else {
    //make a new node
    node *pNew = malloc(sizeof(node));
    pNew -> data = value;
    pNew -> pNext = NULL;
    //assign this node's Before pointer to the End node:
    pEnd -> pNext = pNew;

    //this node is the new End of Queue:
    pEnd = pNew;
  }
}

int removeFromQ(){
  //check to see if the Queue is empty

  if (pHead == NULL) {
    return INT_MIN;
  } else {
    int retVal = pHead -> data;
    //temp pointer to the End
    node *pTemp = pHead;
    //set pEnd to the Before Node
    pHead = pTemp-> pNext;
    //free temp Node
    free(pTemp);
    return retVal;
  }
}

void clear() {
  while (pHead != NULL) {
    removeFromQ();
  }
}

void printQueue(char* msg) {
  //get a temporary pointer
  node *pTemp = pHead;

  printf("*** %s ***\n", msg );

  if (pTemp==NULL) {
    error("Empty Queue Error");
    return;
  }

  while (pTemp != NULL) {
    printf("%d\n", pTemp -> data);
    pTemp = pTemp -> pNext;
  }

  printf("\n");
}

void error(char* msg) {
  printf("%s\n", msg);
}

void swap() {
  //temporary store for swap
  int iTemp = pHead -> data;
  node *pTemp = pHead -> pNext;

  pHead -> data = pTemp -> data;
  pTemp -> data = iTemp;
}

void add() {
  node *pTemp = pHead -> pNext;
  int value = pHead -> data + pTemp -> data;

  pTemp -> data = value;
  removeFromQ();
}

void reverse() {
  node *pTempQueue = malloc(sizeof(node));
  node *pTempHead = pTempQueue;
  //addToQing the End element if the Queue is not empty
  if (pHead != NULL) {
    pTempQueue -> data = removeFromQ();
    pTempQueue -> pNext = NULL;
    pEnd = pTempQueue;
  }

  //removeFromQ all remaining elements of the main Queue and addToQ them on temporary Queue
  while (pHead != NULL) {
    //create new Queue by addToQing
    node *pNextNode = malloc(sizeof(node));
    pNextNode -> data = removeFromQ();
    pNextNode-> pNext = pTempQueue;
    pTempQueue = pNextNode;
  }

  //After all elements are removeFromQped, point to the new Queue
  pHead = pTempQueue;

}
