/*
PIC : belva 
NIM : 241524035
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

typedef struct {
    addressList head;
    addressList tail;
} Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, addressList node);
void dequeue(Queue *Q);
void reverseQueue(Queue *Q);

#endif