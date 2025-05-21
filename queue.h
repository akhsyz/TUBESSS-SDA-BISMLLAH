/*
PIC : belva 
NIM : 241524035
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "convention.h"

typedef struct {
    addressList head;
    addressList tail;
} Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, infotype namaTim);
void dequeue(Queue *Q, infotype *namaTim);
void manageSeed(Queue *Q);

#endif