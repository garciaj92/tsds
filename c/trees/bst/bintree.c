#include "bintree.h"

node_t* new_node(int key, char *value)
{
  node_t *node  = (node_t *)malloc(sizeof(node_t));
  
  node->key = key;
  node->value = (char *)malloc(strlen(value) + 1);
  strcpy(node->value, value);

  node->left = NULL;
  node->right = NULL;
  
  return node;
}

bintree_t* init_bt_with_head(int head_key, char* value)
{
  bintree_t *bt = (bintree_t *)malloc(sizeof(bintree_t));
  bt->head = new_node(head_key, value);
  return bt;
}

void init(bintree_t **bt)
{
  *bt = (bintree_t *)malloc(sizeof(bintree_t));
}

void free_subtree(node_t *n)
{
  if(n)
  {
//    printf("freeing(%d)\n", n->key);

    free_subtree(n->left);
    free_subtree(n->right);
    free(n->value);
    free(n);
  }
}

void free_bt(bintree_t *bt)
{
  if(bt)
  {
    free_subtree(bt->head);
    free(bt);
  }
}

int insert_node(node_t **bt_n, node_t *n)
{
  if(!*bt_n || (*bt_n)->key == n->key)
  {
    *bt_n = n;
    return 0;
  }
  
  if((*bt_n)->key < n->key) return insert_node( &(*bt_n)->right, n);
  return insert_node( &(*bt_n)->left, n);
}

int insert(bintree_t *bt, node_t *n)
{
  if(!bt || !n) return -1;

  if(!bt->head || bt->head->key == n->key)
  {
    bt->head = n;
    return 0;
  }

  if(bt->head->key < n->key) return insert_node(&bt->head->right, n);
  return insert_node(&bt->head->left, n);
}

void print_subtree_inorder(node_t *n)
{
  if(n)
  {
    print_subtree_inorder(n->left);
    printf(" %d ", n->key);
    print_subtree_inorder(n->right);
  }
}

void print_subtree_postorder(node_t *n)
{
  if(n)
  {
    print_subtree_postorder(n->left);
    print_subtree_postorder(n->right);
    printf(" %d ", n->key);
  }
}

void print_subtree_preorder(node_t *n)
{
  if(n)
  {
    printf(" %d ", n->key);
    print_subtree_preorder(n->left);
    print_subtree_preorder(n->right);
  }
}

void print(bintree_t *bt, traversal order)
{
  if(bt)
  {
    if(order == PRE)
    {
      printf("preorder : ");
      print_subtree_preorder(bt->head);
    }
    if(order == IN)
    {
      printf("inorder  : ");
      print_subtree_inorder(bt->head);
    }
    if(order == POST)
    {
      printf("postorder: ");
      print_subtree_postorder(bt->head);
    }
    printf("\n");
  }
}

node_t* find_in_subtree(node_t *n, int key)
{
  node_t *node = NULL;

  if(n)
  {
    if(n->key == key)
      node = n;
    else if(n->key < key)
      node = find_in_subtree(n->right, key);
    else
      node = find_in_subtree(n->left, key);
  }

  return node;
}

node_t* find(bintree_t *bt, int key)
{
  node_t *n = NULL;

  if(bt && bt->head)
    n = find_in_subtree(bt->head, key);

  return n;
}

void print_node(node_t *n)
{
  if(n)
    printf("node: key(%d), value(\"%s\")\n", n->key, n->value);
  else
    printf("node: NULL\n");
}
