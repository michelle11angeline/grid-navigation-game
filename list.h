#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

LinkedList* createList(void);
void insertFirst(LinkedList *list, void *data);
void freeList(LinkedList *list, void (*freeData)(void*));
void saveToFileReverse(LinkedList *list, const char *filename, void (*printData)(void*, FILE*));

#endif