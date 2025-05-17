/*
PIC : akhsya 
NIM : 241524039
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur data buat nyimpen hasil pertandingan 

typedef struct {
  int matchID;     // ID pertandingan 
  int team1Id;    // ID tim 1
  int team2Id;    // ID tim 2
  int idPemenang; // ID pemenang 
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
  int size;
} Stack;

// Fungsi - fungsi dasar stack 

void inisialisasiStack(Stack* s);
bool apakahStackKosong(Stack* s);
void push(Stack* s, MatchResult data);
bool pop(Stack* s, MatchResult* result);
bool peek(Stack* s, MatchResult* result);
void clearStack(Stack* s);
int getStackSize(Stack* s);

#endif
