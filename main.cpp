#include "main.h"

#define test_bstree

int main(void)
{


#ifdef test_bstree
pBSTree BST=NULL;
Tree_Init(BST);
pre_order_tree(BST);
mid_order_tree(BST);
#endif // test_bstree

#ifdef test_link
	char id[][10]={"312441110","312441111","312441010","312440911","312441119","312441108"};
	char name[][20]={"zzhangsan","lisi","wangdacui","xiaoming","zhaosi","luofuxiang"};
#endif // test_link

#ifdef test_stack
	pStack S=NULL;
	pBSTree e=NULL;

	unsigned int sc[]={34,123,43,1,4,25,23,76,89};
	for(int i=0;i<9;i++)
	{
		e=(pBSTree)malloc(sizeof(BSTree));
		e->score=sc[i];
		stack_push(S,e);
	}
	system("pause");
	print_stack(S);
	stack_pop(S,e);
	print_stack(S);
#endif // test_stack
    return 0;
}
