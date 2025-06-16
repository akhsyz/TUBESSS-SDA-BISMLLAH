/*
PIC : belva 
NIM : 241524035
*/

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "templatebagan.h" 

// Fungsi dasar manajemen tim
void tambahTim(addressList *head);
void hapusTim(addressList *head);

// Fungsi penjadwalan turnamen
void jadwalkanPertandingan(addressList head, Queue *matchQueue, addressTree *tournamentTree);

// Fungsi helper untuk tampilan pertandingan
void tampilkanPertandinganSiap(addressTree root, int target_round);
void tampilkanPertandinganTersedia(addressTree root, addressList head);
void cekStatusTurnamen(addressTree root);
void tampilkanPertandinganSiapRapi(addressTree root, addressList head, int target_round);

// Fungsi untuk menampilkan bracket
void tampilkanBracket(addressTree root, addressList head);
void tampilkanBracketDetailed(addressTree root, addressList head, int depth);
void tampilkanPertandinganRound(addressTree root, addressList head, int target_round);

// Fungsi utility untuk nama tim
char* getNamaTim(int id_tim, addressList head);
void tampilkanInfoPertandingan(addressTree match, addressList head);

#endif