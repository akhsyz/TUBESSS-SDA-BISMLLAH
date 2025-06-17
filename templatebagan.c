/*
PIC : aufa
NIM : 241524052
*/

#include "templatebagan.h"

void getTeamName(int id_tim, addressList head, char *output) {
    if (id_tim <= 0) {
        strcpy(output, "BYE");
        return;
    }
    
    addressList temp = searchNodeById(head, id_tim);
    if (temp != NULL) {
        strncpy(output, temp->namaTim, 19);
        output[19] = '\0';
    } else {
        sprintf(output, "Tim-%d", id_tim);
    }
}

void getMatchScore(int match_id, Stack *history, int *skor1, int *skor2) {
    *skor1 = 0;
    *skor2 = 0;
    
    if (history == NULL || history->top == NULL) return;
    
    StackNode *temp = history->top;
    while (temp != NULL) {
        if (temp->data.matchID == match_id) {
            *skor1 = temp->data.skorTim1;
            *skor2 = temp->data.skorTim2;
            return;
        }
        temp = temp->next;
    }
}

void displayMatchInfo(addressTree match, addressList head) {
    printf("Match %d: ", match->match_id);
    
    if (match->id_tim1 > 0 && match->id_tim2 > 0) {
        char tim1[20], tim2[20];
        getTeamName(match->id_tim1, head, tim1);
        getTeamName(match->id_tim2, head, tim2);
        printf("%-12s vs %-12s", tim1, tim2);
        
        if (match->id_pemenang != 0) {
            char winner[20];
            getTeamName(match->id_pemenang, head, winner);
            printf(" >> Menang: %s", winner);
        } else {
            printf(" [SIAP DIMAINKAN]");
        }
    } else if (match->id_tim1 > 0) {
        char tim1[20];
        getTeamName(match->id_tim1, head, tim1);
        printf("%-12s vs TBD", tim1);
        printf(" [MENUNGGU]");
    } else if (match->id_tim2 > 0) {
        char tim2[20];
        getTeamName(match->id_tim2, head, tim2);
        printf("TBD vs %-12s", tim2);
        printf(" [MENUNGGU]");
    } else {
        printf("TBD vs TBD [MENUNGGU]");
    }
    printf("\n");
}

void displayLeafMatches(addressTree root, addressList head) {
    if (root == NULL) return;
    
    if (root->left == NULL && root->right == NULL) {
        displayMatchInfo(root, head);
    }
    
    displayLeafMatches(root->left, head);
    displayLeafMatches(root->right, head);
}

void displaySemifinalMatches(addressTree root, addressList head) {
    if (root == NULL) return;
    
    if (root->left != NULL && (root->left->left != NULL || root->left->right != NULL)) {
        displayMatchInfo(root->left, head);
    }
    if (root->right != NULL && (root->right->left != NULL || root->right->right != NULL)) {
        displayMatchInfo(root->right, head);
    }
}

void displayFinalMatch(addressTree root, addressList head) {
    if (root != NULL) {
        displayMatchInfo(root, head);
    }
}

void displayQuarterFinalMatches(addressTree root, addressList head) {
    if (root == NULL) return;
    
    displayQuarterFinalHelper(root, head, 0);
}

void displayQuarterFinalHelper(addressTree root, addressList head, int level) {
    if (root == NULL) return;
    
    if (level == 2) {
        displayMatchInfo(root, head);
        return;
    }
    
    displayQuarterFinalHelper(root->left, head, level + 1);
    displayQuarterFinalHelper(root->right, head, level + 1);
}

void displayMatchesByLevelSpecific(addressTree root, addressList head, int target_level, int current_level) {
    if (root == NULL) return;
    
    if (current_level == target_level) {
        displayMatchInfo(root, head);
        return;
    }
    
    displayMatchesByLevelSpecific(root->left, head, target_level, current_level + 1);
    displayMatchesByLevelSpecific(root->right, head, target_level, current_level + 1);
}

void templatebagan3tim(addressTree root, addressList head, Stack *history) {
    (void)history; 
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== SEMIFINAL ===\n");
    if (root->left != NULL) {
        displayMatchInfo(root->left, head);
    }
    
    if (root->id_tim2 != 0) {
        char tim3[20];
        getTeamName(root->id_tim2, head, tim3);
        printf("%-12s: BYE (Langsung ke Final)\n", tim3);
    }
    
    printf("\n=== FINAL ===\n");
    displayFinalMatch(root, head);
    printf("\n");
}

void templatebagan4tim(addressTree root, addressList head, Stack *history) {
    (void)history; 
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== SEMIFINAL ===\n");
    
    if (root->left != NULL) {
        displayMatchInfo(root->left, head);
    }
    
    if (root->right != NULL) {
        displayMatchInfo(root->right, head);
    }
    
    printf("\n=== FINAL ===\n");
    displayFinalMatch(root, head);
    printf("\n");
}

void templatebagan5tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== BABAK PERTAMA ===\n");
    displayLeafMatches(root, head);
    
    printf("\n=== SEMIFINAL ===\n");
    displaySemifinalMatches(root, head);
    
    printf("\n=== FINAL ===\n");
    displayFinalMatch(root, head);
    printf("\n");
}

void templatebagan6tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== BABAK PERTAMA ===\n");
    displayLeafMatches(root, head);
    
    printf("\n=== SEMIFINAL ===\n");
    displaySemifinalMatches(root, head);
    
    printf("\n=== FINAL ===\n");
    displayFinalMatch(root, head);
    printf("\n");
}

void templatebagan7tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== BABAK PERTAMA ===\n");
    displayLeafMatches(root, head);
    
    printf("\nTim dengan BYE ke Semifinal:\n");
    if (root->right != NULL && root->right->id_tim2 > 0) {
        char tim_bye[20];
        getTeamName(root->right->id_tim2, head, tim_bye);
        printf("   %s (Langsung ke Semifinal)\n", tim_bye);
    }
    
    printf("\n=== SEMIFINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 1, 0);
    
    printf("\n=== FINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 0, 0);
    printf("\n");
}

void templatebagan8tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== PEREMPAT FINAL ===\n");
    displayLeafMatches(root, head); 
    
    printf("\n=== SEMIFINAL ===\n");
    displaySemifinalMatches(root, head);
    
    printf("\n=== FINAL ===\n");
    displayFinalMatch(root, head);
    printf("\n");
}

void templatebagan9tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== BABAK PERTAMA ===\n");
    displayMatchesByLevelSpecific(root, head, 3, 0);
    
    printf("\n=== PEREMPAT FINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 2, 0);
    
    printf("\n=== SEMIFINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 1, 0);
    
    printf("\n=== FINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 0, 0);
    printf("\n");
}

void templatebagan10tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== BABAK PERTAMA ===\n");
    displayMatchesByLevelSpecific(root, head, 3, 0);
    
    printf("\n=== PEREMPAT FINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 2, 0);
    
    printf("\n=== SEMIFINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 1, 0);
    
    printf("\n=== FINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 0, 0);
    printf("\n");
}

void templatebagan11tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== BABAK PERTAMA ===\n");
    displayLeafMatches(root, head);
    
    printf("\n=== PEREMPAT FINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 2, 0);
    
    printf("\n=== SEMIFINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 1, 0);
    
    printf("\n=== FINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 0, 0);
    printf("\n");
}

void templatebagan12tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    
    printf("\n");
    printf("=== BABAK PERTAMA ===\n");
    displayMatchesByLevelSpecific(root, head, 3, 0);
    
    printf("\n=== PEREMPAT FINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 2, 0);
    
    printf("\n=== SEMIFINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 1, 0);
    
    printf("\n=== FINAL ===\n");
    displayMatchesByLevelSpecific(root, head, 0, 0);
    printf("\n");
}

void displayMatchesByRound(addressTree root, addressList head, int target_round) {
    if (root == NULL) return;
    
    int current_round = calculateRoundNumber(root, root->match_id, NULL);
    
    if (current_round == target_round) {
        printf("Match %d: ", root->match_id);
        
        if (root->id_tim1 > 0 && root->id_tim2 > 0) {
            char tim1[20], tim2[20];
            getTeamName(root->id_tim1, head, tim1);
            getTeamName(root->id_tim2, head, tim2);
            printf("%-12s vs %-12s", tim1, tim2);
            
            if (root->id_pemenang != 0) {
                char winner[20];
                getTeamName(root->id_pemenang, head, winner);
                printf(" >> Menang: %s", winner);
            } else {
                printf(" [SIAP DIMAINKAN]");
            }
        } else if (root->id_pemenang != 0) {
            char winner[20];
            getTeamName(root->id_pemenang, head, winner);
            printf("%-12s (BYE)", winner);
        } else {
            printf("Menunggu hasil pertandingan sebelumnya");
        }
        printf("\n");
    }
    
    displayMatchesByRound(root->left, head, target_round);
    displayMatchesByRound(root->right, head, target_round);
}

void displayTreeStructure(addressTree root, addressList head, Stack *history, int depth) {
    if (root == NULL) return;
    
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    printf("Match %d: ", root->match_id);
    
    if (root->id_tim1 > 0 && root->id_tim2 > 0) {
        char tim1[20], tim2[20];
        getTeamName(root->id_tim1, head, tim1);
        getTeamName(root->id_tim2, head, tim2);
        printf("%s vs %s", tim1, tim2);
        
        if (root->id_pemenang != 0) {
            char winner[20];
            getTeamName(root->id_pemenang, head, winner);
            printf(" [Winner: %s]", winner);
        }
    } else if (root->id_pemenang != 0) {
        char winner[20];
        getTeamName(root->id_pemenang, head, winner);
        printf("%s (Advance)", winner);
    } else {
        printf("TBD");
    }
    
    printf("\n");
    
    if (root->left || root->right) {
        displayTreeStructure(root->left, head, history, depth + 1);
        displayTreeStructure(root->right, head, history, depth + 1);
    }
}
