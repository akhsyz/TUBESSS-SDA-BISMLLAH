#include "menu.h"

void uiGreetings(char *namaEvent) {
    printf("***********************************************************************************\n");
    printf("*   W E L C O M E   T O   T O R N A M E N T   M A N A G E M E N T   S Y S T E M   *\n");
    printf("***********************************************************************************\n");
    printf("PLEASE ENTER YOUR EVENT NAME: ");
    scanf(" %[^\n]", namaEvent);
    while (getchar() != '\n');
    printf("\n***************************************************************\n");
    printf("*                                                             *\n");
    printf("*                    WELCOME TO %s                        *\n", namaEvent);
    printf("*                                                             *\n");
    printf("***************************************************************\n");
}

void mainMenu(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    int input = 0;
    while (input != 11) {
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
        printf("10. Save Pertandingan\n");
        printf("11. Keluar\n");
        printf("Pilih Opsi: ");
        scanf("%d", &input);
        while (getchar() != '\n'); 
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
                printf("\n--- Input Hasil Pertandingan ---\n");
                printf("Input hasil pertandingan.\n");
                if (*tournamentTree == NULL) {
                    printf("Jadwalkan pertandingan terlebih dahulu!\n");
                } else {
                    inputMatchResult(tournamentTree, *head, matchHistory);
                }
                break;
            case 6:
                printf("\n--- Undo Hasil Pertandingan ---\n");
                printf("Undo hasil pertandingan terakhir.\n");
                if (apakahStackKosong(matchHistory)) {
                    printf("Tidak ada hasil untuk di-undo!\n");
                } else {
                    undoMatchResult(tournamentTree, *head, matchHistory);
                    printf("Hasil pertandingan berhasil di-undo.\n");
                }
                break;
            case 7:
                printf("\n--- Bagan Pertandingan ---\n");
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
                printf("\n--- Statistik Tim ---\n");
                printf("Menampilkan statistik tim.\n");
                tampilkanStatistik(*head);
                break;
            case 9:
                printf("\n--- Riwayat Pertandingan ---\n");
                printf("Menampilkan riwayat pertandingan.\n");
                tampilkanHistori(matchHistory);
                break;
            case 10:
                printf("\n--- Save Pertandingan ---\n");
                printf("Menyimpan detail turnamen ke file...\n");
                saveTeamsToFile(*head, "teams.txt");
                saveMatchHistoryToFile(matchHistory, "history.txt");
                saveTournamentTreeToFile(*tournamentTree, "tournament.txt");
                printf("Turnamen berhasil disimpan.\n");
                break;
            case 11:
                printf("\n--- Keluar ---\n");
                printf("Menyimpan dan keluar dari program...\n");
                exitProgram(head, matchQueue, tournamentTree, matchHistory);
                return;
            default:
                printf("Opsi tidak valid!\n");
        }
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

void exitProgram(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory) {
    saveTeamsToFile(*head, "teams.txt");
    saveMatchHistoryToFile(matchHistory, "history.txt");
    saveTournamentTreeToFile(*tournamentTree, "tournament.txt");
    DeAlokasi(head); 
    while (matchQueue->head != NULL) {
        dequeue(matchQueue);
    }
    clearTree(tournamentTree); 
    clearStack(matchHistory); 
    printf("TERIMAKASIH SUDAH MENGGUNAKAN PROGRAM BAGAN KAMI!!!\n");
}