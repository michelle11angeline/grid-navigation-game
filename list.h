/*list.h - create struct for linked list and declare linked list function*/
/*Guard to prevent multiple inclusion*/
#ifndef LIST_H
#define LIST_H

#include <stdio.h>

/*Generic linked list*/
/*Define a node in linked list*/
typedef struct Node {
    void *data;
    struct Node *next;
} Node;
/* Define a linked list*/
typedef struct {
    Node *head;
    int size;
} LinkedList;

/* Function declaration */
LinkedList* createList(void);
void insertFirst(LinkedList *list, void *data);
void freeList(LinkedList *list, void (*freeData)(void*));
void saveToFileReverse(LinkedList *list, const char *filename, void (*printData)(void*, FILE*));

#endif