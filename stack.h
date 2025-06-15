/*
PIC : akhsya 
NIM : 241524039
*/

#ifndef STACK_H
#define STACK_H

#include "tree.h"
#include "convention.h"  // Gunakan convention.h untuk konsistensi

// Struktur data buat nyimpen hasil pertandingan 

typedef struct {
  int matchID;     // ID pertandingan 
  int team1Id;    // ID tim 1
  int team2Id;    // ID tim 2
  int idPemenang; // ID tim pemenang
  int nomorRonde; // Nomor ronde/babak
  int skorTim1;   // Skor tim 1
  int skorTim2;   // Skor tim 2 
} MatchResult;

// Node buat stack 
typedef struct StackNode{
  MatchResult data;
  struct StackNode* next;
} StackNode;

// Struktur Stack
typedef struct {
  StackNode* top;
  int size ; 
} Stack;

// Fungsi - fungsi dasar stack 
// Gunakan boolean dari convention.h alih-alih bool

void inisialisasiStack(Stack* s);
boolean apakahStackKosong(Stack* s);
void push(Stack* s, MatchResult data);
boolean pop(Stack* s, MatchResult* result);
boolean peek(Stack* s, MatchResult* result);
void clearStack(Stack* s);
int getStackSize(Stack* s);

// untuk kompatibilitas dengan tournament.c
#define initStack inisialisasiStack
#define isStackEmpty apakahStackKosong
#define pushStack(s, match_id, winner_id) do { \
    MatchResult result = {match_id, 0, 0, winner_id, 0, 0, 0}; \
    push(s, result); \
} while(0)

#endif