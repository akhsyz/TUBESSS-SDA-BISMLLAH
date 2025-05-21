/*
PIC : belva 
NIM : 241524035
*/

#include "queue.h"

void initQueue(Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
}

void enqueue(Queue *Q, infotype namaTim) {
    addressList newNode = createNode(namaTim);
    if (newNode == NULL) {
        printf("Gagal membuat node baru untuk Queue.\n");
        return;
    }
    insertAtLast(&(Q->head), newNode);
    if (Q->tail == NULL) {
        Q->tail = newNode;
    } else {
        Q->tail->next = newNode;
        Q->tail = newNode;
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

void manageSeed(Queue *Q) {
    if (Q->head == NULL) {
        printf("Queue kosong, tidak bisa membuat seed.\n");
        return;
    }
    printf("\n=== Penjadwalan Pertandingan ===\n");
    int seed = 1;
    while (Q->head != NULL && Q->head->next != NULL) {
        infotype tim1, tim2;
        dequeue(Q, &tim1);
        dequeue(Q, &tim2);
        printf("Seed %d: %s vs %s\n", seed++, tim1, tim2);
        free(tim1);
        free(tim2);
    }
    if (Q->head != NULL) {
        infotype tim;
        dequeue(Q, &tim);
        printf("Seed %d: %s vs BYE\n", seed++, tim);
        free(tim);
    }
}