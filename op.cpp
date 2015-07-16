#include "op.h"

bool operate_init(pOperate &OP)
{
	if(!OP)
	OP = (pOperate)malloc(sizeof(Operate));
	OP->BST = NULL;
	OP->is_op_file=false;
	OP->count_insert_score=0;
	OP->count_insert_stu=0;
	OP->count_rm_score=0;
	OP->count_rm_stu=0;
	strcpy(OP->file_name,"error!");
	return true;
}

pCmm get_command(pOperate &OP)
{
	print_head(OP);
	char cmd_str[40];				///用来接收命令字符串
	gets(cmd_str);					///获取命令
	if(!strlen(cmd_str)) strcpy(cmd_str," ");
	unsigned int i=0,k=0;
	unsigned int count_str_num=0;	///统计命令的数量
	char key_word[5][20];
	pCmm cmd=NULL;
	cmd_init(cmd);
	strcpy(cmd->cmd_str,cmd_str);
	if(count_char(cmd_str,' ')>4)	return cmd;
	while('\0'!=cmd_str[i])
	{
		if(' '==cmd_str[i])
		{
			key_word[count_str_num][k]='\0';
			count_str_num++;
			k=0;
		}
		else
		{
			key_word[count_str_num][k]=cmd_str[i];
			k++;
		}
		i++;
	}
	key_word[count_str_num][k]='\0';
	count_str_num++;
    if(!(OP->is_op_file))		///没有打开文件
    {
    	if(!strcmp("open",key_word[0]))
		{
			cmd->code=0x0;
			strcpy(cmd->file_name,key_word[1]);
		}
    	else if(!strcmp("rm",key_word[0])&&2==count_str_num)
		{
			cmd->code=0x2;
			strcpy(cmd->file_name,key_word[1]);
		}
		else cmd->code=0xd;
    }
    else
	{
    	if(1==count_str_num)	///命令长度为1
		{
			if(!strcmp("commit",key_word[0])) cmd->code=0xf;
		}
		else if(2==count_str_num)///命令长度为2
		{
			if(!strcmp("open",key_word[0]))	///open
			{
				cmd->code=0x0;
				strcpy(cmd->file_name,key_word[1]);
			}
			else if(!strcmp("rm",key_word[0]))
			{
				cmd->code=0x2;
				strcpy(cmd->file_name,key_word[1]);
			}
			else cmd->code=0xd;
		}
		else if(3==count_str_num)	///命令长度为3
		{
			if(!strcmp("rm",key_word[0]))///rm
			{
				if(!strcmp("score",key_word[1]))///rm score <score>
				{
					cmd->code=0x3;
					cmd->parameter_score_a=str_to_int(key_word[2]);
				}
				else if(!strcmp("student",key_word[1]))///rm student <id|name>
				{
					cmd->code=0x6;
					strcpy(cmd->parameter_stu,key_word[2]);
				}
			}
			else if(!strcmp("find",key_word[0]))
			{
				if(!strcmp("score",key_word[1]))	///find score <score>
				{
					cmd->code=0x7;
					cmd->parameter_score_a=str_to_int(key_word[2]);
				}
				else if(!strcmp("student",key_word[1]))	///find student <id|name>
				{
					cmd->code=0xa;
					strcpy(cmd->parameter_stu,key_word[2]);
				}
				else cmd->code=0xd;
			}
			else if(!strcmp("insert",key_word[0]))	///insert score <score>
			{
				if(!strcmp("score",key_word[1]))
				{
					cmd->code=0xb;
					cmd->parameter_score_a=str_to_int(key_word[2]);
				}
				else cmd->code=0xd;
			}
			else cmd->code=0xd;
		}
		else if(4==count_str_num)
		{
			if(!strcmp("rm",key_word[0]))///rm
			{
				if(!strcmp("score",key_word[1]))///rm score <score> <score>
				{
					cmd->code=0x4;
					cmd->parameter_score_a=str_to_int(key_word[2]);
					cmd->parameter_score_b=str_to_int(key_word[3]);
				}
				else if(!strcmp("student",key_word[1]))///rm student <id|name> <score>
				{
					cmd->code=0x5;
					strcpy(cmd->parameter_stu,key_word[2]);
					cmd->parameter_score_a=str_to_int(key_word[3]);
				}
				else cmd->code=0xd;
			}
			else if(!strcmp("find",key_word[0]))
			{
				if(!strcmp("score",key_word[1]))	///find score <score> <score>
				{
					cmd->code=0x8;
					cmd->parameter_score_a=str_to_int(key_word[2]);
					cmd->parameter_score_b=str_to_int(key_word[3]);
				}
				else if(!strcmp("student",key_word[1]))	///find student <id|name> <score>
				{
					cmd->code=0x9;
					strcpy(cmd->parameter_stu,key_word[2]);
					cmd->parameter_score_a=str_to_int(key_word[3]);
				}
				else cmd->code=0xd;
			}
			else cmd->code=0xd;
		}
		else if(5==count_str_num)
		{
			if(!strcmp("insert",key_word[0])&&!strcmp("student",key_word[1]))	///insert student <stu_id> <stu_name> <score>
			{
				cmd->code=0xc;
				strcpy(cmd->parameter_stu_id,key_word[2]);
				strcpy(cmd->parameter_stu_name,key_word[3]);
				cmd->parameter_score_a=str_to_int(key_word[4]);
			}
			else cmd->code=0xd;
		}
		else cmd->code=0xd;
	}
	return cmd;
}

bool print_head(pOperate &OP)
{
	printf("\nUser");
	pOperate p=OP;
	if(p->is_op_file)	///正在对一个文件进行操作
	{
		printf("\\%s",OP->file_name);
		printf("(%d,%d,%d,%d)",OP->count_insert_score,OP->count_insert_stu,OP->count_rm_score,OP->count_rm_stu);
	}
	printf(">");
	return true;
}

unsigned int count_char(char*str,char ch)
{
	unsigned int str_len = strlen(str),count_=0;
	for(int i=0;i<str_len;i++)
	{
		if(ch==*(str+i)) count_++;
	}
	return count_;
}

unsigned int str_to_int(char*str)
{
	unsigned int len=strlen(str);
	unsigned int sum=0;
	for(int i=0;i<len;i++)
	{
		sum+=((unsigned int)*(str+i)-48)*(unsigned int)pow(10,len-i-1);
	}
	return sum;
}

bool cmd_init(pCmm &cmd)
{
	cmd=(pCmm)malloc(sizeof(Cmm));
	strcpy(cmd->cmd_str," ");
	strcpy(cmd->file_name," ");
	strcpy(cmd->parameter_stu," ");
	strcpy(cmd->parameter_stu_id," ");
	strcpy(cmd->parameter_stu_name," ");
	cmd->code=0xd;
	cmd->parameter_score_a=101;
	cmd->parameter_score_b=101;
	return true;
}

bool show_cmd_msg(pCmm &cmd)
{
	printf("cmdstr=%s\n",cmd->cmd_str);
	printf("code=%x\n",cmd->code);
	printf("file_name,%s\n",cmd->file_name);
	printf("score_a=%d\n",cmd->parameter_score_a);
	printf("score_b=%d\n",cmd->parameter_score_b);
	printf("stu=%s\n",cmd->parameter_stu);
	printf("stu_id=%s\n",cmd->parameter_stu_id);
	printf("stu_name=%s\n",cmd->parameter_stu_name);
}

bool open_file(pOperate &OP,pCmm &cmd)
{
	operate_init(OP);
	if(!open_report_card(OP->BST,cmd->file_name))			///创建新文件
	{
		char *file_name=(char*)malloc(20*sizeof(char));
		get_file_name(file_name,cmd->file_name);
        FILE *fp=fopen(file_name,"w");
        fclose(fp);
        open_report_card(OP->BST,cmd->file_name);
	}
	OP->is_op_file=true;
	strcpy(OP->file_name,cmd->file_name);
	return true;
}

bool rm_a_score(pOperate &OP,pCmm &cmd)
{
	pBSTree p = find_tree_node(OP->BST,cmd->parameter_score_a);
	if(p)
	{
		OP->count_rm_stu+=p->stu_quantity;
		if(remove_tree_node(OP->BST,cmd->parameter_score_a))
		{
			OP->count_rm_score++;
			return true;
		}
	}

	else return false;
}

bool save_file(pOperate &OP,pCmm &cmd)
{
	if(0!=OP->count_insert_score+OP->count_insert_stu+OP->count_rm_score+OP->count_rm_stu)
	{
		save_report_card(OP->BST,OP->file_name);
		OP->count_insert_score=0;
		OP->count_insert_stu=0;
		OP->count_rm_score=0;
		OP->count_rm_stu=0;
		return true;
	}
	return false;
}

bool rm_some_score(pOperate &OP,pCmm &cmd)
{
    if(!(OP->BST)) return false;
    pStack S=NULL;
    pBSTree p=OP->BST,q=NULL;
    unsigned int min_score=cmd->parameter_score_a;
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
			if(p->score<=cmd->parameter_score_b&&p->score>=min_score)
			{
				cmd->parameter_score_a=p->score;
				rm_a_score(OP,cmd);
			}
			p=p->rchild;
		}
	}
}

void rm_a_stu_score(pOperate &OP,pCmm &cmd)
{
    pBSTree NODE=NULL;
    if((NODE=find_tree_node(OP->BST,cmd->parameter_score_a))!=NULL)
    if(remove_link_node(NODE->next,cmd->parameter_stu))
	{
		NODE->stu_quantity--;
		OP->count_rm_stu++;
	}
}

bool remove_file(pOperate &OP,pCmm &cmd)
{
    char str[30];
    char *file_name=(char*)malloc(sizeof(char)*20);
    strcpy(str,"del ");
    get_file_name(file_name,cmd->file_name);
    strcat(str,file_name);
    if(-1==system(str)) return false;
    else return true;
}

bool rm_a_student(pOperate &OP,pCmm &cmd)
{
    if(!(OP->BST)) return false;
    pStack S=NULL;
    pBSTree p=OP->BST,q=NULL;
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
			cmd->parameter_score_a=p->score;
			rm_a_stu_score(OP,cmd);
			p=p->rchild;
		}
	}
	return true;
}

bool find_a_score(pOperate &OP,pCmm &cmd)
{
	pBSTree NODE=NULL;
	if(NULL==(NODE=find_tree_node(OP->BST,cmd->parameter_score_a))) return false;
	print_link(NODE->next);
	printf("score = %d , total = %d\n\n",cmd->parameter_score_a,NODE->stu_quantity);
	return true;
}

bool find_some_score(pOperate &OP,pCmm &cmd)
{
    if(!(OP->BST)) return false;
    pStack S=NULL;
    pBSTree p=OP->BST,q=NULL;
    unsigned int count_line=0,min_score=cmd->parameter_score_a;
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
			if(min_score<=p->score&&cmd->parameter_score_b>=p->score)
			{
				cmd->parameter_score_a=p->score;
				find_a_score(OP,cmd);
				count_line+=p->stu_quantity;
			}
			p=p->rchild;
		}
	}
	printf("score between %d and %d\t",min_score,cmd->parameter_score_b);
	printf("Summary = %d\n",count_line);
	return true;
}

bool find_a_stu_score(pOperate &OP,pCmm &cmd)
{
    pBSTree NODE=NULL;
    pLink p=NULL;
    bool is_finded=false;
    if((NODE=find_tree_node(OP->BST,cmd->parameter_score_a))!=NULL)
	{
		if(!(NODE->next)) return false;
		pLink p=NODE->next->next;
		while(p)
		{
			if(!strcmp(cmd->parameter_stu,p->stu_id)||!strcmp(cmd->parameter_stu,p->stu_name))
			{
				printf("score = %d\t%s\t%s\n",cmd->parameter_score_a,p->stu_id,p->stu_name);
				is_finded=true;
			}
			p=p->next;
		}
	}
	return is_finded;
}

bool find_a_student(pOperate &OP,pCmm &cmd)
{
    if(!OP->BST) return false;
    pStack S=NULL;
    pBSTree p=OP->BST,q=NULL;
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
			cmd->parameter_score_a=p->score;
            find_a_stu_score(OP,cmd);
			p=p->rchild;
		}
	}
}

bool insert_a_score(pOperate &OP,pCmm &cmd)
{
	pBSTree tree_node=NULL;
	if(NULL!=(tree_node=build_tree_node(cmd->parameter_score_a)))
	if(insert_tree_node(OP->BST,tree_node))
	{
		OP->count_insert_score++;
		return true;
	}
	return false;
}

bool insert_a_stu_score(pOperate &OP,pCmm &cmd)
{
	pBSTree NODE=NULL;
	char *stu_id=cmd->parameter_stu_id,*stu_name=cmd->parameter_stu_name;
	pLink link_node=build_link_node(stu_id,stu_name);
    insert_a_score(OP,cmd);
    NODE=find_tree_node(OP->BST,cmd->parameter_score_a);
    if(insert_link_node(NODE->next,link_node))
	{
		NODE->stu_quantity++;
		OP->count_insert_stu++;
	}
    return true;
}


void print_welcome(void)
{
	system("cls");
	printf("The Student Result Management [Version 1.0]\n");
	printf("Copyright (c) 2015 1312441117 罗福享\n");
}

