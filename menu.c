/*
PIC : belva 
NIM : 241524035
*/

#include "menu.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void initialUI(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent) {
    int opsi = 0;
    while (1) {
        clearScreen(); 
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
            printf("Tekan Enter untuk melanjutkan...");
            getchar();
            continue;
        }
        while (getchar() != '\n');
        if (opsi == 1) {
            clearScreen();
            boolean loadSuccess = muatTurnamen(head, matchQueue, tournamentTree, matchHistory, namaEvent);
            if (loadSuccess) {
                break;
            }
        } else if (opsi == 2) {
            clearScreen();
            buatTurnamen(head, matchQueue, tournamentTree, matchHistory, namaEvent);
            break;
        }else if (opsi == 3) {
            clearScreen();
            exit(1);
            break;
        } else {
            printf("Opsi tidak valid!\n");
            printf("Tekan Enter untuk melanjutkan...");
            getchar();
        }
    }
}

boolean muatTurnamen(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent) {
    printf("Masukkan nama event turnamen yang ingin diload: ");
    scanf(" %[^\n]", namaEvent);
    while (getchar() != '\n');
    
    char json_path[300];
    snprintf(json_path, sizeof(json_path), "tournament_data/%s.json", namaEvent);
    
    FILE* testFile = fopen(json_path, "r");
    if (testFile == NULL) {
        printf(" Error: Turnamen '%s' tidak ditemukan!\n", namaEvent);
        printf("File '%s' tidak ada.\n", json_path);
        printf("Pastikan nama turnamen yang Anda masukkan benar.\n");
        printf("Tekan Enter untuk kembali ke menu utama...\n");
        getchar();
        return false;
    }
    fclose(testFile);
    
    printf(" Loading turnamen '%s' dari JSON...\n", namaEvent);
    
    TournamentData* data = loadTournamentFromJSON(json_path);
    if (data == NULL) {
        printf("Gagal memuat data turnamen dari JSON.\n");
        printf("File mungkin corrupt atau format tidak sesuai.\n");
        printf("Tekan Enter untuk kembali ke menu utama...\n");
        getchar();
        return false;
    }
    
    *head = data->head;
    
    if (data->root != NULL) {
        *tournamentTree = (TournamentTree*)malloc(sizeof(TournamentTree));
        if (*tournamentTree != NULL) {
            (*tournamentTree)->root = data->root;
            int loaded_teams = countNode(*head);
            setTournamentMetadata(*tournamentTree, loaded_teams, "Single Elimination");
            int rounds = 0;
            int temp_teams = loaded_teams;
            while (temp_teams > 1) {
                temp_teams = (temp_teams + 1) / 2;
                rounds++;
            }
            (*tournamentTree)->meta.total_rounds = rounds;
        }
    } else {
        *tournamentTree = NULL;
    }
    
    if (data->history != NULL) {
        *matchHistory = *(data->history);
        free(data->history);
    } else {
        inisialisasiStack(matchHistory);
    }
    
    if (strlen(data->tournament_name) > 0) {
        strcpy(namaEvent, data->tournament_name);
    }
    
    free(data);
    
    printf("Selamat datang kembali di %s!\n", namaEvent);
    mainMenu(head, matchQueue, tournamentTree, matchHistory, namaEvent);
    return true;
}

void buatTurnamen(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent) {
    uiGreetings(namaEvent);
    mainMenu(head, matchQueue, tournamentTree, matchHistory, namaEvent);
}

void uiGreetings(char *namaEvent) {
    printf("\033[1m");
    printf("\033[35m");
    printf("=============================================================================================\n");
    printf("=   S E L A M A T   D A T A N G   D I   S I S T E M   M A N A J E M E N   T U R N A M E N   =\n");
    printf("=============================================================================================\n");
    printf("MASUKAN NAMA EVENT TURNAMEN ANDA(Maksimal 8 Karakter): ");
    scanf(" %8[^\n]", namaEvent);
    while (getchar() != '\n');
    printf("\033[95m");
    printf("\n===============================================================\n");
    printf("|                                                             |\n");
    printf("|                    SELAMAT DATANG DI %-8s               |\n", namaEvent);
    printf("|                                                             |\n");
    printf("===============================================================\n");
    printf("TEKAN ENTER UNTUK LANJUT...");
	getchar();
    printf("\033[0m");
}

void mainMenu(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent) {
    int input = 0;
    while (input != 10) {
        clearScreen(); 
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
        while (getchar() != '\n');
        switch (input) {
            case 1:
                clearScreen();
                showsTambahTim(head);
                printf("\nTekan Enter untuk kembali ke menu...");
                getchar();
                break;
            case 2:
                clearScreen();
                showsHapusTim(head);
                printf("\nTekan Enter untuk kembali ke menu...");
                getchar();
                break;
            case 3:
                clearScreen();
                displayLinkedList(*head);
                printf("\nTekan Enter untuk kembali ke menu...");
                getchar();
                break;
            case 4:
                clearScreen();
                jadwalkanPertandingan(*head, matchQueue, tournamentTree, matchHistory);
                printf("\nTekan Enter untuk kembali ke menu...");
                getchar();
                break;
            case 5:
                clearScreen();
                printf("\n=== Input Hasil Pertandingan ===\n");
                if (*tournamentTree == NULL || (*tournamentTree)->root == NULL) {
                    printf(" Jadwalkan pertandingan terlebih dahulu!\n");
                } else {
                    inputMatchResult(&((*tournamentTree)->root), *head, matchHistory);
                }
                printf("\nTekan Enter untuk kembali ke menu...");
                getchar();
                break;
            case 6:
                clearScreen();
                printf("\n=== Undo Hasil Pertandingan ===\n");
                printf("Undo hasil pertandingan terakhir.\n");
                if (apakahStackKosong(matchHistory)) {
                    printf("Tidak ada hasil untuk di-undo!\n");
                } else {
                    if (*tournamentTree != NULL && (*tournamentTree)->root != NULL) {
                        undoMatchResult(&((*tournamentTree)->root), *head, matchHistory);
                        printf("Hasil pertandingan berhasil di-undo.\n");
                    } else {
                        printf("Tidak ada turnamen aktif untuk di-undo!\n");
                    }
                }
                printf("\nTekan Enter untuk kembali ke menu...");
                getchar();
                break;
            case 7:
                clearScreen();
                printf("\n=== Bagan Pertandingan ===\n");
                if (*tournamentTree == NULL || (*tournamentTree)->root == NULL) {
                    printf("Jadwalkan pertandingan terlebih dahulu!\n");
                } else {
                    tampilkanBracket(*tournamentTree, *head);
                }
                printf("\nTekan Enter untuk kembali ke menu...");
                getchar();
                break;
            case 8:
                clearScreen();
                tampilkanStatistik(*head);
                printf("\nTekan Enter untuk kembali ke menu...");
                getchar();
                break;
            case 9:
                clearScreen();
                tampilkanHistori(matchHistory, *head);
                printf("\nTekan Enter untuk kembali ke menu...");
                getchar();
                break;
            case 10:
                clearScreen();
                printf("\n=== Keluar ===\n");
                printf("Menyimpan dan keluar dari program...\n");
                exitProgram(head, matchQueue, tournamentTree, matchHistory, namaEvent);
                return;
            default:
                printf("Opsi tidak valid!\n");
                printf("Tekan Enter untuk melanjutkan...");
                getchar();
        }
        if (*tournamentTree != NULL && (*tournamentTree)->root != NULL && (*tournamentTree)->root->id_pemenang != 0) {
            addressList winner = searchNodeById(*head, (*tournamentTree)->root->id_pemenang);
            if (winner != NULL) {
                printf("\n TURNAMEN SELESAI! \n");
                printf(" JUARA: %s (ID: %d) \n", winner->namaTim, winner->id_tim);
                printf("Selamat kepada pemenang!\n");
                printf("\nTekan Enter untuk melanjutkan...");
                getchar();
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

void exitProgram(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent) {
    if (strlen(namaEvent) == 0) {
        strcpy(namaEvent, "default");
    }
    
    printf("\n");
    printf("\033[1;35m");
    printf("=========================================================================\n");
    printf("                           KELUAR DARI PROGRAM                          \n");
    printf("=========================================================================\n");
    printf("\033[0m");
    
    printf("\033[1;36m");
    printf("  Menyimpan data turnamen '%s'...\n", namaEvent);
    printf("\033[0m");
    
    char json_path[300];
    snprintf(json_path, sizeof(json_path), "tournament_data/%s.json", namaEvent);
    
    createDataFolder();
    
    FILE* test_save = fopen(json_path, "w");
    if (test_save != NULL) {
        fclose(test_save);
        addressTree rootToSave = (*tournamentTree != NULL) ? (*tournamentTree)->root : NULL;
        saveTournamentToJSONQuiet(*head, rootToSave, matchHistory, namaEvent, json_path, false);
        
        printf("\033[1;32m");
        printf("   Data berhasil disimpan!\n");
        printf("\033[0m");
    } else {
        printf("\033[1;31m");
        printf("   Gagal menyimpan data!\n");
        printf("\033[0m");
    }
    
    DeAlokasi(head);
    clearQueue(matchQueue);
    clearTournamentTree(tournamentTree); 
    clearStack(matchHistory);
    
    printf("\033[1;33m");
    printf("  Lokasi file: %s\n", json_path);
    printf("  Format: JSON (Terstruktur & Modern)\n");
    printf("\033[0m");
    
    printf("\n");
    printf("\033[1;35m");
    printf("=========================================================================\n");
    printf("                    TERIMA KASIH TELAH MENGGUNAKAN                      \n");
    printf("                           BRACKET FORGE                                \n");
    printf("=========================================================================\n");
    printf("\033[1;36m");
    printf("                     Sampai jumpa di turnamen berikutnya!               \n");
    printf("\033[0m");
    printf("\n");
}