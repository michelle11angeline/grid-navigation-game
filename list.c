#include <stdlib.h>
#include <stdio.h>
#include "list.h"

LinkedList* createList(void) {
    LinkedList *list = malloc(sizeof(LinkedList));
    if (!list) return NULL;

    list->head = NULL;
    list->size = 0;
    return list;
}

void insertFirst(LinkedList *list, void *data) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return;

    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void freeList(LinkedList *list, void (*freeData)(void*)) {
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

void saveToFileReverse(LinkedList *list, const char *filename, void (*printData)(void*, FILE*)) {
    int i;
    FILE *file;
    void **nodes;
    Node *current;

    if (!list || !filename || !printData) return;

    file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    nodes = malloc(sizeof(void*) * list->size);
    if (!nodes) {
        fclose(file);
        return;
    }

    current = list->head;
    for (i = 0; current && i < list->size; i++) {
        nodes[i] = current->data;
        current = current->next;
    }

    for (i = list->size - 1; i >= 0; i--) {
        printData(nodes[i], file);
        fprintf(file, "\n");
    }

    free(nodes);
    fclose(file);
}