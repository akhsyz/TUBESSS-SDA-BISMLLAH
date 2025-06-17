/*
PIC : aufa
NIM : 241524052
*/

#include "tree.h"

addressTree createTreeNode(int id_tim1, int id_tim2, int match_id) {
    addressTree newNode = (addressTree)malloc(sizeof(NodeTree));
    if (newNode != NULL) {
        newNode->id_tim1 = id_tim1;
        newNode->id_tim2 = id_tim2;
        newNode->id_pemenang = 0;
        newNode->match_id = match_id;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

addressTree createMatchNode(int id_tim1, int id_tim2, int match_id) {
    return createTreeNode(id_tim1, id_tim2, match_id);
}

int isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

addressTree buildTree3Teams(int teams[], int *match_id) {
    addressTree semi = createMatchNode(teams[0], teams[1], (*match_id)++);
    addressTree final = createMatchNode(-1, teams[2], (*match_id)++);
    final->left = semi;
    
    return final;
}

addressTree buildTree4Teams(int teams[], int *match_id) {
    addressTree semi1 = createMatchNode(teams[0], teams[1], (*match_id)++);
    addressTree semi2 = createMatchNode(teams[2], teams[3], (*match_id)++);
    addressTree final = createMatchNode(-1, -1, (*match_id)++);
    final->left = semi1;
    final->right = semi2;
    
    return final;
}

addressTree buildTree5Teams(int teams[], int *match_id) {
    addressTree match1 = createMatchNode(teams[0], teams[1], (*match_id)++);
    
    addressTree match2 = createMatchNode(teams[2], teams[3], (*match_id)++);
    
    addressTree match3 = createMatchNode(-1, teams[4], (*match_id)++);
    match3->left = match1;
    
    addressTree final = createMatchNode(-1, -1, (*match_id)++);
    final->left = match3;
    final->right = match2;
    
    return final;
}

addressTree buildTree6Teams(int teams[], int *match_id) {
    addressTree match1 = createMatchNode(teams[0], teams[1], (*match_id)++);
    
    addressTree match2 = createMatchNode(teams[2], teams[3], (*match_id)++);
    
    addressTree semi1 = createMatchNode(-1, teams[4], (*match_id)++);
    semi1->left = match1;
    
    addressTree semi2 = createMatchNode(-1, teams[5], (*match_id)++);
    semi2->left = match2;
    
    addressTree final = createMatchNode(-1, -1, (*match_id)++);
    final->left = semi1;
    final->right = semi2;
    
    return final;
}


addressTree buildTree7Teams(int teams[], int *match_id) {
   
    addressTree match1 = createMatchNode(teams[0], teams[1], (*match_id)++); 
    addressTree match2 = createMatchNode(teams[2], teams[3], (*match_id)++);   
    addressTree match3 = createMatchNode(teams[4], teams[5], (*match_id)++); 
    
    addressTree semi1 = createMatchNode(-1, -1, (*match_id)++);
    semi1->left = match1;
    semi1->right = match2;
    
    addressTree semi2 = createMatchNode(-1, teams[6], (*match_id)++);
    semi2->left = match3;
    
    addressTree final = createMatchNode(-1, -1, (*match_id)++);
    final->left = semi1;
    final->right = semi2;
    
    return final;
}


addressTree buildTree8Teams(int teams[], int *match_id) {
    addressTree quarter1 = createMatchNode(teams[0], teams[1], (*match_id)++);
    addressTree quarter2 = createMatchNode(teams[2], teams[3], (*match_id)++);
    addressTree quarter3 = createMatchNode(teams[4], teams[5], (*match_id)++);
    addressTree quarter4 = createMatchNode(teams[6], teams[7], (*match_id)++);
    
    addressTree semi1 = createMatchNode(-1, -1, (*match_id)++);
    semi1->left = quarter1;
    semi1->right = quarter2;
    
    addressTree semi2 = createMatchNode(-1, -1, (*match_id)++);
    semi2->left = quarter3;
    semi2->right = quarter4;
    
    addressTree final = createMatchNode(-1, -1, (*match_id)++);
    final->left = semi1;
    final->right = semi2;
    
    return final;
}

addressTree buildTree9Teams(int teams[], int *match_id) {
    addressTree match1 = createMatchNode(teams[0], teams[1], (*match_id)++);
    
    addressTree quarter1 = createMatchNode(-1, teams[2], (*match_id)++);  
    quarter1->left = match1;
    
    addressTree quarter2 = createMatchNode(teams[3], teams[4], (*match_id)++);
    addressTree quarter3 = createMatchNode(teams[5], teams[6], (*match_id)++);
    addressTree quarter4 = createMatchNode(teams[7], teams[8], (*match_id)++);
    
    addressTree semi1 = createMatchNode(-1, -1, (*match_id)++);
    semi1->left = quarter1;
    semi1->right = quarter2;
    
    addressTree semi2 = createMatchNode(-1, -1, (*match_id)++);
    semi2->left = quarter3;
    semi2->right = quarter4;
    
    addressTree final = createMatchNode(-1, -1, (*match_id)++);
    final->left = semi1;
    final->right = semi2;
    
    return final;
}

addressTree buildTree10Teams(int teams[], int *match_id) {
    addressTree match1 = createMatchNode(teams[0], teams[1], (*match_id)++);
    addressTree match2 = createMatchNode(teams[2], teams[3], (*match_id)++);
    
    addressTree quarter1 = createMatchNode(-1, teams[4], (*match_id)++);  
    quarter1->left = match1;
    
    addressTree quarter2 = createMatchNode(-1, teams[5], (*match_id)++);  
    quarter2->left = match2;
    
    addressTree quarter3 = createMatchNode(teams[6], teams[7], (*match_id)++);
    addressTree quarter4 = createMatchNode(teams[8], teams[9], (*match_id)++);
    
    addressTree semi1 = createMatchNode(-1, -1, (*match_id)++);
    semi1->left = quarter1;
    semi1->right = quarter2;
    
    addressTree semi2 = createMatchNode(-1, -1, (*match_id)++);
    semi2->left = quarter3;
    semi2->right = quarter4;
    
    addressTree final = createMatchNode(-1, -1, (*match_id)++);
    final->left = semi1;
    final->right = semi2;
    
    return final;
}

addressTree buildTree11Teams(int teams[], int *match_id) {
    addressTree match1 = createMatchNode(teams[0], teams[1], (*match_id)++); 
    addressTree match2 = createMatchNode(teams[2], teams[3], (*match_id)++); 
    addressTree match3 = createMatchNode(teams[4], teams[5], (*match_id)++); 
    addressTree match4 = createMatchNode(teams[6], teams[7], (*match_id)++); 
    addressTree match5 = createMatchNode(teams[8], teams[9], (*match_id)++); 
    
    addressTree quarter1 = createMatchNode(-1, -1, (*match_id)++);           
    quarter1->left = match1;
    quarter1->right = match2;
    
    addressTree quarter2 = createMatchNode(-1, -1, (*match_id)++);           
    quarter2->left = match3;
    quarter2->right = match4;
    
    addressTree quarter3 = createMatchNode(-1, teams[10], (*match_id)++);    
    quarter3->left = match5;
    
    addressTree semi1 = createMatchNode(-1, -1, (*match_id)++);              
    semi1->left = quarter1;
    semi1->right = quarter2;
    
    addressTree final = createMatchNode(-1, -1, (*match_id)++);              
    final->left = semi1;
    final->right = quarter3; 
    
    return final;
}

addressTree buildTree12Teams(int teams[], int *match_id) {
    addressTree match1 = createMatchNode(teams[0], teams[1], (*match_id)++); 
    addressTree match2 = createMatchNode(teams[2], teams[3], (*match_id)++); 
    addressTree match3 = createMatchNode(teams[4], teams[5], (*match_id)++); 
    addressTree match4 = createMatchNode(teams[6], teams[7], (*match_id)++); 
    addressTree match5 = createMatchNode(teams[8], teams[9], (*match_id)++); 
    addressTree match6 = createMatchNode(teams[10], teams[11], (*match_id)++); 
    
    addressTree quarter1 = createMatchNode(-1, -1, (*match_id)++);           
    quarter1->left = match1;
    quarter1->right = match2;
    
    addressTree quarter2 = createMatchNode(-1, -1, (*match_id)++);           
    quarter2->left = match3;
    quarter2->right = match4;
    
    addressTree quarter3 = createMatchNode(-1, -1, (*match_id)++);           
    quarter3->left = match5;
    quarter3->right = match6;
    
    addressTree semi1 = createMatchNode(-1, -1, (*match_id)++);              
    semi1->left = quarter1;
    semi1->right = quarter2;
    
    addressTree semi2 = quarter3; 
    
    addressTree final = createMatchNode(-1, -1, (*match_id)++);
    final->left = semi1;
    final->right = semi2;
    
    return final;
}

addressTree buildTournamentTree(Queue *Q, int total_teams, addressList head) {
    (void)head;
    
    if (total_teams <= 0 || Q == NULL || Q->head == NULL) {
        return NULL;
    }
    
    if (total_teams < 3 || total_teams > 12) {
        return NULL;
    }

    int teams[12]; 
    addressList temp = Q->head;
    for (int i = 0; i < total_teams && temp != NULL; i++) {
        teams[i] = temp->id_tim;
        temp = temp->next;
    }
    
    int match_id = 1;
    
    switch(total_teams) {
        case 3:
            return buildTree3Teams(teams, &match_id);
        case 4:
            return buildTree4Teams(teams, &match_id);
        case 5:
            return buildTree5Teams(teams, &match_id);
        case 6:
            return buildTree6Teams(teams, &match_id);
        case 7:
            return buildTree7Teams(teams, &match_id);
        case 8:
            return buildTree8Teams(teams, &match_id);
        case 9:
            return buildTree9Teams(teams, &match_id);
        case 10:
            return buildTree10Teams(teams, &match_id);
        case 11:
            return buildTree11Teams(teams, &match_id);
        case 12:
            return buildTree12Teams(teams, &match_id);
        default:
            return NULL;
    }
}

void updateMatchWinner(addressTree root, int match_id, int winner_id) {
    if (root == NULL) {
        return;
    }
    
    addressTree match_node = findMatchNode(root, match_id);
    if (match_node == NULL) {
        return;
    }
    
    if (winner_id != match_node->id_tim1 && winner_id != match_node->id_tim2) {
        return;
    }
    
    match_node->id_pemenang = winner_id;
    
    updateParentNodes(root, match_node);
}

void updateParentNodes(addressTree root, addressTree changed_node) {
    addressTree parent = findParentNode(root, changed_node);
    if (parent != NULL && changed_node->id_pemenang != 0) {
        if (parent->left == changed_node) {
            parent->id_tim1 = changed_node->id_pemenang;
        } else if (parent->right == changed_node) {
            parent->id_tim2 = changed_node->id_pemenang;
        }
        
        if (parent->id_tim1 > 0 && parent->id_tim2 > 0) {
        }
    }
}

addressTree findMatchNode(addressTree root, int match_id) {
    if (root == NULL) return NULL;
    if (root->match_id == match_id) return root;
    
    addressTree left = findMatchNode(root->left, match_id);
    if (left != NULL) return left;
    
    return findMatchNode(root->right, match_id);
}

addressTree findParentNode(addressTree root, addressTree childNode) {
    if (root == NULL || childNode == NULL) return NULL;
    if (root->left == childNode || root->right == childNode) return root;
    
    addressTree left = findParentNode(root->left, childNode);
    if (left != NULL) return left;
    
    return findParentNode(root->right, childNode);
}

int calculateRoundNumber(addressTree root, int match_id, addressList head) {
    (void)head; 
    
    addressTree matchNode = findMatchNode(root, match_id);
    if (matchNode == NULL) return 0;
    
    int depth = 0;
    
    addressTree current = matchNode;
    while (current != NULL && (current->left != NULL || current->right != NULL)) {
        depth++;
        if (current->left != NULL) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return depth + 1;
}

int calculateDepthFromLeaf(addressTree root, addressTree target) {
    if (root == NULL || target == NULL) return -1;
    if (root == target) {
        if (root->left == NULL && root->right == NULL) {
            return 0;
        }
        int left_depth = calculateMaxDepth(root->left);
        int right_depth = calculateMaxDepth(root->right);
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }
    
    int left_result = calculateDepthFromLeaf(root->left, target);
    if (left_result >= 0) return left_result;
    
    return calculateDepthFromLeaf(root->right, target);
}

int calculateMaxDepth(addressTree root) {
    if (root == NULL) return -1;
    if (root->left == NULL && root->right == NULL) return 0;
    
    int left_depth = calculateMaxDepth(root->left);
    int right_depth = calculateMaxDepth(root->right);
    
    return ((left_depth > right_depth) ? left_depth : right_depth) + 1;
}

void clearTree(addressTree *root) {
    if (root == NULL || *root == NULL) return;
    clearTree(&(*root)->left);
    clearTree(&(*root)->right);
    free(*root);
    *root = NULL;
}

void printTreeStructure(addressTree root, int depth) {
    if (root == NULL) return;
    
    for (int i = 0; i < depth; i++) printf("  ");
    printf("Match %d: Tim %d vs Tim %d", root->match_id, root->id_tim1, root->id_tim2);
    if (root->id_pemenang != 0) {
        printf(" (Winner: %d)", root->id_pemenang);
    }
    printf("\n");
    
    if (root->left != NULL || root->right != NULL) {
        printTreeStructure(root->left, depth + 1);
        printTreeStructure(root->right, depth + 1);
    }
}

void getMatchesByRound(addressTree root, int target_round, addressTree matches[], int *count) {
    if (root == NULL) return;
    
    int current_round = calculateRoundNumber(root, root->match_id, NULL);
    if (current_round == target_round) {
        matches[(*count)++] = root;
    }
    
    getMatchesByRound(root->left, target_round, matches, count);
    getMatchesByRound(root->right, target_round, matches, count);
}

TournamentTree* buildTournamentTreeWithMeta(Queue *Q, int total_teams, addressList head) {
    TournamentTree* tournament = (TournamentTree*)malloc(sizeof(TournamentTree));
    if (tournament == NULL) {
        return NULL;
    }
    
    tournament->root = buildTournamentTree(Q, total_teams, head);
    
    if (tournament->root == NULL) {
        free(tournament);
        return NULL;
    }
    
    tournament->meta.total_participants = total_teams;
    strcpy(tournament->meta.tournament_format, "Single Elimination");
    
    int rounds = 0;
    if (total_teams <= 1) {
        rounds = 0;
    } else if (total_teams == 2) {
        rounds = 1; 
    } else if (total_teams <= 4) {
        rounds = 2; 
    } else if (total_teams <= 8) {
        rounds = 3; 
    } else if (total_teams <= 16) {
        rounds = 4; 
    } else {
        int temp_teams = total_teams;
        while (temp_teams > 1) {
            temp_teams = (temp_teams + 1) / 2;
            rounds++;
        }
    }
    
    tournament->meta.total_rounds = rounds;
    
    return tournament;
}

int getTournamentParticipants(TournamentTree *tournament) {
    if (tournament == NULL) {
        return 0;
    }
    return tournament->meta.total_participants;
}

void setTournamentMetadata(TournamentTree *tournament, int participants, const char* format) {
    if (tournament == NULL) return;
    
    tournament->meta.total_participants = participants;
    strncpy(tournament->meta.tournament_format, format, 19);
    tournament->meta.tournament_format[19] = '\0';
}

void clearTournamentTree(TournamentTree **tournament) {
    if (tournament == NULL || *tournament == NULL) return;
    
    clearTree(&((*tournament)->root));
    
    free(*tournament);
    *tournament = NULL;
}
