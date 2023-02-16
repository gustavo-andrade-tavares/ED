// TAD Arvore B
/*
#define ordem 8

typedef struct arv_b {
    int tam;
    int elems; // quantidade de elementos na arvore
    int info[ordem - 1]; // vetor contendo todas as informações do no
    struct arv_b *filhos[ordem]; // vetor contendo os filhos
} Arvore_B; */
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

struct BTreeNode {
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
};

struct BTreeNode *root;

struct BTreeNode *createNode(int val, struct BTreeNode *child);
void insertNode(int val, int pos, struct BTreeNode *node, struct BTreeNode *child);
void splitNode(int val, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode);
int setValue(int val, int *pval, struct BTreeNode *node, struct BTreeNode **child);
void insert(int val);
void search(int val, int *pos, struct BTreeNode *myNode);
void traversal(struct BTreeNode *myNode); */

#define MAX 3
#define MIN 2

struct BTreeNode {
  int item[MAX + 1], count;
  struct BTreeNode *linker[MAX + 1];
};

struct BTreeNode *root;

struct BTreeNode *createNode(int item, struct BTreeNode *child);
void addValToNode(int item, int pos, struct BTreeNode *node, struct BTreeNode *child);
void splitNode(int item, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode);
int setValueInNode(int item, int *pval, struct BTreeNode *node, struct BTreeNode **child);
void insertion(int item);
void copySuccessor(struct BTreeNode *myNode, int pos);
void removeVal(struct BTreeNode *myNode, int pos);
void rightShift(struct BTreeNode *myNode, int pos);
void leftShift(struct BTreeNode *myNode, int pos);
void mergeNodes(struct BTreeNode *myNode, int pos);
void adjustNode(struct BTreeNode *myNode, int pos);
int delValFromNode(int item, struct BTreeNode *myNode);
void delete (int item, struct BTreeNode *myNode);
void searching(int item, int *pos, struct BTreeNode *myNode);
void traversal(struct BTreeNode *myNode);
