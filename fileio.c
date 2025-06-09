#include "fileio.h"
#include <string.h>
#include <stdbool.h>

void saveTeamsToFile(addressList head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk menulis.\n", filename);
        return;
    }

    if (head == NULL) {
        printf("Daftar tim kosong, tidak ada data untuk disimpan.\n");
        fclose(file);
        return;
    }

    addressList current = head;
    while (current != NULL) {
        char namaTim[50];
        strncpy(namaTim, current->namaTim, 49);
        namaTim[49] = '\0';
        fprintf(file, "[TEAM]\n");
        fprintf(file, "ID: %d\n", current->id_tim);
        fprintf(file, "Nama: %s\n", namaTim);
        fprintf(file, "Laga: %d\n", current->laga);
        fprintf(file, "Kemenangan: %d\n", current->kemenangan);
        fprintf(file, "Kekalahan: %d\n", current->kekalahan);
        fprintf(file, "[END]\n\n");
        current = current->next;
    }

    fclose(file);
    printf("Data tim berhasil disimpan ke %s.\n", filename);
}

addressList loadTeamsFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk membaca.\n", filename);
        return NULL;
    }

    addressList head = NULL;
    char line[256];
    int id_tim = 0, laga = 0, kemenangan = 0, kekalahan = 0;
    char namaTim[50] = "";
    bool validBlock = false;
    bool hasId = false, hasNama = false, hasLaga = false, hasKemenangan = false, hasKekalahan = false;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; 

        if (strcmp(line, "[TEAM]") == 0) {
            validBlock = true;
            hasId = hasNama = hasLaga = hasKemenangan = hasKekalahan = false;
            id_tim = laga = kemenangan = kekalahan = 0;
            namaTim[0] = '\0';
            continue;
        } else if (strcmp(line, "[END]") == 0 && validBlock) {
            if (hasId && hasNama && hasLaga && hasKemenangan && hasKekalahan) {
                addressList newNode = (addressList)malloc(sizeof(node));
                if (newNode == NULL) {
                    printf("Gagal mengalokasi memori untuk node tim.\n");
                    DeAlokasi(&head);
                    fclose(file);
                    return NULL;
                }
                newNode->id_tim = id_tim;
                strncpy(newNode->namaTim, namaTim, 49);
                newNode->namaTim[49] = '\0';
                newNode->laga = laga;
                newNode->kemenangan = kemenangan;
                newNode->kekalahan = kekalahan;
                newNode->next = NULL;
                insertAtLast(&head, newNode);
            } else {
                printf("Blok data tim tidak lengkap, melewati.\n");
            }
            validBlock = false;
            continue;
        }

        if (validBlock) {
            if (strncmp(line, "ID: ", 4) == 0 && sscanf(line + 4, "%d", &id_tim) == 1) {
                hasId = true;
            } else if (strncmp(line, "Nama: ", 6) == 0) {
                strncpy(namaTim, line + 6, 49);
                namaTim[49] = '\0';
                hasNama = true;
            } else if (strncmp(line, "Laga: ", 6) == 0 && sscanf(line + 6, "%d", &laga) == 1) {
                hasLaga = true;
            } else if (strncmp(line, "Kemenangan: ", 12) == 0 && sscanf(line + 12, "%d", &kemenangan) == 1) {
                hasKemenangan = true;
            } else if (strncmp(line, "Kekalahan: ", 11) == 0 && sscanf(line + 11, "%d", &kekalahan) == 1) {
                hasKekalahan = true;
            }
        }
    }

    fclose(file);
    if (head == NULL) {
        printf("Tidak ada data tim yang berhasil dimuat dari %s.\n", filename);
    } else {
        printf("Data tim berhasil dimuat dari %s.\n", filename);
    }
    return head;
}

void saveMatchHistoryToFile(Stack* history, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk menulis.\n", filename);
        return;
    }

    if (apakahStackKosong(history)) {
        printf("Riwayat pertandingan kosong, tidak ada data untuk disimpan.\n");
        fclose(file);
        return;
    }

    Stack tempStack;
    inisialisasiStack(&tempStack);
    MatchResult result;

    while (pop(history, &result)) {
        push(&tempStack, result);
    }

    while (pop(&tempStack, &result)) {
        fprintf(file, "[MATCH]\n");
        fprintf(file, "MatchID: %d\n", result.matchID);
        fprintf(file, "Team1ID: %d\n", result.team1Id);
        fprintf(file, "Team2ID: %d\n", result.team2Id);
        fprintf(file, "PemenangID: %d\n", result.idPemenang);
        fprintf(file, "Ronde: %d\n", result.nomorRonde);
        fprintf(file, "SkorTim1: %d\n", result.skorTim1);
        fprintf(file, "SkorTim2: %d\n", result.skorTim2);
        fprintf(file, "[END]\n\n");
        push(history, result); 
    }

    fclose(file);
    printf("Riwayat pertandingan berhasil disimpan ke %s.\n", filename);
}

Stack* loadMatchHistoryFromFile(const char* filename) {
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
            } else {
                printf("Blok data pertandingan tidak lengkap, melewati.\n");
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
    if (apakahStackKosong(history)) {
        printf("Tidak ada riwayat pertandingan yang berhasil dimuat dari %s.\n", filename);
        free(history);
        return NULL;
    }
    printf("Riwayat pertandingan dimuat dari %s.\n", filename);
    return history;
}

static void saveTreePreorder(FILE* file, addressTree treeNode) {
    if (!treeNode) return;
    fprintf(file, "[NODE]\n");
    fprintf(file, "MatchID: %d\n", treeNode->match_id);
    fprintf(file, "Team1ID: %d\n", treeNode->id_tim1);
    fprintf(file, "Team2ID: %d\n", treeNode->id_tim2);
    fprintf(file, "PemenangID: %d\n", treeNode->id_pemenang);
    fprintf(file, "LeftID: %d\n", treeNode->left ? treeNode->left->match_id : 0);
    fprintf(file, "RightID: %d\n", treeNode->right ? treeNode->right->match_id : 0);
    fprintf(file, "[END]\n");
    saveTreePreorder(file, treeNode->left);
    saveTreePreorder(file, treeNode->right);
}

void saveTournamentTreeToFile(addressTree root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk menulis.\n", filename);
        return;
    }
    if (root == NULL) {
        printf("Pohon turnamen kosong, tidak ada data untuk disimpan.\n");
        fclose(file);
        return;
    }
    saveTreePreorder(file, root);
    fclose(file);
    printf("Pohon turnamen berhasil disimpan ke %s.\n", filename);
}

typedef struct {
    int match_id, id_tim1, id_tim2, id_pemenang, left_id, right_id;
    addressTree node;
} TreeNodeTemp;

addressTree loadTournamentTreeFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk membaca.\n", filename);
        return NULL;
    }
  
    TreeNodeTemp tempNodes[64];
    int count = 0;
    char line[256];
    int match_id=0, id_tim1=0, id_tim2=0, id_pemenang=0, left_id=0, right_id=0;
    bool validBlock = false;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "[NODE]") == 0) {
            validBlock = true;
            match_id = id_tim1 = id_tim2 = id_pemenang = left_id = right_id = 0;
            continue;
        } else if (strcmp(line, "[END]") == 0 && validBlock) {
            if (count < 64) {
                tempNodes[count].match_id = match_id;
                tempNodes[count].id_tim1 = id_tim1;
                tempNodes[count].id_tim2 = id_tim2;
                tempNodes[count].id_pemenang = id_pemenang;
                tempNodes[count].left_id = left_id;
                tempNodes[count].right_id = right_id;
                tempNodes[count].node = createTreeNode(id_tim1, id_tim2, match_id);
                tempNodes[count].node->id_pemenang = id_pemenang;
                count++;
            }
            validBlock = false;
            continue;
        }
        if (validBlock) {
            if (strncmp(line, "MatchID: ", 9) == 0) sscanf(line + 9, "%d", &match_id);
            else if (strncmp(line, "Team1ID: ", 9) == 0) sscanf(line + 9, "%d", &id_tim1);
            else if (strncmp(line, "Team2ID: ", 9) == 0) sscanf(line + 9, "%d", &id_tim2);
            else if (strncmp(line, "PemenangID: ", 12) == 0) sscanf(line + 12, "%d", &id_pemenang);
            else if (strncmp(line, "LeftID: ", 8) == 0) sscanf(line + 8, "%d", &left_id);
            else if (strncmp(line, "RightID: ", 9) == 0) sscanf(line + 9, "%d", &right_id);
        }
    }
    fclose(file);
    
    for (int i = 0; i < count; i++) {
        if (tempNodes[i].left_id != 0) {
            for (int j = 0; j < count; j++) {
                if (tempNodes[j].match_id == tempNodes[i].left_id) {
                    tempNodes[i].node->left = tempNodes[j].node;
                    break;
                }
            }
        }
        if (tempNodes[i].right_id != 0) {
            for (int j = 0; j < count; j++) {
                if (tempNodes[j].match_id == tempNodes[i].right_id) {
                    tempNodes[i].node->right = tempNodes[j].node;
                    break;
                }
            }
        }
    }
    addressTree root = (count > 0) ? tempNodes[0].node : NULL;
    if (root == NULL) {
        printf("Tidak ada pohon turnamen yang berhasil dimuat dari %s.\n", filename);
    } else {
        printf("Pohon turnamen berhasil dimuat dari %s.\n", filename);
    }
    return root;
}
