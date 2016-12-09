#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/*
 * Keyan Fayaz - 14kf34
 * Student ID#: 10188190
 * 
 * CISC220 w/ M. Lamb 
 * Assignment 5: Linked Lists
 */


// Adds value to the start of the list, returns pointer of the modified list
LinkedList addToStart(LinkedList list, int value) {

  // Create the new node and its values
  LinkedList newNode = (LinkedList)malloc(sizeof(struct ListNode));   

  newNode->data = value;
  newNode->next = list;
  list = newNode;

  return list;
}

// Adds value to the end of the list, returns pointer of the modified list
LinkedList addToEnd(LinkedList list, int value) {

  // Create the new node and its values
  LinkedList newNode = (LinkedList)malloc(sizeof(struct ListNode));

  newNode->data = value;
  newNode->next = NULL;

  LinkedList temp;
  temp = list;

  // If empty
  if (list == NULL) {
    list = newNode;
  } else {
    // Iterate temp to the last item, add newNode there
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return list; 
}

// Deletes first element and returns pointer of the modified list
LinkedList deleteFirst(LinkedList list) {

  // Pointers for the temporary pointer and previous
  LinkedList temp, prev;
  temp = list;

  // If empty
  if (list == NULL) {
    return NULL;
    // If list contains one element
  } else if (list->next == NULL) {
    list = NULL;
    free(temp);
    // Delete the first node
  } else {
    prev = list;
    list = list->next; 
    free(prev);
    // If not empty after removing the first node
    if (list->next != NULL) {
      return list;
    }
  }

  return list;
}

// Deletes the last element and returns pointer of the modified list
LinkedList deleteLast(LinkedList list) {

  // Pointer for the temporary value, used to iterate through the list, and a pointer to that previous value
  LinkedList temp, prev;
  temp = list;
  
  // If empty
  if (list == NULL) {
    return NULL;
    // If contains one element
  } else if (list->next == NULL) {
    list = NULL;
    free(temp);
    // Obtain the second last element and assign it to prev
  } else {
    while(temp->next != NULL) {
      prev = temp;
      temp = temp->next;
    }
    // Eliminate the last node
    prev->next = NULL;
    free(temp);
  }

  return list;
}

// Prints the list. Format: [1,2,3,4] -- square brackets, seperated by commas, no spaces
void printList(LinkedList list) {
  
  LinkedList temp;
  temp = list;
  
  // Print the list according to the format
  printf("[");
  while ((temp != NULL) && (temp->next != NULL)) { // Iterate through the list
    printf("%d,", temp->data);
    temp = temp->next;
  }
  // If last element... used mainly to prevent errors with an empty list
  if (temp != NULL) {
    printf("%d", temp->data);
  }
  printf("]\n");
}

// Searches the list and returns 1 if found, 0 otherwise
int search(LinkedList list, int value) {

  // Iterate through the list
  while (list != NULL) {
    // If value is found
    if (list->data == value) {
      return 1;
    }
    list = list->next;
  }
  
  return 0; // If not found
}
