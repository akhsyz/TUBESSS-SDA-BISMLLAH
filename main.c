#include "menu.h"

int main() {
    addressList head = NULL;
    Queue matchQueue;
    addressTree tournamentTree = NULL;
    Stack matchHistory;
    char namaEvent[50] = "";

    // Inisialisasi struktur data
    initLinkedList(&head);
    initQueue(&matchQueue);
    inisialisasiStack(&matchHistory);

    // Tampilkan UI awal
    initialUI(&head, &matchQueue, &tournamentTree, &matchHistory, namaEvent);

    return 0;
}