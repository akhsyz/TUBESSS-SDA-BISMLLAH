// Nama : Muhammad Danish Aufa
// NIM : 241524052
// Deskripsi : File ini berisikan implementasi dari fungsi-fungsi yang dideklarasikan di linkedlist.h untuk mengelola linked list

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
   
    printf("\033[1;36m"); 
    printf("\n== Daftar Tim ==\n");
    printf("%-5s %-8s %-6s %-6s %-6s\n", 
           "ID", "Nama", "Laga", "Menang", "Kalah");
    printf("\033[0m"); 
    addressList current = head;
    int row = 0;
    while (current != NULL) {
        
        if (row % 2 == 0)
            printf("\033[1;37m"); 
        else
            printf("\033[0;37m"); 
        char namaPendek[9];
        strncpy(namaPendek, current->namaTim, 8);
        namaPendek[8] = '\0';
        printf("%-5d %-8s %-6d %-6d %-6d\n", 
               current->id_tim, namaPendek, 
               current->laga, current->kemenangan, current->kekalahan);
        printf("\033[0m"); 
        current = current->next;
        row++;
    }
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
    while (temp != NULL) {
        temp->laga = 0;
        temp->kemenangan = 0;
        temp->kekalahan = 0;
        temp = temp->next;
    }
}
