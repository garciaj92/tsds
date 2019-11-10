#ifndef _BINTREE_H_
#define _BINTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum traversal { PRE, POST, IN } traversal;
typedef struct _node_t node_t;
typedef struct _bintree_t bintree_t;

struct _node_t {
  int key;
  char *value;
  node_t *left;
  node_t *right;
};

struct _bintree_t {
  node_t *head;
};

// Creation ops
void init(bintree_t **bt);
bintree_t* init_bt_with_head(int head_key, char* value);
node_t* new_node(int key, char *value);

// Insertion ops
int insert_node(node_t **bt_n, node_t *n);
int insert(bintree_t *bt, node_t *n);

// Free mem ops
void free_subtree(node_t *n);
void free_bt(bintree_t *bt);

// Print ops
void print_node(node_t *n);
void print(bintree_t *bt, traversal order);
void print_subtree_inorder(node_t *n);
void print_subtree_postorder(node_t *n);
void print_subtree_preorder(node_t *n);

// Find ops
node_t* find(bintree_t *bt, int key);
node_t* find_in_subtree(node_t *n, int key);

#endif
