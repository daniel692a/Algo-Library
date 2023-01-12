#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef int Data;
typedef struct NodeBST{
    int priority;
    int level;
    int answer;
    struct NodeBST *left, *right;
};

struct NodeBST *newNode(int priority, int level, char expr[20], int answer);
void printPreOrder(struct NodeBST *root);
void printPosOrder(struct NodeBST *root);
void printInOrder(struct NodeBST *root);
void printNodeBST(struct NodeBST *root);

struct NodeBST *insert(struct NodeBST *node, int priority, int level, char expr[20], int answer);
struct NodeBST *insertAnswer(struct NodeBST *node, int priority, int level, char expr[20], int answer);

struct NodeBST *minValueNode(struct NodeBST *node);
struct NodeBST *deleteNode(struct NodeBST *root, int key);

int getLevelUtil(struct NodeBST* node, int answer, int level);

int getLevel(struct NodeBST* node, int answer);