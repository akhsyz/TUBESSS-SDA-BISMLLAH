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

// Tambah riwayat pertandingan ke stack
void push (Stack* s, MatchResult data) {
  StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
  if (!newNode)
  {
    printf("Error: Gagal alokasi memori untuk StackNode\n");
    return;
  }
  newNode->data = data;
  newNode->next = s->top;
  s->top = newNode;
  s->size++;
}

// Hapus dan kembalikan pertandingan terakhir
bool pop (Stack* s, MatchResult* result){
  if (apakahStackKosong(s))
  {
    return false;
  }
  StackNode* temp = s->top;
  *result = temp->data;
  s->size--;
  return true;
}

// Lihat pertandingan teratas tanpa menghapus 
bool peek(Stack* s, MatchResult* result){
  if (apakahStackKosong(s))
  {
    return false;
  }
  *result = s->top->data;
  return true;
}

// Kosongkan semua isi stack 
void clearStack(Stack* s){
  StackNode*s current = s->top;
  while (current != NULL)
  {
    StackNode* temp = current;
    current = current->next;
    free(temp);
  }
  s->top = NULL;
  s->size = 0;
}

// Mendapatkan ukuran stack
int getStackSize(Stack* s){
  return s->size;
}

// Tampilkan riwayat pertandingan
void tampilkanHistori(){

}

// Batalkan pertandingan terakhir dan kembalikan tim ke Queue
void undoMatch(){

}

