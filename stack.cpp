#include "stack.h"

bool stack_push(pStack &S,pBSTree &e)					///½øÕ»
{
	if(!e) return false;
	pStack s=(pStack)malloc(sizeof(Stack));
	s->data=e;
	s->next=NULL;
	if(!S)
	{
		S=(pStack)malloc(sizeof(Stack));
		S->next=s;
		S->stack_size=1;
	}
	else
	{
		s->next=S->next;
		S->next=s;
		S->stack_size++;
	}
	return true;
}

bool stack_pop(pStack &S,pBSTree &e)		///³öÕ»
{
	if(stack_empty(S)) return false;
	pStack p=S->next;
	e=p->data;
	S->next=S->next->next;
	S->stack_size--;
	free(p);
	return true;
}

bool print_stack(pStack &S)
{
	if(stack_empty(S)) return false;
	pStack p=S->next;
	while(p)
	{
		printf("%d ",p->data->score);
		p=p->next;
	}
	printf("\n");
	return true;
}

bool stack_empty(pStack &S)
{
	if(!S||0==S->stack_size)
		return true;
	else
		return false;
}

