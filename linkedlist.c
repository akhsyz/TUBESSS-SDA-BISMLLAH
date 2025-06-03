// Nama : Muhammad Danish Aufa
// NIM : 241524052
// Deskripsi : File ini berisikan implementasi dari fungsi-fungsi yang dideklarasikan di linkedlist.h untuk mengelola linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

static int next_id = 1; // Variabel statis untuk ID unik

void initLinkedList(addressList *head) {
    *head = NULL;
    next_id = 1;
}

void addToLinkedList(addressList *head, char* namaTim) {
    addressList temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->namaTim, namaTim) == 0) {
            printf("Tim %s sudah ada!\n", namaTim);
            return;
        }
        temp = temp->next;
    }
    addressList newNode = createNode(namaTim);
    if (newNode == NULL) {
        printf("Gagal membuat node baru.\n");
        return;
    }
    newNode->id_tim = next_id++;
    newNode->laga = 0;
    newNode->kemenangan = 0;
    newNode->kekalahan = 0;
    insertAtLast(head, newNode);
    printf("Tim %s berhasil ditambahkan.\n", namaTim);
}

void removeFromLinkedList(addressList *head, char* namaTim) {
    infotype info;
    deleteValue(head, namaTim);
    printf("Tim %s berhasil dihapus.\n", namaTim);
}

void displayLinkedList(addressList head) {
    if (head == NULL) {
        printf("Daftar tim kosong.\n");
        return;
    }
    printf("\n== Daftar Tim ==\n");
    addressList current = head;
    int count = 1;
    while (current != NULL) {
        printf("%d. %s\n", count++, current->namaTim);
        current = current->next;
    }
}

addressList createNode(infotype info) {
    addressList p = (addressList)malloc(sizeof(node));
    if (p != NULL) {
        strcpy(p->namaTim, info);
        p->id_tim = 0;
        p->laga = 0;
        p->kemenangan = 0;
        p->kekalahan = 0;
        p->next = NULL;
    }
    return p;
}

void insertAtFirst(addressList *head, addressList newP) {
    if (newP == NULL) return;
    newP->next = *head;
    *head = newP;
}

void insertAtLast(addressList *head, addressList newP) {
    if (newP == NULL) return;
    newP->next = NULL;
    if (*head == NULL) {
        *head = newP;
    } else {
        addressList last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newP;
    }
}

void DeAlokasi(addressList *head) {
    addressList temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void deleteFirst(addressList *head, infotype *info) {
    if (*head == NULL) {
        *info = NULL;
        return;
    }
    addressList temp = *head;
    *info = temp->namaTim;
    *head = temp->next;
    free(temp);
}

void deleteValue(addressList *head, infotype info) {
    if (*head == NULL) {
        printf("Daftar tim kosong.\n");
        return;
    }
    if (strcmp((*head)->namaTim, info) == 0) {
        addressList temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    addressList prev = *head, temp = (*head)->next;
    while (temp != NULL && strcmp(temp->namaTim, info) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Tim %s tidak ditemukan.\n", info);
    }
}

int countNode(addressList L) {
    int count = 0;
    while (L != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void updateTeamStats(addressList head, char* namaTim, int menang, int kalah) {
    addressList temp = head;
    while (temp != NULL && strcmp(temp->namaTim, namaTim) != 0) {
        temp = temp->next;
    }
    if (temp != NULL) {
        temp->laga += 1;
        temp->kemenangan += menang;
        temp->kekalahan += kalah;
    }
}

addressList searchNodeById(addressList head, int id_tim) {
    addressList temp = head;
    while (temp != NULL) {
        if (temp->id_tim == id_tim) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
