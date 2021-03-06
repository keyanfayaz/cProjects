/*
 * Linked list type definitions to be used with Assignment 5.
 * Your program *must* work with this header file.
 * Don't waste server space by submitting a copy, since
 * the TAs will have the file already.  
 *
 * CISC 220, Fall 2016
 * M. Lamb
 */

// A single node in a linked list
struct ListNode {
  int data; // the data in this node
  struct ListNode *next; // point to next node, NULL for last node in the list
};

// Refer to a linked list with a pointer to the first node
typedef struct ListNode *LinkedList;

/* 
 * Parameters: 
 *    1. a linked list (pointer to the first node, or NULL for an empty list)
 *    2. a value to add to the start of the list
 * Returns a pointer to the start of the modified list.
 */
LinkedList addToStart(LinkedList list, int value);

/* 
 * Parameters: 
 *    1. a linked list (pointer to the first node, or NULL for an empty list)
 *    2. a value to add to the end of the list
 * Returns a pointer to the end of the modified list.
 */
LinkedList addToEnd(LinkedList list, int value);

/* 
 * Parameter: a linked list (pointer to the first node, 
 *     or NULL for an empty list)
 * Deletes the first element of the linked list and 
 * returns a pointer to the modified list (or NULL if
 * the list is now empty).
 */
LinkedList deleteFirst(LinkedList list);

/* 
 * Parameter: a linked list (pointer to the first node, 
 *     or NULL for an empty list)
 * Deletes the last element of the linked list and 
 * returns a pointer to the modified list (or NULL if
 * the list is now empty).
 */
LinkedList deleteLast(LinkedList list);

/*
 * Parameter: a linked list of numbers.
 * Prints the list to the standard output in a format like this: [1,2,3,4] --
 * enclosed in square brackets, numbers separated by commas, and no spaces.
 * Follows the list with an end of line character.
 */
void printList(LinkedList list);

/*
 * Parameters:
 *   1. a linked list of numbers
 *   2. a value to search for
 * Searches the list and returns 1 if the value occurs
 * at least once in the list and 0 if it does not.
 */
int search(LinkedList list, int value);
