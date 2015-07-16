#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED
#include "variable.h"

bool 	remove_link_node(pLink &L,char *str);
pLink 	find_link_node(pLink &L,char *str);
void 	print_link(pLink &L);
void 	free_link(pLink &L);
pLink 	find_link_node(pLink &L,char *str);
pLink 	build_link_node(char *&stu_id,char *&stu_name);
bool 	insert_link_node(pLink &L,pLink &e);

#include "link.cpp"
#endif // LINK_H_INCLUDED
