#include <stdio.h>
#include <stdlib.h>
#include "Arvore_B.h"
/*
int main(void) {
  int ch; // val;

  insert(8);
  insert(9);
  insert(10);
  insert(11);
  insert(15);
  insert(16);
  insert(17);
  insert(18);
  insert(20);
  insert(23);

  traversal(root);

  printf("\n");
  search(11, &ch, root);

  return(0);
} */

int main(void) {
  //int item, ch;

  insertion(8);
  insertion(9);
  insertion(10);
  insertion(11);
  insertion(15);
  insertion(16);
  insertion(17);
  insertion(18);
  insertion(20);
  insertion(23);

  traversal(root);

  delete (20, root);
  delete (23, root);
  printf("\n");
  traversal(root);

  return(0);
}
