/*
PIC: belva
NIM: 241524035
*/

#ifndef MENU_H
#define MENU_H

#include "fileio.h"

void uiGreetings(char *namaEvent);
void mainMenu(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent);
void showsTambahTim(addressList *head);
void showsHapusTim(addressList *head);
void exitProgram(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent);

#endif