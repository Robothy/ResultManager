#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

pLink build_link_node(char *&stu_id,char *&stu_name);
bool insert_link_node(pLink &L,pLink &e);

#include "link.cpp"
#endif // LINK_H_INCLUDED
