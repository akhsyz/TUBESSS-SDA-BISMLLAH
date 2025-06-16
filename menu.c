#include "menu.h"

// Fungsi UI awal sebelum uiGreetings
void initialUI(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    int opsi = 0;
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
            boolean loadSuccess = muatTurnamen(head, matchQueue, tournamentTree, matchHistory, namaEvent);
            if (loadSuccess) {
                break;
            }
        } else if (opsi == 2) {
            buatTurnamen(head, matchQueue, tournamentTree, matchHistory, namaEvent);
            break;
        }else if (opsi == 3) {
            exit(1);
            break;
        } else {
            printf("Opsi tidak valid!\n");
        }
    }
}

// PERBAIKAN: Fungsi muatTurnamen dengan JSON dalam folder terpisah
boolean muatTurnamen(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    printf("Masukkan nama event turnamen yang ingin diload: ");
    scanf(" %[^\n]", namaEvent);
    while (getchar() != '\n');
    
    // Format path JSON dalam folder terpisah
    char json_path[300];
    snprintf(json_path, sizeof(json_path), "tournament_data/%s.json", namaEvent);
    
    // Cek apakah file JSON ada
    FILE* testFile = fopen(json_path, "r");
    if (testFile == NULL) {
        printf(" Error: Turnamen '%s' tidak ditemukan!\n", namaEvent);
        printf("File '%s' tidak ada.\n", json_path);
        
        // Coba cari format TXT lama sebagai fallback
        char txt_filename[100];
        snprintf(txt_filename, sizeof(txt_filename), "%s_teams.txt", namaEvent);
        FILE* txtFile = fopen(txt_filename, "r");
        if (txtFile != NULL) {
            fclose(txtFile);
            printf("Ditemukan format TXT lama, melakukan konversi ke JSON...\n");
            return muatTurnamenTXT(head, matchQueue, tournamentTree, matchHistory, namaEvent);
        }
        
        printf("Pastikan nama turnamen yang Anda masukkan benar.\n");
        printf("Tekan Enter untuk kembali ke menu utama...\n");
        getchar();
        return false;
    }
    fclose(testFile);
    
    // Load data dari JSON
    printf(" Loading turnamen '%s' dari JSON...\n", namaEvent);
    
    TournamentData* data = loadTournamentFromJSON(json_path);
    if (data == NULL) {
        printf("Gagal memuat data turnamen dari JSON.\n");
        printf("File mungkin corrupt atau format tidak sesuai.\n");
        printf("Tekan Enter untuk kembali ke menu utama...\n");
        getchar();
        return false;
    }
    
    // Set data yang dimuat
    *head = data->head;
    *tournamentTree = data->root;
    if (data->history != NULL) {
        *matchHistory = *(data->history);
        free(data->history);
    } else {
        inisialisasiStack(matchHistory);
    }
    
    // Update nama event dari JSON jika ada
    if (strlen(data->tournament_name) > 0) {
        strcpy(namaEvent, data->tournament_name);
    }
    
    free(data);
    
    printf(" Turnamen '%s' berhasil dimuat dalam format JSON!\n", namaEvent);
    printf("Selamat datang kembali di %s!\n", namaEvent);
    mainMenu(head, matchQueue, tournamentTree, matchHistory, namaEvent);
    return true;
}

// Fungsi fallback untuk memuat format TXT lama
boolean muatTurnamenTXT(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    char fname[100];
    
    // Load teams dari TXT
    snprintf(fname, sizeof(fname), "%s_teams.txt", namaEvent);
    *head = loadTeamsFromFileTXT(fname);
    if (*head == NULL) {
        printf("Gagal memuat data tim dari format TXT lama.\n");
        return false;
    }
    
    // Load history dari TXT (jika ada)
    snprintf(fname, sizeof(fname), "%s_history.txt", namaEvent);
    FILE* histFile = fopen(fname, "r");
    if (histFile != NULL) {
        fclose(histFile);
        Stack* loadedHistory = loadMatchHistoryFromFileTXT(fname);
        if (loadedHistory != NULL) {
            *matchHistory = *loadedHistory;
            free(loadedHistory);
        } else {
            inisialisasiStack(matchHistory);
        }
    } else {
        inisialisasiStack(matchHistory);
        printf("  File history TXT tidak ditemukan, menggunakan history kosong.\n");
    }
    
    // Load tournament tree dari TXT (jika ada)
    snprintf(fname, sizeof(fname), "%s_tournament.txt", namaEvent);
    *tournamentTree = loadTournamentTreeFromFileTXT(fname);
    if (*tournamentTree == NULL) {
        printf("  File tournament TXT tidak ditemukan, tournament tree kosong.\n");
    }
    
    printf(" Data TXT lama berhasil dimuat!\n");
    printf("Akan dikonversi ke format JSON saat menyimpan.\n");
    printf("Selamat datang kembali di %s!\n", namaEvent);
    mainMenu(head, matchQueue, tournamentTree, matchHistory, namaEvent);
    return true;
}

void buatTurnamen(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
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
    scanf(" %[^\n]", namaEvent);
    while (getchar() != '\n');
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
                printf("\n=== Input Hasil Pertandingan ===\n");
                if (*tournamentTree == NULL) {
                    printf(" Jadwalkan pertandingan terlebih dahulu!\n");
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
                if (*tournamentTree == NULL) {
                    printf("Jadwalkan pertandingan terlebih dahulu!\n");
                } else {
                    tampilkanBracket(*tournamentTree, *head);
                }
                break;
            case 8:
                tampilkanStatistik(*head);
                break;
            case 9:
                tampilkanHistori(matchHistory);
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
                printf("\n TURNAMEN SELESAI! \n");
                printf(" JUARA: %s (ID: %d) \n", winner->namaTim, winner->id_tim);
                printf("Selamat kepada pemenang!\n");
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

// PERBAIKAN: Fungsi exitProgram dengan tampilan yang lebih estetik
void exitProgram(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent) {
    if (strlen(namaEvent) == 0) {
        strcpy(namaEvent, "default");
    }
    
    // Tampilan header exit yang estetik
    printf("\n");
    printf("\033[1;35m");
    printf("=========================================================================\n");
    printf("                           KELUAR DARI PROGRAM                          \n");
    printf("=========================================================================\n");
    printf("\033[0m");
    
    // Tampilan saving progress
    printf("\033[1;36m");
    printf("  Menyimpan data turnamen '%s'...\n", namaEvent);
    printf("\033[0m");
    
    // Simpan dalam format JSON dalam folder terpisah
    char json_path[300];
    snprintf(json_path, sizeof(json_path), "tournament_data/%s.json", namaEvent);
    
    // Pastikan folder ada
    createDataFolder();
    
    // Simpan data (tanpa output verbose)
    FILE* test_save = fopen(json_path, "w");
    if (test_save != NULL) {
        fclose(test_save);
        saveTournamentToJSONQuiet(*head, *tournamentTree, matchHistory, namaEvent, json_path, false);
        
        // Tampilan sukses yang estetik
        printf("\033[1;32m");
        printf("   Data berhasil disimpan!\n");
        printf("\033[0m");
    } else {
        printf("\033[1;31m");
        printf("   Gagal menyimpan data!\n");
        printf("\033[0m");
    }
    
    // Cleanup memory
    DeAlokasi(head);
    clearQueue(matchQueue);
    clearTree(tournamentTree);
    clearStack(matchHistory);
    
    // Tampilan informasi file
    printf("\033[1;33m");
    printf("  Lokasi file: %s\n", json_path);
    printf("  Format: JSON (Terstruktur & Modern)\n");
    printf("\033[0m");
    
    // Tampilan penutup yang estetik
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

// PERBAIKAN: Implementasi lengkap fungsi helper untuk load format TXT lama
Stack* loadMatchHistoryFromFileTXT(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk membaca.\n", filename);
        return NULL;
    }

    Stack* history = malloc(sizeof(Stack));
    if (history == NULL) {
        printf("Gagal mengalokasi memori untuk stack riwayat.\n");
        fclose(file);
        return NULL;
    }
    inisialisasiStack(history);

    char line[256];
    MatchResult result = {0};
    bool validBlock = false;
    bool hasMatchID = false, hasTeam1ID = false, hasTeam2ID = false, hasPemenangID = false;
    bool hasRonde = false, hasSkorTim1 = false, hasSkorTim2 = false;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "[MATCH]") == 0) {
            validBlock = true;
            hasMatchID = hasTeam1ID = hasTeam2ID = hasPemenangID = false;
            hasRonde = hasSkorTim1 = hasSkorTim2 = false;
            memset(&result, 0, sizeof(MatchResult));
            continue;
        } else if (strcmp(line, "[END]") == 0 && validBlock) {
            if (hasMatchID && hasTeam1ID && hasTeam2ID && hasPemenangID && hasRonde && hasSkorTim1 && hasSkorTim2) {
                push(history, result);
            }
            validBlock = false;
            continue;
        }

        if (validBlock) {
            if (strncmp(line, "MatchID: ", 9) == 0 && sscanf(line + 9, "%d", &result.matchID) == 1) {
                hasMatchID = true;
            } else if (strncmp(line, "Team1ID: ", 9) == 0 && sscanf(line + 9, "%d", &result.team1Id) == 1) {
                hasTeam1ID = true;
            } else if (strncmp(line, "Team2ID: ", 9) == 0 && sscanf(line + 9, "%d", &result.team2Id) == 1) {
                hasTeam2ID = true;
            } else if (strncmp(line, "PemenangID: ", 12) == 0 && sscanf(line + 12, "%d", &result.idPemenang) == 1) {
                hasPemenangID = true;
            } else if (strncmp(line, "Ronde: ", 7) == 0 && sscanf(line + 7, "%d", &result.nomorRonde) == 1) {
                hasRonde = true;
            } else if (strncmp(line, "SkorTim1: ", 10) == 0 && sscanf(line + 10, "%d", &result.skorTim1) == 1) {
                hasSkorTim1 = true;
            } else if (strncmp(line, "SkorTim2: ", 10) == 0 && sscanf(line + 10, "%d", &result.skorTim2) == 1) {
                hasSkorTim2 = true;
            }
        }
    }

    fclose(file);
    return history;
}

// PERBAIKAN: Implementasi dasar untuk load tournament tree dari TXT
addressTree loadTournamentTreeFromFileTXT(const char* filename) {
    // Untuk saat ini, return NULL karena format TXT tournament tree kompleks
    // Dalam implementasi nyata, bisa dilakukan parsing dari file TXT
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // File tidak ada, tidak masalah
        return NULL;
    }
    fclose(file);
    
    // Implementasi parsing TXT tournament tree bisa ditambahkan di sini
    // Untuk sekarang, return NULL dan biarkan rebuilding dari match history
    return NULL;
}