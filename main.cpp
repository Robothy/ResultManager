#include "main.h"

int main(void)
{
pOperate OP=NULL;		///会话开始,定义标志变量
operate_init(OP);		///初始化标志变量
pCmm cmd=NULL;
print_welcome();
while(1)
{
	cmd=get_command(OP);
	switch (cmd->code)
	{
		case 0x0	: if(open_file(OP,cmd)); 		break;
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
		case 0xd	: if(!strcmp("exit",cmd->cmd_str)) exit(0);
						system(cmd->cmd_str); 		break;
		case 0xf	: save_file(OP,cmd); 			break;
		default		: printf("未知命令\n");			break;
	}
	free(cmd);
}
    return 0;
}


