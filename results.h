#ifndef RESULTS_H
#define RESULTS_H

#include "linkedlist.h"
#include "tree.h"
#include "stack.h"

// Deklarasi fungsi 
void tampilkanStatistik(addressList head);
void tampilkanHistori(Stack *s);
void tampilkanHistoriDenganNama(Stack *s, addressList head); // TAMBAHAN: Fungsi baru untuk menampilkan nama tim
void inputMatchResult(addressTree *turnamentTree, addressList head, Stack *matchHistory );
void undoMatchResult (addressTree *turnmanetTree, addressList head, Stack *matchHistory);
void updateMatchResult(addressTree root, int match_id, int id_pemenang, int skor1, int skor2, addressList teams, Stack *history);

#endif