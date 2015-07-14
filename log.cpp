#include "log.h"

bool write_log(pOperate &OP,pCmm &cmd)
{
	FILE *fp=fopen("log.txt","a");
	switch (cmd->code)
	{
		case 0x0	: fprintf(fp,"%s\t打开文件%s\t%s\n",time,cmd->file_name,cmd->file_name); 			break;
		case 0x2	: fprintf(fp,"%s\t删除文件%s\t%s\n",time,cmd->file_name,cmd->file_name); 			break;
		case 0x3	: fprintf(fp,"%s\t删除分数%d\t%s\n",time,cmd->parameter_score_a,cmd->file_name); 	break;
		case 0x4	: fprintf(fp,"%s\t删除分数%d~%d\t%s\n",time,cmd->parameter_score_a,cmd->parameter_score_b,cmd->file_name); 	break;
		case 0x5	: fprintf(fp,"%s\t删除分数为%d的学生%s\t%s\n",time,cmd->parameter_score_a,cmd->parameter_stu,cmd->file_name);		break;
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
	fclose(fp);
}
