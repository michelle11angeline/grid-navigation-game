/*list.c - create linked list and it's function (insert, free, save to file)*/
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/* Create a new empty linked list */
LinkedList* createList(void) {
    /*Allocate struct variable to be used in function*/
    LinkedList *list = malloc(sizeof(LinkedList));
    if (!list) return NULL;
    /*point the head to null and initialize the size to zero*/
    list->head = NULL;
    list->size = 0;
    return list;
}

/* Insert new node at the beginning of the list */
void insertFirst(LinkedList *list, void *data) {
    /*Allocate struct variable to be used in function*/
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return;
    
    /*- creating new node and make next pointer to current head -*/
    /*Update the new node as head node & increment the list size*/
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

/* Free the entire list and its nodes */
void freeList(LinkedList *list, void (*freeData)(void*)) {
    /*Transver through the list from the head to free all node*/
    Node *current = list->head;
    while (current) {
        Node *next = current->next;
        if (freeData) {
            freeData(current->data);
        }
        free(current);
        current = next;
    }
    free(list);
}

/* Save list contents to file in reverse order */
void saveToFileReverse(LinkedList *list, const char *filename, void (*printData)(void*, FILE*)) {
    /*Variable declaration*/
    int i;
    FILE *file;
    void **nodes;
    Node *current;

    if (!list || !filename || !printData) return;
    
    /*Open file to write*/
    file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }
    
    /* Temporary array to store nodes for reverse output */
    nodes = malloc(sizeof(void*) * list->size);
    if (!nodes) {
        fclose(file);
        return;
    }
    
    /* Store nodes in array */
    current = list->head;
    for (i = 0; current && i < list->size; i++) {
        nodes[i] = current->data;
        current = current->next;
    }
    
    /* Write to file in reverse order */
    for (i = list->size - 1; i >= 0; i--) {
        printData(nodes[i], file);
        fprintf(file, "\n");
    }
    
    free(nodes);
    fclose(file);
}
