#include <stdio.h>
#include <stdlib.h>

// Create Node
struct NodeAVL {
    int key;
    struct NodeAVL *left;
    struct NodeAVL *right;
    int height;
};

int max(int a, int b);
int height(struct NodeAVL *N);

struct NodeAVL *newNode(int key);

struct NodeAVL *rightRotate(struct NodeAVL *y);
struct NodeAVL *leftRotate(struct NodeAVL *x);

int getBalance(struct NodeAVL *N);

struct NodeAVL *insertNode(struct NodeAVL *node, int key);

struct NodeAVL *minValueNode(struct NodeAVL *node);
struct NodeAVL *deleteNode(struct NodeAVL *root, int key);

void printPreOrder(struct NodeAVL *root);