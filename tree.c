#include "tree.h"
#include <math.h>

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

addressTree buildTournamentTree(Queue *Q, int total_teams, addressList head) {
    if (total_teams <= 0 || Q == NULL || Q->head == NULL) {
        printf("Jumlah tim tidak valid atau Queue kosong.\n");
        return NULL;
    }
    (void)head; 

    int power_of_two = 1;
    while (power_of_two < total_teams) {
        power_of_two *= 2;
    }
    int total_slots = power_of_two;

    NodeTree **nodes = (NodeTree**)malloc((size_t)total_slots * sizeof(NodeTree*));
    if (nodes == NULL) {
        printf("Gagal mengalokasi memori untuk nodes.\n");
        return NULL;
    }

    int queue_count = countNode(Q->head);
    if (queue_count < total_teams) {
        printf("Tim di Queue (%d) kurang dari total_teams (%d).\n", queue_count, total_teams);
        free(nodes);
        return NULL;
    }

    addressList temp = Q->head;
    for (int i = 0; i < total_slots; i++) {
        int id1 = 0;
        if (temp != NULL && i < total_teams) {
            id1 = temp->id_tim;
            temp = temp->next;
        }
        nodes[i] = createTreeNode(id1, 0, 0); 
    }

    int match_id = 1;
    int parent_count = total_slots / 2;
    while (parent_count > 0) {
        for (int i = 0; i < parent_count; i++) {
            int left_idx = i * 2;
            int right_idx = i * 2 + 1;
            int id_tim1 = nodes[left_idx]->id_tim1;
            int id_tim2 = nodes[right_idx]->id_tim1;
            NodeTree *parent = createTreeNode(id_tim1, id_tim2, match_id++);
            parent->left = nodes[left_idx];
            parent->right = nodes[right_idx];
            nodes[i] = parent;
        }
        parent_count /= 2;
    }

    addressTree root = nodes[0];
    free(nodes);
    return root;
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
    addressTree matchNode = findMatchNode(root, match_id);
    if (matchNode == NULL) return 0;
    int depth = 0;
    addressTree current = root;
    while (current != NULL && current != matchNode) {
        depth++;
        current = (findMatchNode(current->left, match_id) != NULL) ? current->left : current->right;
    }
    if (current == NULL) return 0;
    int total_teams = countNode(head);
    int total_rounds = (int)ceil(log2(total_teams + 1));
    return total_rounds - depth + 1;
}

void clearTree(addressTree *root) {
    if (*root == NULL) return;
    clearTree(&(*root)->left);
    clearTree(&(*root)->right);
    free(*root);
    *root = NULL;
}
