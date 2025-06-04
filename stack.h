/*
PIC : akhsya 
NIM : 241524039
*/

#ifndef STACK_H
#define STACK_H

#include "tree.h"

// Struktur data buat nyimpen hasil pertandingan 

typedef struct {
  int matchID;     // ID pertandingan 
  char namaTim1[50];    // Nama tim 1
  char namaTim2[50];    // Nama tim 2
  char namaTimPemenang; // Nama tim pemenang
  int skorTim1;         // Skor tim 1
  int skorTim2;         // Skor tim 2 
  int nomorRonde; // Nomor ronde/babak
} MatchResult;

// Node buat stack 
typedef struct StackNode{
  MatchResult data;
  struct StackNode* next;
} StackNode;

// Struktur Stack
typedef struct {
  StackNode* top;
  int size ; // ini masih ngga tau sesuai dinamis atau statis
} Stack;

// Fungsi - fungsi dasar stack 

void inisialisasiStack(Stack* s);
bool apakahStackKosong(Stack* s);
void push(Stack* s, MatchResult data);
bool pop(Stack* s, MatchResult* result);
bool peek(Stack* s, MatchResult* result);
void clearStack(Stack* s);
int getStackSize(Stack* s);
void tampilkanHistori(Stack* s); // Tampilkan riwayat pertandingan
void undoMatch(Stack* s, Queue* queue); // Batalkan pertandingan dan kembalikan tim ke Queue

#endif
