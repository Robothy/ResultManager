#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "variable.h"
#include "link.h"
#include "stack.h"

bool 		insert_tree_node(pBSTree &BST,pBSTree &NODE);
void 		Tree_Init(pBSTree &BST);
bool 		remove_tree_node(pBSTree &BST,unsigned int score);
pBSTree 	find_tree_node(pBSTree &BST,unsigned int score);
void 		pre_order_tree(pBSTree &BST);
void 		mid_order_tree(pBSTree &BST);
pBSTree 	build_tree_node(unsigned int score);

#include "tree.cpp"


#endif // TREE_H_INCLUDED
