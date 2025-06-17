/*
PIC : belva 
NIM : 241524035
*/

#include "tournament.h"

void tambahTim(addressList *head) {
    int jmlTim;
    printf("Masukkan jumlah tim: ");
    if (scanf("%d", &jmlTim) != 1 || jmlTim <= 0) {
        printf("Jumlah tim tidak valid.\n");
        while (getchar() != '\n'); 
        return;
    }
    while (getchar() != '\n');
    
    char namaTim[9];
    for (int i = 0; i < jmlTim; i++) {
        printf("Nama Tim %d: ", i + 1);
        if (scanf(" %8[^\n]", namaTim) != 1) {
            printf("Input nama tim tidak valid.\n");
            while (getchar() != '\n'); 
            return;
        }
        
        if (searchNode(*head, namaTim) != NULL) {
            printf("Tim %s sudah terdaftar! Masukkan nama tim yang berbeda.\n", namaTim);
            i--; 
            continue;
        }
        
        addToLinkedList(head, namaTim);
    }
    
    printf("Total %d tim berhasil ditambahkan.\n", jmlTim);
}

void hapusTim(addressList *head) {
    if (*head == NULL) {
        printf("Daftar tim kosong.\n");
        return;
    }
    
    printf("Daftar tim yang terdaftar:\n");
    displayLinkedList(*head);
    
    char namaTim[9];
    printf("Pilih Tim yang ingin dihapus: ");
    if (scanf(" %8[^\n]", namaTim) != 1) {
        printf("Input nama tim tidak valid.\n");
        while (getchar() != '\n'); 
        return;
    }
    
    if (searchNode(*head, namaTim) == NULL) {
        printf("Tim %s tidak ditemukan dalam daftar.\n", namaTim);
        return;
    }
    
    deleteValue(head, namaTim);
    printf("Tim %s telah dihapus.\n", namaTim);
    
    printf("\nDaftar tim setelah penghapusan:\n");
    displayLinkedList(*head);
}

void jadwalkanPertandingan(addressList head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory) {
    printf("\n\033[1;36m");
    printf("==============================================================\n");
    printf("                 PENJADWALAN PERTANDINGAN                    \n");
    printf("==============================================================\n");
    printf("\033[0m");
    
    int total_teams = countNode(head);
    printf("\nTotal tim terdaftar: \033[1;33m%d\033[0m\n", total_teams);
    
    if (total_teams < 3) {
        printf("\n\033[1;31mError: Minimal 3 tim diperlukan untuk membuat turnamen!\033[0m\n");
        printf("Silakan tambahkan tim terlebih dahulu melalui Menu 1.\n");
        return;
    }
    
    if (total_teams > 12) {
        printf("\n\033[1;31mError: Maksimal 12 tim yang dapat berpartisipasi!\033[0m\n");
        printf("Silakan hapus beberapa tim terlebih dahulu melalui Menu 2.\n");
        return;
    }
    
    printf("\n\033[1;32mTim Peserta:\033[0m\n");
    addressList temp = head;
    int count = 1;
    while (temp != NULL) {
        printf("   %d. %s\n", count++, temp->namaTim);
        temp = temp->next;
    }
    
    if (*tournamentTree != NULL) {
        char konfirmasi;
        printf("\n\033[1;33mTurnamen sudah dijadwalkan sebelumnya.\033[0m\n");
        printf("Apakah Anda ingin membuat turnamen baru? (y/n): ");
        scanf(" %c", &konfirmasi);
        while (getchar() != '\n'); 
        
        if (konfirmasi != 'y' && konfirmasi != 'Y') {
            printf("Penjadwalan dibatalkan.\n");
            return;
        }
        
        printf("\033[1;33m\nMereset data turnamen lama...\033[0m\n");
        clearTournamentTree(tournamentTree);
        resetAllTeamStatsSilent(head);
        
        if (matchHistory != NULL) {
            clearStackSilent(matchHistory);
        }
        
        clearQueue(matchQueue);
        
        printf("\033[1;32mData turnamen lama telah dihapus dan direset!\033[0m\n");
    } else {
        resetAllTeamStatsSilent(head);
        if (matchHistory != NULL && !apakahStackKosong(matchHistory)) {
            clearStackSilent(matchHistory);
        }
        clearQueue(matchQueue);
    }
    clearQueue(matchQueue);
    
    temp = head;
    while (temp != NULL) {
        enqueue(matchQueue, temp);
        temp = temp->next;
    }
    
    *tournamentTree = buildTournamentTreeWithMeta(matchQueue, total_teams, head);
    
    if (*tournamentTree == NULL || (*tournamentTree)->root == NULL) {
        printf("\n\033[1;31mGagal membuat struktur turnamen!\033[0m\n");
        printf("Silakan coba lagi atau periksa data tim.\n");
        return;
    }
    
    int rounds = 0;
    int temp_teams = total_teams;
    while (temp_teams > 1) {
        temp_teams = (temp_teams + 1) / 2; 
        rounds++;
    }
    
    setTournamentMetadata(*tournamentTree, total_teams, "Single Elimination");
    (*tournamentTree)->meta.total_rounds = rounds;
    
    printf("\n\033[1;32m");
    printf("==============================================================\n");
    printf("                   PENJADWALAN BERHASIL!                     \n");
    printf("==============================================================\n");
    printf("  Informasi Turnamen:                                        \n");
    printf("     * Total Tim      : %-32d\n", total_teams);
    printf("     * Total Babak    : %-32d\n", rounds);
    printf("     * Sistem         : Single Elimination                   \n");
    printf("==============================================================\n");
    printf("\033[0m");
    
    printf("\n\033[1;35mPertandingan Siap Dimainkan:\033[0m\n");
    printf("==============================================================\n");
    tampilkanPertandinganSiapRapi((*tournamentTree)->root, head, 1);
    printf("==============================================================\n");
    
    printf("\n\033[1;36mMenu yang tersedia sekarang:\033[0m\n");
    printf("   Menu 5: Input Hasil Pertandingan\n");
    printf("   Menu 7: Lihat Bagan Pertandingan\n");
    printf("   Menu 8: Lihat Statistik Tim\n");
    printf("   Menu 9: Lihat Riwayat Pertandingan\n");
}

void tampilkanPertandinganSiapRapi(addressTree root, addressList head, int target_round) {
    if (root == NULL) return;
    
    int current_round = calculateRoundNumber(root, root->match_id, NULL);
    if (current_round == target_round) {
        if (root->id_tim1 > 0 && root->id_tim2 > 0 && root->id_pemenang == 0) {
            addressList tim1 = searchNodeById(head, root->id_tim1);
            addressList tim2 = searchNodeById(head, root->id_tim2);
            
            if (tim1 != NULL && tim2 != NULL) {
                printf("   Match %d: %-15s vs %-15s\n", 
                       root->match_id, tim1->namaTim, tim2->namaTim);
            } else {
                printf("   Match %d: Tim %-11d vs Tim %-11d\n", 
                       root->match_id, root->id_tim1, root->id_tim2);
            }
        } else if (root->id_pemenang != 0) {
            addressList winner = searchNodeById(head, root->id_pemenang);
            if (winner != NULL) {
                printf("   Match %d: %s (Lolos Otomatis)\n", 
                       root->match_id, winner->namaTim);
            } else {
                printf("   Match %d: Tim %d (Lolos Otomatis)\n", 
                       root->match_id, root->id_pemenang);
            }
        } else if (root->id_tim1 == 0 || root->id_tim2 == 0) {
            int winner = (root->id_tim1 != 0) ? root->id_tim1 : root->id_tim2;
            if (winner != 0) {
                addressList tim_winner = searchNodeById(head, winner);
                if (tim_winner != NULL) {
                    printf("   Match %d: %s (BYE - Lolos Otomatis)\n", 
                           root->match_id, tim_winner->namaTim);
                } else {
                    printf("   Match %d: Tim %d (BYE - Lolos Otomatis)\n", 
                           root->match_id, winner);
                }
            }
        } else {
            printf("   Match %d: Menunggu peserta dari babak sebelumnya\n", 
                   root->match_id);
        }
    }
    tampilkanPertandinganSiapRapi(root->left, head, target_round);
    tampilkanPertandinganSiapRapi(root->right, head, target_round);
}

// Fungsi helper untuk menampilkan pertandingan yang siap dimainkan (fungsi lama - untuk backward compatibility)
void tampilkanPertandinganSiap(addressTree root, int target_round) {
    if (root == NULL) return;
    
    int current_round = calculateRoundNumber(root, root->match_id, NULL);
    if (current_round == target_round) {
        if (root->id_tim1 > 0 && root->id_tim2 > 0 && root->id_pemenang == 0) {
            printf("   Match %d: Tim %d vs Tim %d\n", 
                   root->match_id, root->id_tim1, root->id_tim2);
        } else if (root->id_pemenang != 0) {
            printf("   Match %d: SELESAI - Pemenang: Tim %d\n", 
                   root->match_id, root->id_pemenang);
        } else if (root->id_tim1 == 0 || root->id_tim2 == 0) {
            int winner = (root->id_tim1 != 0) ? root->id_tim1 : root->id_tim2;
            if (winner != 0) {
                printf("   Match %d: Tim %d (BYE) - Lolos Otomatis\n", 
                       root->match_id, winner);
            }
        } else {
            printf("   Match %d: Menunggu peserta dari babak sebelumnya\n", 
                   root->match_id);
        }
    }
    tampilkanPertandinganSiap(root->left, target_round);
    tampilkanPertandinganSiap(root->right, target_round);
}

void tampilkanPertandinganTersedia(addressTree root, addressList head) {
    if (root == NULL) return;
    
    if (root->id_tim1 > 0 && root->id_tim2 > 0 && root->id_pemenang == 0) {
        int round = calculateRoundNumber(root, root->match_id, NULL);
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
    tampilkanPertandinganTersedia(root->left, head);
    tampilkanPertandinganTersedia(root->right, head);
}

void cekStatusTurnamen(addressTree root) {
    if (root == NULL) return;
    
    if (root->left == NULL && root->right == NULL) {
        return;
    }
    
    if (root->id_pemenang != 0) {
        printf(" TURNAMEN SELESAI!\n");
        printf("Juara: Tim %d\n", root->id_pemenang);
    } else {
        printf(" Turnamen masih berlangsung...\n");
        printf("Pertandingan yang bisa dimainkan:\n");
        tampilkanPertandinganTersedia(root, NULL);
    }
}

char* getNamaTim(int id_tim, addressList head) {
    static char nama[50];
    addressList temp = searchNodeById(head, id_tim);
    if (temp != NULL) {
        strcpy(nama, temp->namaTim);
        return nama;
    } else {
        strcpy(nama, "Unknown");
        return nama;
    }
}

void tampilkanInfoPertandingan(addressTree match, addressList head) {
    if (match == NULL) {
        printf("Pertandingan tidak valid.\n");
        return;
    }
    
    char* nama1 = getNamaTim(match->id_tim1, head);
    char* nama2 = getNamaTim(match->id_tim2, head);
    
    printf("=== Info Pertandingan %d ===\n", match->match_id);
    printf("Tim 1: %s (ID: %d)\n", nama1, match->id_tim1);
    printf("Tim 2: %s (ID: %d)\n", nama2, match->id_tim2);
    if (match->id_pemenang != 0) {
        char* pemenang = getNamaTim(match->id_pemenang, head);
        printf("Pemenang: %s (ID: %d)\n", pemenang, match->id_pemenang);
    } else {
        printf("Status: Belum selesai\n");
    }
    printf("========================\n");
}

void tampilkanBracket(TournamentTree *tournamentTree, addressList head) {
    if (tournamentTree == NULL || tournamentTree->root == NULL) {
        printf("\n\033[1;31mTurnamen belum dijadwalkan!\033[0m\n");
        printf("Silakan jadwalkan turnamen terlebih dahulu melalui Menu 4.\n");
        return;
    }
    
    int tournament_teams = getTournamentParticipants(tournamentTree);
    int current_teams = countNode(head);
    
    printf("\n\033[1;36m");
    printf("========================================================\n");
    printf("                   BAGAN PERTANDINGAN                  \n");
    printf("                   TURNAMEN %d TIM                      \n", tournament_teams);
    printf("========================================================\n");
    printf("\033[0m");
    
    if (current_teams != tournament_teams) {
        printf("\033[1;33m");
        printf("!!! PERHATIAN: Jumlah tim berubah setelah penjadwalan !!!\n");
        printf("   - Tim saat penjadwalan: %d tim\n", tournament_teams);
        printf("   - Tim terdaftar saat ini: %d tim\n", current_teams);
        printf("   - Untuk menggunakan tim baru, lakukan penjadwalan ulang (Menu 4)\n");
        printf("========================================================\n");
        printf("\033[0m");
    }
    
    Stack tempStack;
    tempStack.top = NULL;
    tempStack.size = 0;
    
    switch(tournament_teams) {
        case 3:
            templatebagan3tim(tournamentTree->root, head, &tempStack);
            break;
        case 4:
            templatebagan4tim(tournamentTree->root, head, &tempStack);
            break;
        case 5:
            templatebagan5tim(tournamentTree->root, head, &tempStack);
            break;
        case 6:
            templatebagan6tim(tournamentTree->root, head, &tempStack);
            break;
        case 7:
            templatebagan7tim(tournamentTree->root, head, &tempStack);
            break;
        case 8:
            templatebagan8tim(tournamentTree->root, head, &tempStack);
            break;
        case 9:
            templatebagan9tim(tournamentTree->root, head, &tempStack);
            break;
        case 10:
            templatebagan10tim(tournamentTree->root, head, &tempStack);
            break;
        case 11:
            templatebagan11tim(tournamentTree->root, head, &tempStack);
            break;
        case 12:
            templatebagan12tim(tournamentTree->root, head, &tempStack);
            break;
        
        default:
            printf("\n\033[1;33m=== TAMPILAN UMUM ===\033[0m\n");
            int rounds = tournamentTree->meta.total_rounds;
            for (int round = 1; round <= rounds; round++) {
                char round_name[20];
                if (rounds == 1) {
                    strcpy(round_name, "FINAL");
                } else if (round == rounds) {
                    strcpy(round_name, "FINAL");
                } else if (round == rounds - 1) {
                    strcpy(round_name, "SEMIFINAL");
                } else if (round == rounds - 2) {
                    strcpy(round_name, "PEREMPAT FINAL");
                } else {
                    sprintf(round_name, "BABAK %d", round);
                }
                
                printf("\n\033[1;34m=== %s ===\033[0m\n", round_name);
                tampilkanPertandinganRound(tournamentTree->root, head, round);
            }
            break;
    }
    
    if (tournamentTree->root->id_pemenang != 0) {
        char juara[20];
        getTeamName(tournamentTree->root->id_pemenang, head, juara);
        printf("\n\033[1;32m");
        printf("========================================================\n");
        printf("                   JUARA TURNAMEN                      \n");
        printf("                      %s                               \n", juara);
        printf("========================================================\n");
        printf("\033[0m");
    }
    
    printf("\n\033[1;36m");
    printf("========================================================\n");
    printf("Keterangan:\n");
    printf("  \033[1;32mMenang\033[0m      - Tim pemenang pertandingan\n");
    printf("  \033[1;34mSIAP\033[0m        - Dapat dimainkan sekarang\n");
    printf("  \033[1;31mMENUNGGU\033[0m    - Menunggu hasil pertandingan sebelumnya\n");
    printf("  BYE           - Tim lolos otomatis\n");
    printf("========================================================\n");
    printf("\033[0m");
}

void tampilkanPertandinganRound(addressTree root, addressList head, int target_round) {
    if (root == NULL) return;
    
    int current_round = calculateRoundNumber(root, root->match_id, NULL);
    
    if (current_round == target_round) {
        char tim1_name[20] = "BYE";
        char tim2_name[20] = "BYE";
        
        if (root->id_tim1 > 0) {
            addressList tim1 = searchNodeById(head, root->id_tim1);
            if (tim1) {
                strncpy(tim1_name, tim1->namaTim, 15);
                tim1_name[15] = '\0';
            }
        } else if (root->id_tim1 == -1) {
            strcpy(tim1_name, "TBD");
        }
        
        if (root->id_tim2 > 0) {
            addressList tim2 = searchNodeById(head, root->id_tim2);
            if (tim2) {
                strncpy(tim2_name, tim2->namaTim, 15);
                tim2_name[15] = '\0';
            }
        } else if (root->id_tim2 == -1) {
            strcpy(tim2_name, "TBD");
        }
        
        printf("   \033[1;37mMatch %d:\033[0m %-15s vs %-15s", 
               root->match_id, tim1_name, tim2_name);
        
        if (root->id_pemenang != 0) {
            addressList pemenang = searchNodeById(head, root->id_pemenang);
            printf("   \033[1;32m[SELESAI - %s]\033[0m", 
                   pemenang ? pemenang->namaTim : "Unknown");
        } else if (root->id_tim1 > 0 && root->id_tim2 > 0) {
            printf("   \033[1;34m[SIAP DIMAINKAN]\033[0m");
        } else {
            printf("   \033[1;31m[MENUNGGU]\033[0m");
        }
        printf("\n");
    }
    
    tampilkanPertandinganRound(root->left, head, target_round);
    tampilkanPertandinganRound(root->right, head, target_round);
}

void tampilkanBracketDetailed(addressTree root, addressList head, int depth) {
    if (root == NULL) return;
    
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    if (root->left == NULL && root->right == NULL) {
        char* nama1 = getNamaTim(root->id_tim1, head);
        char* nama2 = getNamaTim(root->id_tim2, head);
        printf("Match %d: %s vs %s", root->match_id, nama1, nama2);
        if (root->id_pemenang != 0) {
            char* pemenang = getNamaTim(root->id_pemenang, head);
            printf(" (Winner: %s)", pemenang);
        }
        printf("\n");
    } else {
        printf("Round Match %d\n", root->match_id);
        if (root->left) tampilkanBracketDetailed(root->left, head, depth + 1);
        if (root->right) tampilkanBracketDetailed(root->right, head, depth + 1);
    }
}

boolean verifyTournamentReset(addressList head, Stack *matchHistory) {
    if (!apakahStackKosong(matchHistory)) {
        return false;
    }
    
    addressList temp = head;
    while (temp != NULL) {
        if (temp->laga != 0 || temp->kemenangan != 0 || temp->kekalahan != 0) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}