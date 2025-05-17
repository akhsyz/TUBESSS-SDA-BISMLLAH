/*
PIC : akhsya 
NIM : 241524039
*/

#include "stack.h"

// Inisialisasi stack
void inisialisasiStack(Stack* s) {
  s->top = NULL;
  s->size = 0;
}

// Cek apakah stack kosong 
bool apakahStackKosong(Stack* s) {
  return (s->top == NULL);
}

// Push data ke stack 
void push (Stack* s, MatchResult data) {

}

// Pop data dari stack 
bool pop (Stack* s, MatchResult* result){

}

// Lihat data teratas tanpa ngambil 
bool peek(Stack* s, MatchResult* result){

}

// Bersihin semua isi stack 
void clearStack(Stack* s){

}

// Mendapatkan ukuran stack
int getStackSize(Stack* s){

}


