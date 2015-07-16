#ifndef SATCK_H_INCLUDED
#define SATCK_H_INCLUDED

#include "variable.h"

bool stack_push(pStack &S,pBSTree &e);
bool stack_pop(pStack &S,pBSTree &e);
bool print_stack(pStack &S);
bool stack_empty(pStack &S);



#include "stack.cpp"

#endif // SATCK_H_INCLUDED
