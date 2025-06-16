/*
PIC: belva
NIM: 241524035
*/

#ifndef MENU_H
#define MENU_H

#include "fileio.h"

// Fungsi menu utama
void initialUI(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent);
void uiGreetings(char *namaEvent);
void mainMenu(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent);

// Fungsi untuk mengelola turnamen
boolean muatTurnamen(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent);
boolean muatTurnamenTXT(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent);
void buatTurnamen(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent);

// Fungsi menu spesifik
void showsTambahTim(addressList *head);
void showsHapusTim(addressList *head);

// Fungsi keluar program
void exitProgram(addressList *head, Queue *matchQueue, addressTree *tournamentTree, Stack *matchHistory, char *namaEvent);

// Fungsi helper untuk format TXT lama
Stack* loadMatchHistoryFromFileTXT(const char* filename);
addressTree loadTournamentTreeFromFileTXT(const char* filename);

#endif