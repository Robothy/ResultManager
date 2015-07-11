#include "variable.h"

///往链表中插入节点，按照学生学号排序
bool insert_link_node(pLink &L,pLink &e)
{
	if(!e) return false;
	e->next=NULL;
    if(!L)
	{
		L=(pLink)malloc(sizeof(Link));
		strcpy(L->stu_id,"0");
		L->next=e;
	}
	else
	{
	 	pLink q=L,p=L->next;
		while(p)
		{
			if(strcmp(p->stu_id,e->stu_id)>0&&strcmp(e->stu_id,q->stu_id)>0)
			{
				break;
			}
			q=p;
			p=p->next;
		}
		e->next=p;
		q->next=e;
		return true;
	}
}

///根据学生姓名或者学生学号删除一个链结
bool remove_link_node(pLink &L,char *str)
{
    if(!L) return false;
    pLink q=L,p=L->next;
    while(p)
	{
		if(!(strcmp(str,p->stu_id))||!(strcmp(str,p->stu_name)))
		{
			break;
		}
		q=p;
		p=p->next;
	}
	if(!p) return false;
	q->next=p->next;
	free(p);
	return true;
}

///打印整个链表
void print_link(pLink &L)
{
    if(!L) return;
    pLink p=L->next;
    unsigned int i=0;
    printf("\nrow_num\tstudent_id\tstudent_name\n");
    printf("-------\t----------\t-------------------\n");
    while(p)
	{
		i++;
		printf("%d\t%s\t%s\n",i,p->stu_id,p->stu_name);
		p=p->next;
	}
}

///释放单链表中的内存
void free_link(pLink &L)
{
	pLink p=L,q=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
}




