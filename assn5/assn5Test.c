/* 
 * Sample testing program for Assignment 5.  Your linkedList.c file will
 * be tested with a different main program.
 * CISC 220, Fall 2016
 * M. Lamb
 */

#include "heapReport.h"
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("start of program: "); heapReport();

  LinkedList list = NULL; // list is initially empty

  printf("\nADDING TO LIST:\n");
  list = addToStart(list, 1);
  printList(list);
  list = addToEnd(list, 2);
  printList(list);
  list = addToStart(list, 3);
  printList(list);
  list = addToEnd(list,4);
  printList(list);
  list = addToStart(list, 5);
  printList(list);
  list = addToEnd(list,6);
  printList(list);

  // Show heap space used 
  heapReport();

  printf("\nTESTING SEARCH FUNCTION:\n");
  int target;
  for (target = 0; target < 8; target++) {
    printf("Searching for %d: ", target);
    if (search(list, target))
      printf("found\n");
    else
      printf("not found\n");
  } // end for

  printf("\nDELETING FROM LIST:\n");
  list = deleteLast(list);
  printList(list);
  list = deleteFirst(list);
  printList(list);
  list = deleteLast(list);
  printList(list);
  list = deleteFirst(list);
  printList(list);

  // Show heap space used 
  heapReport();

  // Add a few more more elements to show that deleting 
  // didn't mess up the list
  printf("\nADDING MORE TO LIST:\n");
  list = addToStart(list,7);
  printList(list);
  list = addToEnd(list,8);
  printList(list);
  
  // Show heap space used 
  heapReport();

  // Empty out the list
  printf("\nEMPTYING THE LIST:\n");
  while (list != NULL) {
    list = deleteFirst(list);
    printList(list);
    list = deleteLast(list);
    printList(list);
  } // end while

  // Show heap space again; if delete functions have freed space
  // it should be zero.
  printf("after emptying list: "); heapReport();

  return 0;
} // end main
