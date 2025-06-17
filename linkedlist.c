/*
PIC : aufa
NIM : 241524052
*/

#include "linkedlist.h"

static int next_id = 1; 

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

void displayLinkedList(addressList head) {
    if (head == NULL) {
        printf("Daftar tim kosong.\n");
        return;
    }
    
    printf("\n\033[1;36m");
    printf("==================================================\n");
    printf("                  DAFTAR TIM                     \n");
    printf("==================================================\n");
    printf("\033[0m");
    
    printf("\033[1;33m"); 
    printf("%-5s | %-20s\n", "ID", "Nama Tim");
    printf("==================================================\n");
    printf("\033[0m");
    
    addressList current = head;
    int count = 0;
    
    while (current != NULL) {
        if (count % 2 == 0) {
            printf("\033[1;37m"); 
        } else {
            printf("\033[0;37m"); 
        }
        
        printf("%-5d | %-20s\n", current->id_tim, current->namaTim);
        printf("\033[0m"); 
        
        current = current->next;
        count++;
    }
    
    printf("\033[1;36m");
    printf("==================================================\n");
    printf("Total Tim Terdaftar: %d\n", count);
    printf("==================================================\n");
    printf("\033[0m");
}

addressList createNode(infotype info) {
    if (strlen(info) >= 50) {
        printf("Nama tim terlalu panjang (maksimal 49 karakter).\n");
        return NULL;
    }
    addressList p = (addressList)malloc(sizeof(node));
    if (p != NULL) {
        strncpy(p->namaTim, info, 49);
        p->namaTim[49] = '\0'; 
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

void deleteFirst(addressList *head) {
    if (*head == NULL) {
        return;
    }
    addressList temp = *head;
    *head = (*head)->next;
    free(temp);
}

void renumberTeamIDs(addressList head) {
    addressList temp = head;
    int new_id = 1;
    int renumbered_count = 0;
    
    while (temp != NULL) {
        if (temp->id_tim != new_id) {
            temp->id_tim = new_id;
            renumbered_count++;
        }
        new_id++;
        temp = temp->next;
    }
    
    next_id = new_id;
    
    if (renumbered_count > 0) {
        printf("ID tim telah diurutkan ulang (%d tim diperbarui).\n", renumbered_count);
    }
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
        
        renumberTeamIDs(*head);
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
        
        renumberTeamIDs(*head);
    } else {
        printf("Tim %s tidak ditemukan.\n", info);
    }
}

int countNode(addressList head) {
    int count = 0;
    while (head != NULL) {
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
    } else {
        printf("Tim %s tidak ditemukan untuk pembaruan statistik.\n", namaTim);
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

void resetAllTeamStats(addressList head) {
    addressList temp = head;
    int reset_count = 0;
    
    while (temp != NULL) {
        temp->laga = 0;
        temp->kemenangan = 0;
        temp->kekalahan = 0;
        reset_count++;
        temp = temp->next;
    }
    
    printf("   - %d tim direset statistiknya (laga=0, menang=0, kalah=0)\n", reset_count);
}

void resetAllTeamStatsSilent(addressList head) {
    addressList temp = head;
    
    while (temp != NULL) {
        temp->laga = 0;
        temp->kemenangan = 0;
        temp->kekalahan = 0;
        temp = temp->next;
    }        
}

addressList searchNode(addressList head, char* namaTim) {
    addressList temp = head;
    while (temp != NULL) {
        if (strcmp(temp->namaTim, namaTim) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void reorderTeamIDs(addressList *head) {
    if (*head == NULL) {
        printf("Daftar tim kosong, tidak ada yang perlu diurutkan.\n");
        return;
    }
    
    printf("Mengurutkan ulang ID tim...\n");
    renumberTeamIDs(*head);
    printf("ID tim telah diurutkan ulang!\n");
}
