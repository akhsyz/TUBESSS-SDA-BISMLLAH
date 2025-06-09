#include "templatebagan.h"

static void getTeamName(int id_tim, addressList head, char *output) {
    addressList team = searchNodeById(head, id_tim);
    if (team == NULL || id_tim == 0) {
        strncpy(output, "BYE", 8);
        output[8] = '\0';
    } else {
        strncpy(output, team->namaTim, 8);
        output[8] = '\0';
    }
}

static void getMatchScore(int match_id, Stack *history, int *skor1, int *skor2) {
    *skor1 = 0;
    *skor2 = 0;
    StackNode *current = history->top;
    while (current != NULL) {
        if (current->data.matchID == match_id) {
            *skor1 = current->data.skorTim1;
            *skor2 = current->data.skorTim2;
            break;
        }
        current = current->next;
    }
}

void templatebagan4tim(addressTree root, addressList head, Stack *history) {
    if (root == NULL || root->left == NULL || root->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char name1[9], name2[9], name3[9], name4[9], winner[9];
    int skor1, skor2, skor3, skor4, skor5, skor6;
    getTeamName(root->left->id_tim1, head, name1);
    getTeamName(root->left->id_tim2, head, name2);
    getTeamName(root->right->id_tim1, head, name3);
    getTeamName(root->right->id_tim2, head, name4);
    getTeamName(root->id_pemenang, head, winner);
    getMatchScore(root->left->match_id, history, &skor1, &skor2);
    getMatchScore(root->right->match_id, history, &skor3, &skor4);
    getMatchScore(root->match_id, history, &skor5, &skor6);

    printf("\033[1;33m\n"); // Yellow bold
    printf("%-8s : %d\n", name1, skor1);
    printf("        |--> %-8s : %d\n", name1, skor5);
    printf("%-8s : %d\n", name2, skor2);
    printf("                    |--> %-8s\n", winner);
    printf("%-8s : %d\n", name3, skor3);
    printf("        |--> %-8s : %d\n", name4, skor6);
    printf("%-8s : %d\n", name4, skor4);
    printf("Winner : %-8s\n\n", winner);
    printf("\033[0m");
}

void templatebagan5tim(addressTree root, addressList head, Stack *history) {
    if (root == NULL || root->left == NULL || root->right == NULL || root->left->left == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char name1[9], name2[9], name3[9], name4[9], name5[9], winner[9];
    int skor1, skor2, skor3, skor4, skor5, skor6, skor7, skor8;
    getTeamName(root->left->left->id_tim1, head, name1);
    getTeamName(root->left->left->id_tim2, head, name2);
    getTeamName(root->left->id_tim2, head, name3);
    getTeamName(root->right->id_tim1, head, name4);
    getTeamName(root->right->id_tim2, head, name5);
    getTeamName(root->id_pemenang, head, winner);
    getMatchScore(root->left->left->match_id, history, &skor1, &skor2);
    getMatchScore(root->left->match_id, history, &skor3, &skor4);
    getMatchScore(root->right->match_id, history, &skor5, &skor6);
    getMatchScore(root->match_id, history, &skor7, &skor8);

    printf("\n");
    printf("%-8s : %d\n", name1, skor1);
    printf("        |--> %-8s : %d\n", name1, skor3);
    printf("%-8s : %d\n", name2, skor2);
    printf("                    |--> %-8s : %d\n", winner, skor7);
    printf("%-8s : %d\n", name3, skor4);
    printf("%-8s : %d\n", name4, skor5);
    printf("        |--> %-8s : %d\n", name4, skor6);
    printf("%-8s : %d\n", name5, skor6);
    printf("Winner : %-8s\n\n", winner);
}

void templatebagan6tim(addressTree root, addressList head, Stack *history) {
    if (root == NULL || root->left == NULL || root->right == NULL || root->left->left == NULL || root->right->left == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char name1[9], name2[9], name3[9], name4[9], name5[9], name6[9], winner[9];
    int skor1, skor2, skor3, skor4, skor5, skor6, skor7, skor8, skor9, skor10;
    getTeamName(root->left->left->id_tim1, head, name1);
    getTeamName(root->left->left->id_tim2, head, name2);
    getTeamName(root->left->id_tim2, head, name5);
    getTeamName(root->right->left->id_tim1, head, name3);
    getTeamName(root->right->left->id_tim2, head, name4);
    getTeamName(root->right->id_tim2, head, name6);
    getTeamName(root->id_pemenang, head, winner);
    getMatchScore(root->left->left->match_id, history, &skor1, &skor2);
    getMatchScore(root->left->match_id, history, &skor5, &skor6);
    getMatchScore(root->right->left->match_id, history, &skor3, &skor4);
    getMatchScore(root->right->match_id, history, &skor7, &skor8);
    getMatchScore(root->match_id, history, &skor9, &skor10);

    printf("\n");
    printf("%-8s : %d\n", name1, skor1);
    printf("        |--> %-8s : %d\n", name1, skor5);
    printf("%-8s : %d\n", name2, skor2);
    printf("                    |--> %-8s : %d\n", winner, skor9);
    printf("%-8s : %d\n", name5, skor6);
    printf("%-8s : %d\n", name3, skor3);
    printf("        |--> %-8s : %d\n", name4, skor7);
    printf("%-8s : %d\n", name4, skor4);
    printf("                    |--> %-8s : %d\n", name6, skor8);
    printf("%-8s : %d\n", name6, skor8);
    printf("Winner : %-8s\n\n", winner);
}

void templatebagan7tim(addressTree root, addressList head, Stack *history) {
    if (root == NULL || root->left == NULL || root->right == NULL || root->left->left == NULL || root->right->left == NULL || root->right->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char name1[9], name2[9], name3[9], name4[9], name5[9], name6[9], name7[9], winner[9];
    int skor1, skor2, skor3, skor4, skor5, skor6, skor7, skor8, skor9, skor10;
    getTeamName(root->left->left->id_tim1, head, name1);
    getTeamName(root->left->left->id_tim2, head, name2);
    getTeamName(root->left->id_tim2, head, name7);
    getTeamName(root->right->left->id_tim1, head, name3);
    getTeamName(root->right->left->id_tim2, head, name4);
    getTeamName(root->right->right->id_tim1, head, name5);
    getTeamName(root->right->right->id_tim2, head, name6);
    getTeamName(root->id_pemenang, head, winner);
    getMatchScore(root->left->left->match_id, history, &skor1, &skor2);
    getMatchScore(root->left->match_id, history, &skor7, &skor8);
    getMatchScore(root->right->left->match_id, history, &skor3, &skor4);
    getMatchScore(root->right->right->match_id, history, &skor5, &skor6);
    getMatchScore(root->match_id, history, &skor9, &skor10);

    printf("\n");
    printf("%-8s : %d\n", name1, skor1);
    printf("        |--> %-8s : %d\n", name1, skor7);
    printf("%-8s : %d\n", name2, skor2);
    printf("                    |--> %-8s : %d\n", winner, skor9);
    printf("%-8s : %d\n", name7, skor8);
    printf("%-8s : %d\n", name3, skor3);
    printf("        |--> %-8s : %d\n", name4, skor9);
    printf("%-8s : %d\n", name4, skor4);
    printf("%-8s : %d\n", name5, skor5);
    printf("        |--> %-8s : %d\n", name6, skor10);
    printf("%-8s : %d\n", name6, skor6);
    printf("Winner : %-8s\n\n", winner);
}

void templatebagan8tim(addressTree root, addressList head, Stack *history) {
    if (root == NULL || root->left == NULL || root->right == NULL || root->left->left == NULL || root->left->right == NULL || root->right->left == NULL || root->right->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char name1[9], name2[9], name3[9], name4[9], name5[9], name6[9], name7[9], name8[9], winner[9];
    int skor1, skor2, skor3, skor4, skor5, skor6, skor7, skor8, skor9, skor10, skor11, skor12, skor13, skor14;
    getTeamName(root->left->left->id_tim1, head, name1);
    getTeamName(root->left->left->id_tim2, head, name2);
    getTeamName(root->left->right->id_tim1, head, name3);
    getTeamName(root->left->right->id_tim2, head, name4);
    getTeamName(root->right->left->id_tim1, head, name5);
    getTeamName(root->right->left->id_tim2, head, name6);
    getTeamName(root->right->right->id_tim1, head, name7);
    getTeamName(root->right->right->id_tim2, head, name8);
    getTeamName(root->id_pemenang, head, winner);
    getMatchScore(root->left->left->match_id, history, &skor1, &skor2);
    getMatchScore(root->left->right->match_id, history, &skor3, &skor4);
    getMatchScore(root->right->left->match_id, history, &skor5, &skor6);
    getMatchScore(root->right->right->match_id, history, &skor7, &skor8);
    getMatchScore(root->left->match_id, history, &skor9, &skor10);
    getMatchScore(root->right->match_id, history, &skor11, &skor12);
    getMatchScore(root->match_id, history, &skor13, &skor14);

    printf("\n");
    printf("%-8s : %d\n", name1, skor1);
    printf("        |--> %-8s : %d\n", name1, skor9);
    printf("%-8s : %d\n", name2, skor2);
    printf("                    |--> %-8s : %d\n", winner, skor13);
    printf("%-8s : %d\n", name3, skor3);
    printf("        |--> %-8s : %d\n", name3, skor10);
    printf("%-8s : %d\n", name4, skor4);
    printf("%-8s : %d\n", name5, skor5);
    printf("        |--> %-8s : %d\n", name5, skor11);
    printf("%-8s : %d\n", name6, skor6);
    printf("                    |--> %-8s : %d\n", name5, skor12);
    printf("%-8s : %d\n", name7, skor7);
    printf("        |--> %-8s : %d\n", name8, skor8);
    printf("%-8s : %d\n", name8, skor8);
    printf("Winner : %-8s\n\n", winner);
}

void templatebagan9tim(addressTree root, addressList head, Stack *history) {
    if (root == NULL || root->left == NULL || root->right == NULL || root->left->left == NULL || root->left->right == NULL || root->right->left == NULL || root->right->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char name1[9], name2[9], name3[9], name4[9], name5[9], name6[9], name7[9], name8[9], name9[9], winner[9];
    int skor1, skor2, skor3, skor4, skor5, skor6, skor7, skor8, skor9, skor10, skor11, skor12, skor13, skor14, skor15, skor16;
    getTeamName(root->left->left->left->id_tim1, head, name1);
    getTeamName(root->left->left->left->id_tim2, head, name2);
    getTeamName(root->left->left->id_tim2, head, name3);
    getTeamName(root->left->right->id_tim1, head, name4);
    getTeamName(root->left->right->id_tim2, head, name5);
    getTeamName(root->right->left->id_tim1, head, name6);
    getTeamName(root->right->left->id_tim2, head, name7);
    getTeamName(root->right->right->id_tim1, head, name8);
    getTeamName(root->right->right->id_tim2, head, name9);
    getTeamName(root->id_pemenang, head, winner);
    getMatchScore(root->left->left->left->match_id, history, &skor1, &skor2);
    getMatchScore(root->left->left->match_id, history, &skor3, &skor4);
    getMatchScore(root->left->right->match_id, history, &skor5, &skor6);
    getMatchScore(root->right->left->match_id, history, &skor7, &skor8);
    getMatchScore(root->right->right->match_id, history, &skor9, &skor10);
    getMatchScore(root->left->match_id, history, &skor11, &skor12);
    getMatchScore(root->right->match_id, history, &skor13, &skor14);
    getMatchScore(root->match_id, history, &skor15, &skor16);

    printf("\n");
    printf("%-8s : %d\n", name1, skor1);
    printf("        |--> %-8s : %d\n", name1, skor3);
    printf("%-8s : %d\n", name2, skor2);
    printf("                    |--> %-8s : %d\n", winner, skor11);
    printf("%-8s : %d\n", name3, skor4);
    printf("%-8s : %d\n", name4, skor5);
    printf("        |--> %-8s : %d\n", name5, skor6);
    printf("%-8s : %d\n", name5, skor6);
    printf("                                |--> %-8s : %d\n", winner, skor15);
    printf("%-8s : %d\n", name6, skor7);
    printf("        |--> %-8s : %d\n", name7, skor8);
    printf("%-8s : %d\n", name7, skor8);
    printf("%-8s : %d\n", name8, skor9);
    printf("        |--> %-8s : %d\n", name9, skor10);
    printf("%-8s : %d\n", name9, skor10);
    printf("                    |--> %-8s : %d\n", name9, skor14);
    printf("Winner : %-8s\n\n", winner);
}

void templatebagan10tim(addressTree root, addressList head, Stack *history) {
    if (root == NULL || root->left == NULL || root->right == NULL || root->left->left == NULL || root->left->right == NULL || root->right->left == NULL || root->right->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char name1[9], name2[9], name3[9], name4[9], name5[9], name6[9], name7[9], name8[9], name9[9], name10[9], winner[9];
    int skor1, skor2, skor3, skor4, skor5, skor6, skor7, skor8, skor9, skor10, skor11, skor12, skor13, skor14, skor17, skor18;
    getTeamName(root->left->left->left->id_tim1, head, name1);
    getTeamName(root->left->left->left->id_tim2, head, name2);
    getTeamName(root->left->left->id_tim2, head, name5);
    getTeamName(root->left->right->left->id_tim1, head, name6);
    getTeamName(root->left->right->id_tim2, head, name7);
    getTeamName(root->right->left->id_tim1, head, name3);
    getTeamName(root->right->left->id_tim2, head, name4);
    getTeamName(root->right->right->id_tim1, head, name8);
    getTeamName(root->right->right->id_tim2, head, name9);
    getTeamName(root->right->id_tim2, head, name10);
    getTeamName(root->id_pemenang, head, winner);
    getMatchScore(root->left->left->left->match_id, history, &skor1, &skor2);
    getMatchScore(root->left->left->match_id, history, &skor5, &skor6);
    getMatchScore(root->left->right->left->match_id, history, &skor7, &skor8);
    getMatchScore(root->right->left->match_id, history, &skor3, &skor4);
    getMatchScore(root->right->right->match_id, history, &skor11, &skor12);
    getMatchScore(root->left->match_id, history, &skor9, &skor10);
    getMatchScore(root->right->match_id, history, &skor13, &skor14);
    getMatchScore(root->match_id, history, &skor17, &skor18);

    printf("\n");
    printf("%-8s : %d\n", name1, skor1);
    printf("        |--> %-8s : %d\n", name1, skor5);
    printf("%-8s : %d\n", name2, skor2);
    printf("                    |--> %-8s : %d\n", name1, skor9);
    printf("%-8s : %d\n", name5, skor6);
    printf("%-8s : %d\n", name6, skor7);
    printf("        |                    |--> %-8s : %d\n", winner, skor17);
    printf("%-8s : %d\n", name6, skor8);
    printf("%-8s : %d\n", name3, skor3);
    printf("        |--> %-8s : %d\n", name3, skor13);
    printf("%-8s : %d\n", name4, skor4);
    printf("                    |--> %-8s : %d\n", name3, skor14);
    printf("%-8s : %d\n", name8, skor11);
    printf("        |--> %-8s : %d\n", name9, skor12);
    printf("%-8s : %d\n", name9, skor12);
    printf("%-8s : %d\n", name10, skor14);
    printf("Winner : %-8s\n\n", winner);
}

void templatebagan11tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL || root->left == NULL || root->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    // Untuk 11 tim, pohon biasanya tidak seimbang, tampilkan secara sederhana
    char winner[9];
    getTeamName(root->id_pemenang, head, winner);
    printf("\nBagan 11 Tim (ringkas):\n");
    printf("Final Winner: %s\n", winner);
    // Untuk detail, lakukan traversal preorder dan tampilkan setiap node
    // (bisa dikembangkan lebih lanjut sesuai kebutuhan visualisasi)
}

void templatebagan12tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL || root->left == NULL || root->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char winner[9];
    getTeamName(root->id_pemenang, head, winner);
    printf("\nBagan 12 Tim (ringkas):\n");
    printf("Final Winner: %s\n", winner);
}

void templatebagan13tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL || root->left == NULL || root->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char winner[9];
    getTeamName(root->id_pemenang, head, winner);
    printf("\nBagan 13 Tim (ringkas):\n");
    printf("Final Winner: %s\n", winner);
}

void templatebagan14tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL || root->left == NULL || root->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char winner[9];
    getTeamName(root->id_pemenang, head, winner);
    printf("\nBagan 14 Tim (ringkas):\n");
    printf("Final Winner: %s\n", winner);
}

void templatebagan15tim(addressTree root, addressList head, Stack *history) {
    (void)history;
    if (root == NULL || root->left == NULL || root->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char winner[9];
    getTeamName(root->id_pemenang, head, winner);
    printf("\nBagan 15 Tim (ringkas):\n");
    printf("Final Winner: %s\n", winner);
}

void templatebagan16tim(addressTree root, addressList head, Stack *history) {
    if (root == NULL || root->left == NULL || root->right == NULL ||
        root->left->left == NULL || root->left->right == NULL ||
        root->right->left == NULL || root->right->right == NULL) {
        printf("Pohon turnamen kosong atau tidak valid.\n");
        return;
    }
    char name1[9], name2[9], name3[9], name4[9], name5[9], name6[9], name7[9], name8[9];
    char name9[9], name10[9], name11[9], name12[9], name13[9], name14[9], name15[9], name16[9], winner[9];
    int skor1, skor2, skor3, skor4, skor5, skor6, skor7, skor8;
    int skor9, skor10, skor11, skor12, skor13, skor14, skor15, skor16;
    int skor17, skor18, skor19, skor20, skor21, skor22, skor23, skor24, skor25, skor26, skor27, skor28, skor29, skor30;

    // Babak 16 besar
    getTeamName(root->left->left->left->left->id_tim1, head, name1);
    getTeamName(root->left->left->left->left->id_tim2, head, name2);
    getTeamName(root->left->left->left->right->id_tim1, head, name3);
    getTeamName(root->left->left->left->right->id_tim2, head, name4);
    getTeamName(root->left->left->right->left->id_tim1, head, name5);
    getTeamName(root->left->left->right->left->id_tim2, head, name6);
    getTeamName(root->left->left->right->right->id_tim1, head, name7);
    getTeamName(root->left->left->right->right->id_tim2, head, name8);
    getTeamName(root->right->right->left->left->id_tim1, head, name9);
    getTeamName(root->right->right->left->left->id_tim2, head, name10);
    getTeamName(root->right->right->left->right->id_tim1, head, name11);
    getTeamName(root->right->right->left->right->id_tim2, head, name12);
    getTeamName(root->right->right->right->left->id_tim1, head, name13);
    getTeamName(root->right->right->right->left->id_tim2, head, name14);
    getTeamName(root->right->right->right->right->id_tim1, head, name15);
    getTeamName(root->right->right->right->right->id_tim2, head, name16);
    getTeamName(root->id_pemenang, head, winner);

    // Skor babak 16 besar
    getMatchScore(root->left->left->left->left->match_id, history, &skor1, &skor2);
    getMatchScore(root->left->left->left->right->match_id, history, &skor3, &skor4);
    getMatchScore(root->left->left->right->left->match_id, history, &skor5, &skor6);
    getMatchScore(root->left->left->right->right->match_id, history, &skor7, &skor8);
    getMatchScore(root->right->right->left->left->match_id, history, &skor9, &skor10);
    getMatchScore(root->right->right->left->right->match_id, history, &skor11, &skor12);
    getMatchScore(root->right->right->right->left->match_id, history, &skor13, &skor14);
    getMatchScore(root->right->right->right->right->match_id, history, &skor15, &skor16);

    // Skor babak 8 besar
    getMatchScore(root->left->left->left->match_id, history, &skor17, &skor18);
    getMatchScore(root->left->left->right->match_id, history, &skor19, &skor20);
    getMatchScore(root->right->right->left->match_id, history, &skor21, &skor22);
    getMatchScore(root->right->right->right->match_id, history, &skor23, &skor24);

    // Skor semifinal
    getMatchScore(root->left->left->match_id, history, &skor25, &skor26);
    getMatchScore(root->right->right->match_id, history, &skor27, &skor28);

    // Skor final
    getMatchScore(root->match_id, history, &skor29, &skor30);

    printf("\nBabak 16 Besar:\n");
    printf("%-8s : %d vs %-8s : %d\n", name1, skor1, name2, skor2);
    printf("%-8s : %d vs %-8s : %d\n", name3, skor3, name4, skor4);
    printf("%-8s : %d vs %-8s : %d\n", name5, skor5, name6, skor6);
    printf("%-8s : %d vs %-8s : %d\n", name7, skor7, name8, skor8);
    printf("%-8s : %d vs %-8s : %d\n", name9, skor9, name10, skor10);
    printf("%-8s : %d vs %-8s : %d\n", name11, skor11, name12, skor12);
    printf("%-8s : %d vs %-8s : %d\n", name13, skor13, name14, skor14);
    printf("%-8s : %d vs %-8s : %d\n", name15, skor15, name16, skor16);

    printf("\nBabak 8 Besar:\n");
    printf("Match 1: %d vs %d\n", skor17, skor18);
    printf("Match 2: %d vs %d\n", skor19, skor20);
    printf("Match 3: %d vs %d\n", skor21, skor22);
    printf("Match 4: %d vs %d\n", skor23, skor24);

    printf("\nSemifinal:\n");
    printf("Match 1: %d vs %d\n", skor25, skor26);
    printf("Match 2: %d vs %d\n", skor27, skor28);

    printf("\nFinal:\n");
    printf("Match: %d vs %d\n", skor29, skor30);
    printf("Winner : %-8s\n\n", winner);
}
