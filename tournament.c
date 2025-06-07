#include "tournament.h"

void tambahTim(addressList *head) {
    int jmlTim;
    if (scanf("%d", &jmlTim) != 1 || jmlTim <= 0) {
        printf("Jumlah tim tidak valid.\n");
        while (getchar() != '\n'); // Bersihkan buffer
        return;
    }
    char namaTim[50];
    for (int i = 0; i < jmlTim; i++) {
        printf("Nama Tim %d: ", i + 1);
        if (scanf(" %49[^\n]", namaTim) != 1) {
            printf("Input nama tim tidak valid.\n");
            while (getchar() != '\n'); // Bersihkan buffer
            return;
        }
        addToLinkedList(head, namaTim);
        while (getchar() != '\n'); // Bersihkan buffer
    }
}

void hapusTim(addressList *head) {
    if (*head == NULL) {
        printf("Daftar tim kosong.\n");
        return;
    }
    char namaTim[50];
    printf("Pilih Tim yang ingin dihapus: ");
    if (scanf(" %49[^\n]", namaTim) != 1) {
        printf("Input nama tim tidak valid.\n");
        while (getchar() != '\n'); // Bersihkan buffer
        return;
    }
    deleteValue(head, namaTim);
    printf("Tim %s telah dihapus.\n", namaTim);
}

void jadwalkanPertandingan(addressList head, Queue *matchQueue, addressTree *tournamentTree) {
    printf("\n--- Penjadwalan Pertandingan ---\n");
    printf("Menjadwalkan pertandingan...\n");
    int total_teams = countNode(head);
    if (total_teams < 2 || total_teams > 16) {
        printf("Jumlah tim harus antara 3 dan 16!\n");
        return;
    }

    while (matchQueue->head != NULL) {
        dequeue(matchQueue); // Hapus parameter dummy
    }
    clearTree(tournamentTree);

    addressList temp = head;
    while (temp != NULL) {
        enqueue(matchQueue, temp); // Gunakan seluruh node, bukan hanya namaTim
        temp = temp->next;
    }

    *tournamentTree = buildTournamentTree(matchQueue, total_teams, head);
    printf("Penjadwalan pertandingan selesai.\n");
}