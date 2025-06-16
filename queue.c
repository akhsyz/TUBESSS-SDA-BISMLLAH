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
    
    // Buat copy node untuk queue agar tidak mengganggu linked list asli
    addressList newNode = (addressList)malloc(sizeof(addressList));
    if (newNode == NULL) {
        printf("Gagal mengalokasi memori untuk queue node.\n");
        return;
    }
    
    // Copy data dari teamNode
    newNode->id_tim = teamNode->id_tim;
    strcpy(newNode->namaTim, teamNode->namaTim);
    newNode->next = NULL;
    
    // Jika queue kosong
    if (Q->head == NULL) {
        Q->head = newNode;
        Q->tail = newNode;
    } else {
        // Tambahkan di akhir queue
        Q->tail->next = newNode;
        Q->tail = newNode;
    }
}

void dequeue(Queue *Q) {
    if (Q->head == NULL) {
        printf("Queue kosong.\n");
        return;
    }
    
    addressList temp = Q->head;
    Q->head = Q->head->next;
    
    // Jika queue menjadi kosong setelah dequeue
    if (Q->head == NULL) {
        Q->tail = NULL;
    }
    
    free(temp);
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

// Fungsi helper untuk membersihkan queue
void clearQueue(Queue *Q) {
    while (Q->head != NULL) {
        dequeue(Q);
    }
}

// Fungsi helper untuk menampilkan isi queue
void displayQueue(Queue *Q) {
    if (Q->head == NULL) {
        printf("Queue kosong.\n");
        return;
    }
    
    printf("Isi Queue:\n");
    addressList temp = Q->head;
    int index = 1;
    while (temp != NULL) {
        printf("%d. %s (ID: %d)\n", index++, temp->namaTim, temp->id_tim);
        temp = temp->next;
    }
}