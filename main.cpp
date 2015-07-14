#include "main.h"

//#include "stdio.h"

#define test_op
//#define test_bstree
//#define test_fileop

int main(void)
{
#ifdef test_op
pOperate OP=NULL;		///会话开始,定义标志变量
operate_init(OP);		///初始化标志变量
pCmm cmd=NULL;

while(1)
{
	cmd=get_command(OP);
	switch (cmd->code)
	{
		case 0x0	: if(open_file(OP,cmd)); 			break;
		case 0x2	: remove_file(OP,cmd); 			break;
		case 0x3	: rm_a_score(OP,cmd); 			break;
		case 0x4	: rm_some_score(OP,cmd); 		break;
		case 0x5	: rm_a_stu_score(OP,cmd);		break;
		case 0x6	: rm_a_student(OP,cmd); 		break;
		case 0x7	: find_a_score(OP,cmd); 		break;
		case 0x8	: find_some_score(OP,cmd); 		break;
		case 0x9	: find_a_stu_score(OP,cmd); 	break;
		case 0xa	: find_a_student(OP,cmd); 		break;
		case 0xb	: insert_a_score(OP,cmd); 		break;
		case 0xc	: insert_a_stu_score(OP,cmd); 	break;
		case 0xd	: system(cmd->cmd_str); 		break;
		case 0xf	: save_file(OP,cmd); 			break;
		default		: printf("未知！\n");
	}
	free(cmd);
}
#endif // test_op



#ifdef test_bstree
pBSTree BST=NULL;
#endif // test_bstree

#ifdef test_fileop

//save_report_card(BST,"ke");
open_report_card(BST,"db");

pre_order_tree(BST);

save_report_card(BST,"kk");
//get_file_name("hellwo.cj");

#endif // test_fileop

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


