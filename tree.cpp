#include "tree.h"

bool insert_tree_node(pBSTree &BST,pBSTree &NODE)
{
    if(!NODE) return false;
    NODE->lchild=NULL;
    NODE->rchild=NULL;
    if(!BST) BST = NODE;
    else
    {
        pBSTree p = BST,q = BST;
        while(p)
        {
            q=p;
            if(NODE->score<p->score)
            {
                p=p->lchild;
            }
            else if(NODE->score>p->score)
            {
                p=p->rchild;
            }
            else return false;
        }
        if(NODE->score<q->score)
        {
            q->lchild = NODE;
        }
        else
        {
            q->rchild = NODE;
        }
    }
    return true;
}


///根据分数删除树的一个节点
bool remove_tree_node(pBSTree &BST,unsigned int score)
{
	if(!BST) return false;
	else
	{
		pBSTree p=BST,q=p;
		while(p&&score!=p->score)
		{
			q=p;
			if(score>p->score) p=p->rchild;
			else p=p->lchild;
		}
		if(!p) return false;
		else
		{
			if(!(p->lchild)&&!(p->rchild))			///找到的为叶子节点
			{
				if(score>q->score) q->rchild=NULL;
				else q->lchild=NULL;
			}
			else
			{
				if(!(p->rchild))					///要删除节点的右子树为空
				{
					if(p==q)
					{
						BST=BST->lchild;
					}
					else
					{
						if(score>q->score) q->rchild=p->lchild;
						else q->lchild=p->lchild;
					}
				}
				else								///要删除节点的右子树不为空
				{
					pBSTree r=p,s=q;
					pBSTree m=r->rchild,n=r;

					while(m->lchild)
					{
						n=m;
						m=m->lchild;
					}

					if(n==r) n->rchild=m->rchild;
					else n->lchild=m->rchild;

					m->lchild=p->lchild;
					m->rchild=p->rchild;

					if(p==q) BST=m;
					else
					{
						if(score>q->score) q->rchild=m;
						else q->lchild=m;
					}
				}
			}
			free_link(p->next);					///释放p中链表的内存
			free(p);
			return true;
		}
	}
}

pBSTree find_tree_node(pBSTree &BST,unsigned int score)
{
	if(!BST) return NULL;
	else
	{
		pBSTree p=BST;
		while(p)
		{
			if(score>p->score)	p=p->rchild;
			else if(score<p->score) p=p->lchild;
			else break;
		}
		return p;
	}
}

void pre_order_tree(pBSTree &BST)
{
    if(!BST) return;
    pStack S=NULL;
    pBSTree p=BST,q=NULL;
    while(p||!stack_empty(S))
	{
		while(p)
		{
			q=p;
			printf("%d ",p->score);
			stack_push(S,p);
			p=p->lchild;
		}
		if(!stack_empty(S))
		{
			stack_pop(S,p);
			p=p->rchild;
		}
	}
	printf("\n");
}

void mid_order_tree(pBSTree &BST)
{
    if(!BST) return;
    pStack S=NULL;
    pBSTree p=BST,q=NULL;
    while(p||!stack_empty(S))
	{
		while(p)
		{
			q=p;
			stack_push(S,p);
			p=p->lchild;
		}
		if(!stack_empty(S))
		{
			stack_pop(S,p);
			printf("%d ",p->score);
			p=p->rchild;
		}
	}
	printf("\n");
}

pBSTree build_tree_node(unsigned int score)
{
	pBSTree NODE=(pBSTree)malloc(sizeof(BSTree));
	NODE->score=score;
	NODE->lchild=NULL;
	NODE->rchild=NULL;
	NODE->next=(pLink)malloc(sizeof(Link));
	NODE->next->next=NULL;
	NODE->stu_quantity=0;
	return NODE;
}

bool free_tree(pBSTree &BST)
{
	pBSTree p=BST;
	if(!p) return true;
	free_tree(BST->lchild);
	free_tree(BST->rchild);
	free(p);
	BST=NULL;
	return true;
}
