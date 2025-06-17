#include "results.h"

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
    
    printf("\n\033[1;33m"); // Yellow bold
    printf("Ringkasan Turnamen:\n");
    printf("   - Total Tim: %d\n", total_teams);
    printf("   - Total Pertandingan: %d\n", total_matches / 2); // Dibagi 2 karena setiap match dihitung 2x
    printf("   - Pertandingan Selesai: %d\n", total_matches / 2);
    printf("\033[0m");
}

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
    
    addressList tim1 = searchNodeById(head, matchNode->id_tim1);
    addressList tim2 = searchNodeById(head, matchNode->id_tim2);
    
    if (tim1 == NULL || tim2 == NULL) {
        printf("Error: Data tim tidak ditemukan!\n");
        return;
    }
    
    printf("\nDetail Pertandingan %d:\n", match_id);
    printf("===============================================\n");
    printf("Tim 1: %s (ID: %d)\n", tim1->namaTim, tim1->id_tim);
    printf("Tim 2: %s (ID: %d)\n", tim2->namaTim, tim2->id_tim);
    printf("===============================================\n");
    
    char namaPemenang[50];
    printf("\nMasukkan nama tim pemenang: ");
    if (scanf(" %49[^\n]", namaPemenang) != 1) {
        printf("Input nama pemenang tidak valid.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');
    
    int id_pemenang = 0;
    if (strcmp(namaPemenang, tim1->namaTim) == 0) {
        id_pemenang = tim1->id_tim;
    } else if (strcmp(namaPemenang, tim2->namaTim) == 0) {
        id_pemenang = tim2->id_tim;
    } else {
        printf("Error: Nama tim pemenang tidak valid!\n");
        printf("Pilihan yang tersedia: '%s' atau '%s'\n", tim1->namaTim, tim2->namaTim);
        return;
    }
    
    // Input skor dengan validasi berulang sampai konsisten
    int input_valid = 0;
    while (!input_valid) {
        printf("Masukkan skor untuk %s: ", tim1->namaTim);
        if (scanf("%d", &skor1) != 1) {
            printf("Skor tidak valid.\n");
            while (getchar() != '\n');
            continue;
        }
        
        printf("Masukkan skor untuk %s: ", tim2->namaTim);
        if (scanf("%d", &skor2) != 1) {
            printf("Skor tidak valid.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        
        if (skor1 < 0 || skor2 < 0) {
            printf("Error: Skor tidak boleh negatif!\n");
            printf("Silakan input ulang skor yang valid.\n\n");
            continue;
        }
        
        if (id_pemenang == tim1->id_tim && skor1 <= skor2) {
            printf("Error: Skor tidak konsisten dengan pemenang!\n");
            printf("Tim pemenang: %s, tetapi skor %s (%d) <= skor %s (%d)\n", 
                   tim1->namaTim, tim1->namaTim, skor1, tim2->namaTim, skor2);
            printf("Pemenang harus memiliki skor lebih tinggi dari lawan.\n");
            
            char pilihan;
            printf("\nPilihan:\n");
            printf("1. Input ulang skor (r)\n");
            printf("2. Ganti pemenang (c)\n");
            printf("3. Batalkan input (b)\n");
            printf("Pilih (r/c/b): ");
            scanf(" %c", &pilihan);
            while (getchar() != '\n');
            
            if (pilihan == 'c' || pilihan == 'C') {
                printf("Mengganti pemenang menjadi %s\n", tim2->namaTim);
                id_pemenang = tim2->id_tim;
                input_valid = 1;
            } else if (pilihan == 'b' || pilihan == 'B') {
                printf("Input hasil pertandingan dibatalkan.\n");
                return;
            } else {
                printf("Input ulang skor...\n\n");
                // Loop akan berlanjut untuk input ulang
            }
        } else if (id_pemenang == tim2->id_tim && skor2 <= skor1) {
            printf("Error: Skor tidak konsisten dengan pemenang!\n");
            printf("Tim pemenang: %s, tetapi skor %s (%d) <= skor %s (%d)\n", 
                   tim2->namaTim, tim2->namaTim, skor2, tim1->namaTim, skor1);
            printf("Pemenang harus memiliki skor lebih tinggi dari lawan.\n");
            
            char pilihan;
            printf("\nPilihan:\n");
            printf("1. Input ulang skor (r)\n");
            printf("2. Ganti pemenang (c)\n");
            printf("3. Batalkan input (b)\n");
            printf("Pilih (r/c/b): ");
            scanf(" %c", &pilihan);
            while (getchar() != '\n');
            
            if (pilihan == 'c' || pilihan == 'C') {
                printf("Mengganti pemenang menjadi %s\n", tim1->namaTim);
                id_pemenang = tim1->id_tim;
                input_valid = 1;
            } else if (pilihan == 'b' || pilihan == 'B') {
                printf("Input hasil pertandingan dibatalkan.\n");
                return;
            } else {
                printf("Input ulang skor...\n\n");
                // Loop akan berlanjut untuk input ulang
            }
        } else if (skor1 == skor2) {
            printf("Error: Skor tidak boleh seri/sama!\n");
            printf("Dalam sistem eliminasi, harus ada pemenang yang jelas.\n");
            printf("Silakan input skor yang berbeda.\n\n");
            // Loop akan berlanjut untuk input ulang
        } else {
            // Skor valid dan konsisten
            input_valid = 1;
        }
    }
    
    // Update hasil pertandingan
    updateMatchResult(*tournamentTree, match_id, id_pemenang, skor1, skor2, head, matchHistory);
    
    printf("\n\033[1;32m");
    printf("===============================================\n");
    printf("        HASIL PERTANDINGAN BERHASIL DISIMPAN! \n");
    printf("===============================================\n");
    printf("\033[0m");
    addressList pemenang = searchNodeById(head, id_pemenang);
    printf("Pemenang: %s (ID: %d)\n", pemenang->namaTim, id_pemenang);
    printf("Skor: %s %d - %d %s\n", tim1->namaTim, skor1, skor2, tim2->namaTim);
    printf("Hasil pertandingan telah diperbarui.\n");
    printf("===============================================\n");
}

void undoMatchResult(addressTree *tournamentTree, addressList head, Stack *matchHistory) {
    MatchResult result;
    if (!pop(matchHistory, &result)) {
        printf("Tidak ada pertandingan untuk diundo.\n");
        return;
    }

    addressTree match = findMatchNode(*tournamentTree, result.matchID);
    if (match == NULL) {
        printf("Pertandingan dengan ID %d tidak ditemukan untuk diundo.\n", result.matchID);
        return;
    }

    // Reset pemenang pertandingan
    match->id_pemenang = 0;

    addressList tim1 = searchNodeById(head, result.team1Id);
    addressList tim2 = searchNodeById(head, result.team2Id);
    
    if (tim1 != NULL && result.team1Id != 0) {
        // Jika tim1 menang, kurangi kemenangan dan laga
        // Jika tim1 kalah, kurangi kekalahan dan laga
        if (result.idPemenang == result.team1Id) {
            tim1->kemenangan = (tim1->kemenangan > 0) ? tim1->kemenangan - 1 : 0;
        } else {
            tim1->kekalahan = (tim1->kekalahan > 0) ? tim1->kekalahan - 1 : 0;
        }
        tim1->laga = (tim1->laga > 0) ? tim1->laga - 1 : 0;
    }
    
    if (tim2 != NULL && result.team2Id != 0) {
        // Jika tim2 menang, kurangi kemenangan dan laga
        // Jika tim2 kalah, kurangi kekalahan dan laga
        if (result.idPemenang == result.team2Id) {
            tim2->kemenangan = (tim2->kemenangan > 0) ? tim2->kemenangan - 1 : 0;
        } else {
            tim2->kekalahan = (tim2->kekalahan > 0) ? tim2->kekalahan - 1 : 0;
        }
        tim2->laga = (tim2->laga > 0) ? tim2->laga - 1 : 0;
    }

    addressTree parent = findParentNode(*tournamentTree, match);
    if (parent != NULL) {
        if (parent->left == match) {
            parent->id_tim1 = 0; // Reset peserta di parent
        } else if (parent->right == match) {
            parent->id_tim2 = 0; // Reset peserta di parent
        }
        
        // Jika parent juga sudah ada pemenang, reset juga
        if (parent->id_pemenang != 0) {
            parent->id_pemenang = 0;
            printf("Pertandingan selanjutnya juga direset karena peserta berubah.\n");
        }
    }

    printf("Pertandingan dengan ID %d telah berhasil diundo.\n", result.matchID);
    
    // Tampilkan info tim yang terpengaruh
    if (tim1 != NULL) {
        printf("Statistik %s diperbarui: %d menang, %d kalah, %d laga\n", 
               tim1->namaTim, tim1->kemenangan, tim1->kekalahan, tim1->laga);
    }
    if (tim2 != NULL) {
        printf("Statistik %s diperbarui: %d menang, %d kalah, %d laga\n", 
               tim2->namaTim, tim2->kemenangan, tim2->kekalahan, tim2->laga);
    }
}

void updateMatchResult(addressTree root, int match_id, int id_pemenang, int skor1, int skor2, addressList head, Stack *history) {
    addressTree match_node = findMatchNode(root, match_id);
    if (match_node == NULL) {
        printf("Pertandingan dengan ID %d tidak ditemukan.\n", match_id);
        return;
    }
    
    // Update pemenang
    match_node->id_pemenang = id_pemenang;

    // Update statistik tim dengan benar
    addressList tim1 = searchNodeById(head, match_node->id_tim1);
    addressList tim2 = searchNodeById(head, match_node->id_tim2);
    
    if (tim1 != NULL && match_node->id_tim1 != 0) {
        // Tim 1: menang jika id_pemenang == id_tim1, kalah sebaliknya
        int menang = (id_pemenang == match_node->id_tim1) ? 1 : 0;
        int kalah = (id_pemenang == match_node->id_tim1) ? 0 : 1;
        updateTeamStats(head, tim1->namaTim, menang, kalah);
    }
    
    if (tim2 != NULL && match_node->id_tim2 != 0) {
        // Tim 2: menang jika id_pemenang == id_tim2, kalah sebaliknya  
        int menang = (id_pemenang == match_node->id_tim2) ? 1 : 0;
        int kalah = (id_pemenang == match_node->id_tim2) ? 0 : 1;
        updateTeamStats(head, tim2->namaTim, menang, kalah);
    }

    // Update parent node
    addressTree parent = findParentNode(root, match_node);
    if (parent != NULL && id_pemenang != 0) {
        if (parent->left == match_node) {
            parent->id_tim1 = id_pemenang;
        } else if (parent->right == match_node) {
            parent->id_tim2 = id_pemenang;
        }
    }

    // Simpan ke history
    MatchResult result = {
        match_id,
        match_node->id_tim1,
        match_node->id_tim2,
        id_pemenang,
        calculateRoundNumber(root, match_id, head),
        skor1,
        skor2
    };
    push(history, result);
    
    printf("Statistik tim berhasil diperbarui.\n");
}