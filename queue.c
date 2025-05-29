/*
PIC : belva 
NIM : 241524035
*/

#include "queue.h"

void initQueue(Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
}

void enqueue(Queue *Q, addressList node) {
    if (node == NULL) {
        printf("Node tidak valid untuk enqueue.\n");
        return;
    }

    insertAtLast(&(Q->head), node);

    if (Q->tail == NULL) {
        Q->tail = node; 
    } else {
        Q->tail = node; 
    }
}

void dequeue(Queue *Q, infotype *namaTim) {
    if (Q->head == NULL) {
        printf("Queue kosong.\n");
        *namaTim = NULL;
        return;
    }
    deleteFirst(&(Q->head), namaTim); 
    if (Q->head == NULL) {
        Q->tail = NULL; 
    }
}

void reverseQueue(Queue *Q) {
    if (Q->head == NULL || Q->head == Q->tail) {
        return; 
    }

    addressList prev = NULL;
    addressList current = Q->head;
    addressList next = NULL;
    Q->tail = Q->head; 

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;      
        current = next;      
    }

    Q->head = prev; 
}