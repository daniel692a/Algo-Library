#include "BST.h"
#include <stdio.h>

struct NodeBST *newNode(int priority, int level, char expr[20], int answer){
    struct NodeBST *temp = (struct NodeBST *) malloc(sizeof(struct NodeBST));
    if(temp==NULL){
        perror("No hay memoria:(");
        return NULL;
    }
    temp->priority = priority;
    temp->level = level;
    temp->answer = answer;
    strcpy(temp->expr, expr);
    temp->left = temp->right = NULL;
    return temp;
}

struct NodeBST *insert(struct NodeBST *node, int priority, int level, char expr[20], int answer){
    if (node == NULL){
        return newNode(priority, level, expr, answer);
    }
    if (priority < node->priority){
        node->left = insert(node->left, priority, level, expr, answer);
    } else {
        node->right = insert(node->right, priority, level, expr, answer);
    }
    return node;
}

struct NodeBST *insertAnswer(struct NodeBST *node, int priority, int level, char expr[20], int answer){
    if (node == NULL){
        return newNode(priority, level, expr, answer);
    }
    if (answer < node->answer){
        node->left = insertAnswer(node->left, priority, level, expr, answer);
    } else {
        node->right = insertAnswer(node->right, priority, level, expr, answer);
    }
    return node;
}

struct NodeBST *minValueNode(struct NodeBST *node){
    struct NodeBST *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


void printInOrder(struct NodeBST *root){
    if (root != NULL){
        // Traverse left
        printInOrder(root->left);
        // Traverse root
        printNodeBST(root);
        // Traverse right
        printInOrder(root->right);
    }
}

void printNodeBST(struct NodeBST *root){
    printf("Expresion: %s\tPrioridad: %d\tEvaluación de la expresion: %d\tNivel: %d\n", root->expr, root->priority, root->answer, root->level);
}

struct NodeBST *deleteNode(struct NodeBST *root, int key){
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (key < root->answer)
        root->left = deleteNode(root->left, key);
    else if (key > root->answer)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL){
            struct NodeBST *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            struct NodeBST *temp = root->left;
            free(root);
            return temp;
        }
        struct NodeBST *temp = minValueNode(root->right);

        root->answer = temp->answer;

        root->right = deleteNode(root->right, temp->answer);
    }
    return root;
}


void printPreOrder(struct NodeBST *root){
    if (root){
        printNodeBST(root);

        printPreOrder(root->left);
        printInOrder(root->right);
    }
}

void printPosOrder(struct NodeBST *root){
    if (root){
        printPosOrder(root->left);
        printPosOrder(root->right);

        printNodeBST(root);
    }
}

int getLevelUtil(struct NodeBST* node, int answer, int level){
    if (node == NULL)
        return 0;
    if (node->answer == answer)
        return level;

    int downlevel = getLevelUtil(node->left, answer, level + 1);

    if (downlevel != 0) return downlevel;

    downlevel = getLevelUtil(node->right, answer, level + 1);
    return downlevel;
}

int getLevel(struct NodeBST* node, int answer){
    return getLevelUtil(node, answer, 1);
}