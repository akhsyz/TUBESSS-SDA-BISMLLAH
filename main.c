#include "menu.h"

// Fungsi UI awal sebelum uiGreetings
void initialUI(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    int opsi = 0;
    char fname[100];
    while (1) {
        printf("============================================\n");
        printf("      WELCOME TO THIS APPLICATION\n");
        printf("============================================\n");
        printf("1. Load Tournament\n");
        printf("2. New Tournament\n");
        printf("Pilih opsi: ");
        if (scanf("%d", &opsi) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid!\n");
            continue;
        }
        while (getchar() != '\n');
        if (opsi == 1) {
            printf("Masukkan nama event turnamen yang ingin diload: ");
            scanf(" %[^\n]", namaEvent);
            while (getchar() != '\n');
            // Compose filenames based on event name
            snprintf(fname, sizeof(fname), "%s_teams.txt", namaEvent);
            *head = loadTeamsFromFile(fname);
            snprintf(fname, sizeof(fname), "%s_history.txt", namaEvent);
            Stack* loadedHistory = loadMatchHistoryFromFile(fname);
            if (loadedHistory != NULL) {
                *matchHistory = *loadedHistory;
                free(loadedHistory);
            } else {
                inisialisasiStack(matchHistory);
            }
            snprintf(fname, sizeof(fname), "%s_tournament.txt", namaEvent);
            *tournamentTree = loadTournamentTreeFromFile(fname);
            printf("Turnamen berhasil dimuat. Selamat datang kembali di %s!\n", namaEvent);
            mainMenu(head, matchQueue, tournamentTree, matchHistory, namaEvent);
            break;
        } else if (opsi == 2) {
            uiGreetings(namaEvent);
            mainMenu(head, matchQueue, tournamentTree, matchHistory, namaEvent);
            break;
        } else {
            printf("Opsi tidak valid!\n");
        }
    }
}

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