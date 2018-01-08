/*
    stack_test.c
*/

#include <stdio.h>
#include <stdlib.h>   //malloc and free
#include <limits.h>   // for INT_MIN

// a stack node
typedef struct node {
  int data;
  struct node *pNext;
} node;

//pointer to top of stack
node *pTop = NULL;

//function prototypes
  void push(int value);
  int pop();
  void clear();
  void error(char* msg);
  void printStack();
  void reverse();
  void swap();
  void add();

int main(int argc, char const *argv[]) {
  push(1);
  push(2);
  push(3);
  push(5);
  push(8);
  printStack();
  //add();
  reverse();
  printStack();
  swap();
  printStack();
  clear();

  return 0;
}

void push(int value) {
  if (pTop == NULL) {
    // stack empty, just set pTop to a new code
    pTop = malloc(sizeof(node));
    pTop -> data = value;
    pTop -> pNext = NULL;
  } else {
    //make a new node
    node *pNew = malloc(sizeof(node));
    pNew -> data = value;
    //assign this node's next pointer to the top node:
    pNew -> pNext = pTop;
    //this node is the new top of stack:
    pTop = pNew;
  }
}

int pop(){
  //check to see if the stack is empty

  if (pTop == NULL) {
    return INT_MIN;
  } else {
    int retVal = pTop -> data;
    //temp pointer to the Top
    node *pTemp = pTop;
    //set pTop to the next Node
    pTop = pTemp-> pNext;
    //free temp Node
    free(pTemp);
    return retVal;
  }
}

void clear() {
  while (pTop != NULL) {
    pop();
  }
}

void printStack() {
  //get a temporary pointer
  node *pTemp = pTop;

  if (pTemp==NULL) {
    error("Empty Stack Error");
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
  int iTemp = pTop -> data;
  node *pTemp = pTop -> pNext;

  pTop -> data = pTemp -> data;
  pTemp -> data = iTemp;
}

void add() {
  node *pTemp = pTop -> pNext;
  int value = pTop -> data + pTemp -> data;

  pTemp -> data = value;
  pop();
}

void reverse() {
  node *pTempStack = malloc(sizeof(node));
  //pushing the top element if the stack is not empty
  if (pTop != NULL) {
    pTempStack -> data = pop();
    pTempStack -> pNext = NULL;
  }

  //POP all remaining elements of the main stack and push them on temporary stack
  while (pTop != NULL) {
    //create new stack by pushing
    node *pNextNode = malloc(sizeof(node));
    pNextNode -> data = pop();
    pNextNode-> pNext = pTempStack;
    pTempStack = pNextNode;

  }

  //After all elements are POPped, point to the new Stack
  pTop = pTempStack;

}
