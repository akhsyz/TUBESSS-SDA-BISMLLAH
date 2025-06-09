#include "menu.h"

// Fungsi UI awal sebelum uiGreetings
void initialUI(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    int opsi = 0;
    char fname[100];
    while (1) {
        printf("\033[96m");
        printf(" ____  ____      _    ____ _  _  _____ _______\n");
        printf("\033[1m");
        printf("\033[94m");
        printf("| __ )|  _ \\    / \\  / ___| |/ /| ____|___  __|\n");
        printf("\033[1m");
        printf("\033[34m");
        printf("|  _ \\| |_) |  / _ \\| |   | ' / |   _|   | |\n");
        printf("\033[1m");
        printf("\033[35m");
        printf("| |_) |  _ <  / ___ \\ |___| . \\ |  |___  | |\n");
        printf("\033[1m");
        printf("\033[95m");
        printf("|____/|_| \\_\\/_/   \\_\\____|_|\\_\\|______| |_|\n");    
        printf("\033[1m");
        printf("\n");
        printf("\033[93m");
        printf("                    F O R G E                     \n");
        printf("\033[1m");
        printf("\n");
        printf("  [1] Muat Turnamen Yang Sudah Ada\n");
        printf("  [2] Buat Turnamen Baru\n");
        printf("  [3] Keluar\n");
        printf("  Pilih opsi: ");
        printf("\033[0m");
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
        }else if (opsi == 3) {
            exit(1);
            break;
        } else {
            printf("Opsi tidak valid!\n");
        }
    }
}

void uiGreetings(char *namaEvent) {
    printf("\033[1m");
    printf("\033[35m");
    printf("=============================================================================================\n");
    printf("=   S E L A M A T   D A T A N G   D I   S I S T E M   M A N A J E M E N   T U R N A M E N   =\n");
    printf("=============================================================================================\n");
    printf("MASUKAN NAMA EVENT TURNAMEN ANDA: ");
    scanf(" %[^\n]", namaEvent);
    while (getchar() != '\n'); // Bersihkan buffer
    printf("\033[95m");
    printf("\n===============================================================\n");
    printf("|                                                             |\n");
    printf("|                    SELAMAT DATANG DI %-8s               |\n", namaEvent);
    printf("|                                                             |\n");
    printf("===============================================================\n");
    printf("\033[0m");
}

void mainMenu(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    int input = 0;
    while (input != 10) {
        printf("\n=== Manajemen Turnamen %s ===\n", namaEvent);
        printf("1. Tambah Tim\n");
        printf("2. Hapus Tim\n");
        printf("3. Tampilkan Daftar Tim\n");
        printf("4. Mulai Penjadwalan Pertandingan\n");
        printf("5. Input Hasil Pertandingan\n");
        printf("6. Undo Hasil Pertandingan\n");
        printf("7. Tampilkan Bagan Pertandingan\n");
        printf("8. Tampilkan Statistik Tim\n");
        printf("9. Tampilkan Riwayat Pertandingan\n");
        printf("10. Keluar\n");
        printf("Pilih Opsi: ");
        scanf("%d", &input);
        while (getchar() != '\n'); // Bersihkan buffer
        switch (input) {
            case 1:
                showsTambahTim(head);
                break;
            case 2:
                showsHapusTim(head);
                break;
            case 3:
                displayLinkedList(*head);
                break;
            case 4:
                jadwalkanPertandingan(*head, matchQueue, tournamentTree);  
                break;
            case 5:
                printf("\n=== Input Hasil Pertandingan ===\n");
                printf("Input hasil pertandingan berikutnya.\n");
                // Perbaikan: cukup cek tournamentTree, tidak perlu cek queue
                if (*tournamentTree == NULL) {
                    printf("Jadwalkan pertandingan terlebih dahulu!\n");
                } else {
                    inputMatchResult(tournamentTree, *head, matchHistory);
                }
                break;
            case 6:
                printf("\n=== Undo Hasil Pertandingan ===\n");
                printf("Undo hasil pertandingan terakhir.\n");
                if (apakahStackKosong(matchHistory)) {
                    printf("Tidak ada hasil untuk di-undo!\n");
                } else {
                    undoMatchResult(tournamentTree, *head, matchHistory);
                    printf("Hasil pertandingan berhasil di-undo.\n");
                }
                break;
            case 7:
                printf("\n=== Bagan Pertandingan ===\n");
                printf("Menampilkan bagan pertandingan.\n");
                if (*tournamentTree == NULL) {
                    printf("Jadwalkan pertandingan terlebih dahulu!\n");
                } else {
                    int numTeams = countNode(*head);
                    switch (numTeams) {
                        case 4: templatebagan4tim(*tournamentTree, *head, matchHistory); break;
                        case 5: templatebagan5tim(*tournamentTree, *head, matchHistory); break;
                        case 6: templatebagan6tim(*tournamentTree, *head, matchHistory); break;
                        case 7: templatebagan7tim(*tournamentTree, *head, matchHistory); break;
                        case 8: templatebagan8tim(*tournamentTree, *head, matchHistory); break;
                        case 9: templatebagan9tim(*tournamentTree, *head, matchHistory); break;
                        case 10: templatebagan10tim(*tournamentTree, *head, matchHistory); break;
                        case 11: templatebagan11tim(*tournamentTree, *head, matchHistory); break;
                        case 12: templatebagan12tim(*tournamentTree, *head, matchHistory); break;
                        case 13: templatebagan13tim(*tournamentTree, *head, matchHistory); break;
                        case 14: templatebagan14tim(*tournamentTree, *head, matchHistory); break;
                        case 15: templatebagan15tim(*tournamentTree, *head, matchHistory); break;
                        case 16: templatebagan16tim(*tournamentTree, *head, matchHistory); break;
                        default: printf("Jumlah tim tidak didukung!\n");
                    }
                }
                break;
            case 8:
                tampilkanStatistik(*head);
                break;
            case 9:
                tampilkanHistori(matchHistory, *head);
                break;
            case 10:
                printf("\n=== Keluar ===\n");
                printf("Menyimpan dan keluar dari program...\n");
                exitProgram(head, matchQueue, tournamentTree, matchHistory, namaEvent);
                return;
            default:
                printf("Opsi tidak valid!\n");
        }
        // Cek kondisi akhir turnamen
        if (*tournamentTree != NULL && (*tournamentTree)->id_pemenang != 0) {
            addressList winner = searchNodeById(*head, (*tournamentTree)->id_pemenang);
            if (winner != NULL) {
                printf("Turnamen selesai! Pemenang: %s\n", winner->namaTim);
            }
        }
    }
}

void showsTambahTim(addressList *head) {
    printf("\n--- Tambah Tim ---\n");
    printf("Tentukan jumlah tim yang akan bertanding.\n");
    tambahTim(head);
}

void showsHapusTim(addressList *head) {
    printf("\n--- Hapus Tim ---\n");
    printf("Masukkan nama tim yang ingin dihapus.\n");
    hapusTim(head); 
}

void exitProgram(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    char fname[100];
    snprintf(fname, sizeof(fname), "%s_teams.txt", namaEvent);
    saveTeamsToFile(*head, fname);
    snprintf(fname, sizeof(fname), "%s_history.txt", namaEvent);
    saveMatchHistoryToFile(matchHistory, fname);
    snprintf(fname, sizeof(fname), "%s_tournament.txt", namaEvent);
    saveTournamentTreeToFile(*tournamentTree, fname);
    DeAlokasi(head); // Dealokasi Linked List
    while (matchQueue->head != NULL) { // Kosongkan Queue
        dequeue(matchQueue);
    }
    clearTree(tournamentTree); // Dealokasi Binary Tree
    clearStack(matchHistory); // Dealokasi Stack
    printf("TERIMAKASIH SUDAH MENGGUNAKAN PROGRAM BAGAN KAMI!!!\n");
}