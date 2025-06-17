/*
PIC : akhsya 
NIM : 241524039
*/

#include "stack.h"

// Wrapper untuk membuat node Stack dari MatchResult
static StackNode* createStackNode(MatchResult data) {
  StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
  if (newNode != NULL) {
    newNode->data = data;
    newNode->next = NULL;
  }
  return newNode;
}

// Wrapper untuk insertAtFirst agar kompatibel dengan StackNode
static void insertAtFirstStack(Stack* s, StackNode* newNode) {
  if (newNode == NULL) return;
  newNode->next = s->top;
  s->top = newNode;
  s->size++;
}

// Wrapper untuk deleteFirst agar kompatibel dengan StackNode
static boolean deleteFirstStack(Stack* s, MatchResult* result) {
  if (s->top == NULL){
    return false;
  }
  StackNode* temp = s->top;
  *result = temp->data;
  s->top = temp->next;
  free(temp);
  s->size--;
  return true;
}

// Inisialisasi stack
void inisialisasiStack(Stack* s) {
  s->top = NULL;
  s->size = 0;
}

// Cek apakah stack kosong 
boolean apakahStackKosong(Stack* s) {
  return (s->top == NULL);
}

// Tambah riwayat pertandingan ke stack
void push (Stack* s, MatchResult data) {
  StackNode* newNode = createStackNode(data);
  if (newNode == NULL) {
    printf("Gagal membuat node baru buat stack Kang/Teh.\n");
    return;
  }
  insertAtFirstStack(s, newNode); // Gunakan logika insert at first
}

// Hapus dan kembalikan pertandingan terakhir
boolean pop (Stack* s, MatchResult* result){
  return deleteFirstStack(s, result); // Gunakan logika deleteFirst
}

// Lihat pertandingan teratas tanpa menghapus 
boolean peek(Stack* s, MatchResult* result){
  if (apakahStackKosong(s)) {
    return false;
  }
  *result = s->top->data;
  return true;
}

void clearStack(Stack* s){
  if (s == NULL) return;
  
  MatchResult dummy;
  int cleared_count = 0;
  
  while (pop(s, &dummy)) {
    cleared_count++;
  }
  
  s->size = 0;
  s->top = NULL;
  
  if (cleared_count > 0) {
    printf("   - %d match history dihapus dari stack\n", cleared_count);
  }
}

void clearStackSilent(Stack* s){
  if (s == NULL) return;
  
  MatchResult dummy;
  
  while (pop(s, &dummy)) {
   
  }
  
  s->size = 0;
  s->top = NULL;
  
}

// Mendapatkan ukuran stack
int getStackSize(Stack* s){
  return s->size;
}