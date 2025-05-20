// Nama : Muhammad Danish Aufa
// NIM : 241524052
// Deskripsi : File ini berisikan definisi untuk variabel dan fungsi pada file linkedlist.c

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    char namaTim[50];
    int laga;
    int kemenangan;
    int kekalahan;
    struct Node* next;
} Node;

extern Node* head;

void initLinkedList();
void addToLinkedList(char* namaTim);
void removeFromLinkedList(int index);
void displayLinkedList();

#endif
