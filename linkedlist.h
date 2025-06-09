// Nama : Muhammad Danish Aufa
// NIM : 241524052
// Deskripsi : File ini berisikan definisi untuk variabel dan fungsi pada file linkedlist.c

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "convention.h"

typedef char* infotype;

typedef struct Node {
    int id_tim; 
    char namaTim[50];
    int laga; 
    int kemenangan; 
    int kekalahan; 
    struct Node* next;
} node;

typedef node* addressList;

void initLinkedList(addressList *head);
void addToLinkedList(addressList *head, char* namaTim);
void displayLinkedList(addressList head);
addressList createNode(infotype info);
void insertAtFirst(addressList *head, addressList newP);
void insertAtLast(addressList *head, addressList newP);
void DeAlokasi(addressList *head);
void deleteFirst(addressList *head);
void deleteValue(addressList *head, infotype info);
int countNode(addressList head);
void updateTeamStats(addressList head, char* namaTim, int menang, int kalah);
addressList searchNodeById(addressList head, int id_tim);
void resetAllTeamStats(addressList head);

#endif
