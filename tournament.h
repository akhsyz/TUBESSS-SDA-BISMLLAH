#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "stack.h"

void tambahTim(addressList *head);
void hapusTim(addressList *head);
void jadwalkanPertandingan(addressList head, Queue *matchQueue, addressTree *tournamentTree);
void calculateStatistik(addressList head);

#endif