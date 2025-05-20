// Nama : Muhammad Danish Aufa
// NIM : 241524052
// Deskripsi : File ini berisikan implementasi dari fungsi-fungsi yang dideklarasikan di linkedlist.h untuk mengelola linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

Node* head = NULL;

void initLinkedList() {
    head = NULL;
}

void addToLinkedList(char* namaTim) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->namaTim, namaTim);
    newNode->laga = 0;
    newNode->kemenangan = 0;
    newNode->kekalahan = 0;
    newNode->next = head;
    head = newNode;
}

void removeFromLinkedList(int index) {
    if (head == NULL) return;
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* current = head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) return;
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void displayLinkedList() {
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        printf("%d. %s\n", count++, current->namaTim);
        current = current->next;
    }
}
