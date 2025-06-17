#include "menu.h"

int main() {
    addressList head = NULL;
    Queue matchQueue;
    TournamentTree *tournamentTree = NULL; 
    Stack matchHistory;
    char namaEvent[50] = "";

    initLinkedList(&head);
    initQueue(&matchQueue);
    inisialisasiStack(&matchHistory);

    initialUI(&head, &matchQueue, &tournamentTree, &matchHistory, namaEvent);

    return 0;
}