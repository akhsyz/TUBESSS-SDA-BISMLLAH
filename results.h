#ifndef RESULTS_H
#define RESULTS_H

#include "stack.h"

// Deklarasi fungsi 
void tampilkanStatistik(StackNode* s, StackNode head);
void saveHasilkeFile(StatistikTim tim[], int teamCount, const char* filename);
void inputResult(addressTree *tournamentTree, addressList head, Stack *matchHistory);
void undoResult(addressTree *tournamentTree, addressList head, Stack *matchHistory);
void updateMatchResult(addressTree root, int match_id, int id_pemenang, int skor1, int skor2, addressList teams, Stack *history);

#endif


