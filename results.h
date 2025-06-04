#ifndef RESULTS_H
#define RESULTS_H

#include "stack.h"

#define MAX_TIM 16
#define MAX_NAMA 50

// Struktur untuk menyimpan statistik tim 
typedef struct {
  char namaTim[MAX_NAMA];
  int laga;
  int menang;
  int kalah:
} StatistikTim;

// Deklarasi fungsi 
void tampilkanStatistik(StackNode* s, StackNode head);
void saveHasilkeFile(StatistikTim tim[], int teamCount, const char* filename);
void inputResult(addressTree *tournamentTree, addressList head, Stack *matchHistory);
void undoResult(addressTree *tournamentTree, addressList head, Stack *matchHistory);

#endif


