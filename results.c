#include "results.h"

void tampilkanStatistik (addressList head) {
  if (head == NULL) {
    printf("Daftar tim kosong.\n");
    return;
  }
    printf("\n== Statistik Tim ==\n");
    printf("----------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "Nama Tim", "Laga", "Menang", "Kalah");
    printf("----------------------------------------\n");
    addressList current = head;
    while (current != NULL) {
        printf("%-20s %-10d %-10d %-10d\n", current->namaTim, current->laga, current->kemenangan, current->kekalahan);
        current = current->next;
    }
    printf("----------------------------------------\n");
}

void tampilkanHistori(Stack *s) {
    if (apakahStackKosong(s)) { // Ganti isEmpty dengan apakahStackKosong
        printf("Riwayat pertandingan kosong.\n");
        return;
    }
    printf("\n== Riwayat Pertandingan ==\n");
    printf("----------------------------------------\n");
    StackNode *current = s->top;
    while (current != NULL) {
        printf("Match %d: Tim %d (%d) vs Tim %d (%d), Pemenang: Tim %d, Ronde: %d\n",
               current->data.matchID, current->data.team1Id, current->data.skorTim1,
               current->data.team2Id, current->data.skorTim2, current->data.idPemenang,
               current->data.nomorRonde);
        current = current->next;
    }
    printf("----------------------------------------\n");
}

void inputMatchResult(addressTree *tournamentTree, addressList head, Stack *matchHistory) {
    int match_id, id_pemenang, skor1, skor2;
    printf("Masukkan ID pertandingan: ");
    if (scanf("%d", &match_id) != 1 || match_id <= 0) {
        printf("ID pertandingan tidak valid.\n");
        while (getchar() != '\n'); // Bersihkan buffer
        return;
    }
    addressTree matchNode = findMatchNode(*tournamentTree, match_id);
    if (matchNode == NULL) {
        printf("Pertandingan dengan ID %d tidak ditemukan.\n", match_id);
        return;
    }
    printf("Tim %d vs Tim %d\n", matchNode->id_tim1, matchNode->id_tim2);
    printf("Masukkan ID tim pemenang: ");
    if (scanf("%d", &id_pemenang) != 1) {
        printf("ID pemenang tidak valid.\n");
        while (getchar() != '\n'); // Bersihkan buffer
        return;
    }
    // Validasi pemenang, izinkan 0 untuk bye
    if ((id_pemenang != matchNode->id_tim1 && id_pemenang != matchNode->id_tim2) &&
        !(matchNode->id_tim1 == 0 || matchNode->id_tim2 == 0)) {
        printf("ID pemenang tidak valid.\n");
        return;
    }
    printf("Masukkan skor untuk Tim %d: ", matchNode->id_tim1);
    if (scanf("%d", &skor1) != 1) {
        printf("Skor tidak valid.\n");
        while (getchar() != '\n'); // Bersihkan buffer
        return;
    }
    printf("Masukkan skor untuk Tim %d: ", matchNode->id_tim2);
    if (scanf("%d", &skor2) != 1) {
        printf("Skor tidak valid.\n");
        while (getchar() != '\n'); // Bersihkan buffer
        return;
    }
    updateMatchResult(*tournamentTree, match_id, id_pemenang, skor1, skor2, head, matchHistory);
    printf("Hasil pertandingan telah diperbarui.\n");
}