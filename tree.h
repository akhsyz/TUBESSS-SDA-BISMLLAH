#ifndef BTREE_H
#define BTREE_H

#include "queue.h"

typedef struct NodeTree {
    int id_tim1;       
    int id_tim2;        
    int id_pemenang;    
    int match_id;      
    struct NodeTree* left;
    struct NodeTree* right;
} NodeTree;

typedef NodeTree* addressTree;

addressTree createTreeNode(int id_tim1, int id_tim2, int match_id);
addressTree buildTournamentTree(Queue *Q, int total_teams, addressList head);
addressTree findMatchNode(addressTree root, int match_id);
addressTree findParentNode(addressTree root, addressTree node);
int calculateRoundNumber(addressTree root, int match_id, addressList head);
void clearTree(addressTree *root);

#endif
