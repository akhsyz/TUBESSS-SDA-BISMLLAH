#include "results.h"

// TAMBAHAN: Fungsi helper untuk menampilkan pertandingan tersedia
static void tampilkanPertandinganTersediaHelper(addressTree root, addressList head) {
    if (root == NULL) return;
    
    // Cek apakah pertandingan ini bisa dimainkan
    if (root->id_tim1 > 0 && root->id_tim2 > 0 && root->id_pemenang == 0) {
        int round = calculateRoundNumber(root, root->match_id, head);
        
        // Tampilkan nama tim, bukan ID
        addressList tim1 = searchNodeById(head, root->id_tim1);
        addressList tim2 = searchNodeById(head, root->id_tim2);
        
        if (tim1 != NULL && tim2 != NULL) {
            printf("   Match %d (Babak %d): %s vs %s\n", 
                   root->match_id, round, tim1->namaTim, tim2->namaTim);
        } else {
            printf("   Match %d (Babak %d): Tim %d vs Tim %d\n", 
                   root->match_id, round, root->id_tim1, root->id_tim2);
        }
    }
    
    // Rekursi untuk child nodes
    tampilkanPertandinganTersediaHelper(root->left, head);
    tampilkanPertandinganTersediaHelper(root->right, head);
}

// PERBAIKAN: Fungsi tampilkanStatistik dengan tampilan yang lebih rapi dan tanpa simbol bermasalah
void tampilkanStatistik(addressList head) {
    if (head == NULL) {
        printf("Daftar tim kosong.\n");
        return;
    }
    
    // Header berwarna cyan tebal
    printf("\033[1;36m");
    printf("\n================================================================================\n");
    printf("||                          == Statistik Tim ==                               ||\n");
    printf("================================================================================\n");
    printf("|| %-4s | %-8s | %-6s | %-8s | %-8s | %-10s               ||\n", 
           "ID", "Nama", "Laga", "Menang", "Kalah", "Win Rate");
    printf("================================================================================\n");
    printf("\033[0m");

    addressList current = head;
    int row = 0;
    int total_teams = 0;
    int total_matches = 0;
    int total_wins = 0;
    int total_losses = 0;
    
    while (current != NULL) {
        total_teams++;
        total_matches += current->laga;
        total_wins += current->kemenangan;
        total_losses += current->kekalahan;
        
        // Baris selang-seling warna
        if (row % 2 == 0)
            printf("\033[1;37m"); // White bold
        else
            printf("\033[0;37m"); // Gray

        char namaPendek[9];
        strncpy(namaPendek, current->namaTim, 8);
        namaPendek[8] = '\0';
        
        // Hitung win rate
        float win_rate = 0.0f;
        if (current->laga > 0) {
            win_rate = ((float)current->kemenangan / (float)current->laga) * 100.0f;
        }
        
        // Format win rate
        char win_rate_str[11];
        if (current->laga > 0) {
            snprintf(win_rate_str, sizeof(win_rate_str), "%.1f%%", win_rate);
        } else {
            strcpy(win_rate_str, "N/A");
        }
        
        printf("|| %-4d | %-8s | %-6d | %-8d | %-8d | %-10s               ||\n",
               current->id_tim, namaPendek, current->laga, current->kemenangan, 
               current->kekalahan, win_rate_str);
        printf("\033[0m");
        current = current->next;
        row++;
    }
    
    // Footer dengan total statistik
    printf("\033[1;36m");
    printf("================================================================================\n");
    printf("|| TOTAL    | %-8d | %-6d | %-8d | %-8d | %-10s               ||\n",
           total_teams, total_matches, total_wins, total_losses, 
           (total_matches > 0) ? "100.0%" : "N/A");
    printf("================================================================================\n");
    printf("\033[0m");
    
    // PERBAIKAN: Informasi tambahan tanpa simbol bermasalah
    printf("\n\033[1;33m"); // Yellow bold
    printf("Ringkasan Turnamen:\n");
    printf("   - Total Tim: %d\n", total_teams);
    printf("   - Total Pertandingan: %d\n", total_matches / 2); // Dibagi 2 karena setiap match dihitung 2x
    printf("   - Pertandingan Selesai: %d\n", total_matches / 2);
    printf("\033[0m");
}

// PERBAIKAN UTAMA: Fungsi tampilkanHistori dengan nama tim yang benar
void tampilkanHistori(Stack *s) {
    if (apakahStackKosong(s)) {
        printf("Riwayat pertandingan kosong.\n");
        return;
    }
    
    printf("\033[1;36m"); // Cyan bold
    printf("\n================================================================================\n");
    printf("||                          == Riwayat Pertandingan ==                        ||\n");
    printf("================================================================================\n");
    printf("|| %-6s | %-8s | %-4s | %-8s | %-4s | %-8s | %-5s         ||\n",
           "Match", "Tim 1", "Skor", "Tim 2", "Skor", "Pemenang", "Ronde");
    printf("================================================================================\n");
    printf("\033[0m"); // Reset

    StackNode *current = s->top;
    int row = 0;
    int total_matches = 0;
    
    while (current != NULL) {
        total_matches++;
        
        // Warna baris: selang-seling
        if (row % 2 == 0)
            printf("\033[1;37m"); // White bold
        else
            printf("\033[0;37m"); // Gray

        printf("|| %-6d | %-8d | %-4d | %-8d | %-4d | %-8d | %-5d         ||\n",
               current->data.matchID,
               current->data.team1Id,
               current->data.skorTim1,
               current->data.team2Id,
               current->data.skorTim2,
               current->data.idPemenang,
               current->data.nomorRonde);
        printf("\033[0m"); // Reset
        current = current->next;
        row++;
    }
    
    printf("\033[1;36m");
    printf("================================================================================\n");
    printf("|| TOTAL PERTANDINGAN SELESAI: %-46d ||\n", total_matches);
    printf("================================================================================\n");
    printf("\033[0m");
}

// TAMBAHAN: Fungsi tampilkanHistori yang menerima parameter head untuk menampilkan nama tim
void tampilkanHistoriDenganNama(Stack *s, addressList head) {
    if (apakahStackKosong(s)) {
        printf("Riwayat pertandingan kosong.\n");
        return;
    }
    
    printf("\033[1;36m"); // Cyan bold
    printf("\n================================================================================\n");
    printf("||                          == Riwayat Pertandingan ==                        ||\n");
    printf("================================================================================\n");
    printf("|| %-6s | %-12s | %-4s | %-12s | %-4s | %-12s | %-5s   ||\n",
           "Match", "Tim 1", "Skor", "Tim 2", "Skor", "Pemenang", "Ronde");
    printf("================================================================================\n");
    printf("\033[0m"); // Reset

    StackNode *current = s->top;
    int row = 0;
    int total_matches = 0;
    
    while (current != NULL) {
        total_matches++;
        
        // Warna baris: selang-seling
        if (row % 2 == 0)
            printf("\033[1;37m"); // White bold
        else
            printf("\033[0;37m"); // Gray

        // Dapatkan nama tim berdasarkan ID
        char tim1_name[13] = "Unknown";
        char tim2_name[13] = "Unknown";
        char winner_name[13] = "Unknown";
        
        addressList tim1 = searchNodeById(head, current->data.team1Id);
        if (tim1 != NULL) {
            strncpy(tim1_name, tim1->namaTim, 12);
            tim1_name[12] = '\0';
        } else {
            snprintf(tim1_name, sizeof(tim1_name), "Tim %d", current->data.team1Id);
        }
        
        addressList tim2 = searchNodeById(head, current->data.team2Id);
        if (tim2 != NULL) {
            strncpy(tim2_name, tim2->namaTim, 12);
            tim2_name[12] = '\0';
        } else {
            snprintf(tim2_name, sizeof(tim2_name), "Tim %d", current->data.team2Id);
        }
        
        addressList winner = searchNodeById(head, current->data.idPemenang);
        if (winner != NULL) {
            strncpy(winner_name, winner->namaTim, 12);
            winner_name[12] = '\0';
        } else {
            snprintf(winner_name, sizeof(winner_name), "Tim %d", current->data.idPemenang);
        }

        printf("|| %-6d | %-12s | %-4d | %-12s | %-4d | %-12s | %-5d   ||\n",
               current->data.matchID,
               tim1_name,
               current->data.skorTim1,
               tim2_name,
               current->data.skorTim2,
               winner_name,
               current->data.nomorRonde);
        printf("\033[0m"); // Reset
        current = current->next;
        row++;
    }
    
    printf("\033[1;36m");
    printf("================================================================================\n");
    printf("|| TOTAL PERTANDINGAN SELESAI: %-46d ||\n", total_matches);
    printf("================================================================================\n");
    printf("\033[0m");
}

void inputMatchResult(addressTree *tournamentTree, addressList head, Stack *matchHistory) {
    printf("\n\033[1;36m");
    printf("===============================================\n");
    printf("           INPUT HASIL PERTANDINGAN           \n");
    printf("===============================================\n");
    printf("\033[0m");
    
    // TAMBAHAN: Tampilkan daftar pertandingan yang tersedia dulu
    printf("\nPertandingan yang dapat dimainkan:\n");
    printf("===============================================\n");
    tampilkanPertandinganTersediaHelper(*tournamentTree, head);
    printf("===============================================\n");
    
    int match_id, skor1, skor2;
    printf("Masukkan ID pertandingan: ");
    if (scanf("%d", &match_id) != 1 || match_id <= 0) {
        printf("ID pertandingan tidak valid.\n");
        while (getchar() != '\n'); // Bersihkan buffer
        return;
    }
    while (getchar() != '\n'); // Bersihkan buffer
    
    addressTree matchNode = findMatchNode(*tournamentTree, match_id);
    if (matchNode == NULL) {
        printf("Pertandingan dengan ID %d tidak ditemukan.\n", match_id);
        return;
    }
    
    // Cek apakah pertandingan sudah selesai
    if (matchNode->id_pemenang != 0) {
        printf("Error: Pertandingan ini sudah selesai!\n");
        addressList winner = searchNodeById(head, matchNode->id_pemenang);
        if (winner != NULL) {
            printf("Pemenang: %s (ID: %d)\n", winner->namaTim, matchNode->id_pemenang);
        }
        return;
    }
    
    // Cek apakah pertandingan bisa dimainkan
    if (matchNode->id_tim1 <= 0 || matchNode->id_tim2 <= 0) {
        printf("Error: Pertandingan ini belum bisa dimainkan.\n");
        printf("Menunggu hasil dari pertandingan sebelumnya.\n");
        return;
    }
    