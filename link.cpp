#include "variable.h"

///�������в���ڵ㣬����ѧ��ѧ������
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

///����ѧ����������ѧ��ѧ��ɾ��һ������
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

pLink find_link_node(pLink &L,char *str)
{
	if(!L) return NULL;
	pLink p=L->next;
	while(p)
	{
		if(!strcmp(str,p->stu_id)||!strcmp(str,p->stu_name)) break;
		p=p->next;
	}
	return p;
}

///��ӡ��������
void print_link(pLink &L)
{
    if(!L) return;
    pLink p=L->next;
    while(p)
	{
		printf("%s\t%s\n",p->stu_id,p->stu_name);
		p=p->next;
	}
}

///�ͷŵ������е��ڴ�
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

pLink build_link_node(char *&stu_id,char *&stu_name)
{
	pLink link_node=(pLink)malloc(sizeof(Link));
	strcpy(link_node->stu_id,stu_id);
	strcpy(link_node->stu_name,stu_name);
	link_node->next=NULL;
	return link_node;
}



