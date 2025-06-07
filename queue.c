/*
PIC : belva 
NIM : 241524035
*/

#include "queue.h"

void initQueue(Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
}

void enqueue(Queue *Q, addressList teamNode) {
    if (teamNode == NULL) {
        printf("Node tidak valid untuk enqueue.\n");
        return;
    }
    insertAtLast(&(Q->head), teamNode);

    if (Q->tail == NULL) {
        Q->tail = teamNode;
    } else {
        addressList temp = Q->head;
        while (temp->next != NULL) temp = temp->next;
        Q->tail = temp;
    }
}

void dequeue(Queue *Q) {
    if (Q->head == NULL) {
        printf("Queue kosong.\n");
        return;
    }
    deleteFirst(&(Q->head)); 
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