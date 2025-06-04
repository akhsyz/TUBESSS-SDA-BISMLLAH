#ifndef TREE_H
#define TREE_H

#include "queue.h"

typedef struct NodeTree {
    int id_tim1; // ID tim pertama (0 jika BYE)
    int id_tim2; // ID tim kedua (0 jika BYE)
    int id_pemenang; // ID pemenang (diisi setelah pertandingan)
    int match_id; // ID pertandingan (seed)
    struct NodeTree* left;
    struct NodeTree* right;
} NodeTree;

typedef NodeTree* addressTree;

void initTree();
void generateTournamentTree(int teamCount, char teams[][50], int scores[], char* winner);

#endif
