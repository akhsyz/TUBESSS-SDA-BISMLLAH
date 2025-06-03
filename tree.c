#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "linkedlist.h"

void initTree() {
    // Tidak ada inisialisasi khusus di sini
}

void generateTournamentTree(int teamCount, char teams[][50], int scores[], char* winner) {
    // Mengambil daftar tim dari Linked List
    Node* current = head;
    int i = 0;
    while (current != NULL && i < teamCount) {
        strcpy(teams[i], current->teamName);
        scores[i] = 0; // Inisialisasi skor awal
        i++;
        current = current->next;
    }

    // Memanggil template berdasarkan jumlah tim
    switch (teamCount) {
        case 4:
            templatebagan4tim(teams, scores, winner);
            break;
        case 5:
            templatebagan5tim(teams, scores, winner);
            break;
        case 6:
            templatebagan6tim(teams, scores, winner);
            break;
        case 7:
            templatebagan7tim(teams, scores, winner);
            break;
        case 8:
            templatebagan8tim(teams, scores, winner);
            break;
        case 9:
            templatebagan9tim(teams, scores, winner);
            break;
        case 10:
            templatebagan10tim(teams, scores, winner);
            break;
        case 11:
            templatebagan11tim(teams, scores, winner);
            break;
        case 12:
            templatebagan12tim(teams, scores, winner);
            break;
        case 13:
            templatebagan13tim(teams, scores, winner);
            break;
        case 14:
            templatebagan14tim(teams, scores, winner);
            break;
        case 15:
            templatebagan15tim(teams, scores, winner);
            break;
        case 16:
            templatebagan16tim(teams, scores, winner);
            break;
        default:
            printf("Jumlah tim tidak didukung (harus 4-16 tim)!\n");
            break;
    }
}
