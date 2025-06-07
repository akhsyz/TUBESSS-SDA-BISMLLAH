#include "menu.h"

// Fungsi UI awal sebelum uiGreetings
void initialUI(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    (void)matchQueue; // Suppress unused parameter warning
    int opsi = 0;
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
            // Load data dari file
            *head = loadTeamsFromFile("teams.txt");
            Stack* loadedHistory = loadMatchHistoryFromFile("history.txt");
            if (loadedHistory != NULL) {
                *matchHistory = *loadedHistory;
                free(loadedHistory);
            }
            *tournamentTree = loadTournamentTreeFromFile("tournament.txt");
            // Minta nama event
            printf("Masukkan nama event turnamen yang ingin diload: ");
            scanf(" %[^\n]", namaEvent);
            while (getchar() != '\n');
            printf("Turnamen berhasil dimuat. Selamat datang kembali di %s!\n", namaEvent);
            break;
        } else if (opsi == 2) {
            // Lanjut ke uiGreetings (akan minta nama event baru)
            uiGreetings(namaEvent);
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

    // Masuk ke menu utama
    mainMenu(&head, &matchQueue, &tournamentTree, &matchHistory, namaEvent);

    return 0;
}