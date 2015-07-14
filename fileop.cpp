#include "fileop.h"

bool save_report_card(pBSTree &BST,char *file_na)
{
    if(!BST) return false;

    char *file_name;
    if(!get_file_name(file_name,file_na)) return false;

    FILE *fp=NULL;
    if((fp=fopen(file_name,"w"))==NULL) return false;
    pStack S=NULL;
    pBSTree p=BST,q=NULL;
    while(p||!stack_empty(S))
	{
		while(p)
		{
			q=p;
			fprintf(fp,"%d ",p->score);			///将分数写入文件，用空格分割
			pLink r=p->next->next;				///开始访问树节点中的链表
			while(r)
			{
				fprintf(fp,"%s %s ",r->stu_id,r->stu_name);
				r=r->next;
				if(r) fprintf(fp,"|");
				else fprintf(fp,"&");
			}
			fprintf(fp,"\n");
			stack_push(S,p);
			p=p->lchild;
		}
		if(!stack_empty(S))
		{
			stack_pop(S,p);
			p=p->rchild;
		}
	}
	fclose(fp);
	return true;
}



bool open_report_card(pBSTree &BST,char *file_na)
{
    free_tree(BST);
    FILE *fp=NULL;
    char  *file_name;
    if(!get_file_name(file_name,file_na))	return false;			///输入的文件名称不对
    if(NULL==(fp=fopen(file_name,"r"))) return false;				///没有找到.cj文件
    unsigned int score;
    char ch,str1[10],str2[20];
    pBSTree tree_node=NULL;
    pLink link_node=NULL,L=NULL;
    while(!feof(fp))
	{
		fscanf(fp,"%d ",&score);
		if(feof(fp)) break;						///防止程序卡住
		tree_node=build_tree_node(score);
		while(1)
		{
			fscanf(fp,"%s %s ",str1,str2);
			char *stu_id=str1,*stu_name=str2;
			link_node=build_link_node(stu_id,stu_name);
			insert_link_node(L,link_node);						///把创建好的链表节点link_node插入到链表L中
            tree_node->stu_quantity++;
			ch=fgetc(fp);
			if('&'==ch) break;
		}
		tree_node->next=L;										///把链表L与树的节点对接
		L=NULL;													///对接完成，L指向NULL，否则L会越来越长
		insert_tree_node(BST,tree_node);
	}
    fclose(fp);
	return true;
}

bool get_file_name(char*&file_name,char *file_na)
{
	char *suffix=strchr(file_na,'.');
	if(!suffix)										///不带后缀
	{
		file_name=(char*)malloc(sizeof(char)*strlen(file_na));
		strcpy(file_name,file_na);
		strcat(file_name,".cj");
		return true;
	}
	else if(!strcmp(suffix,".cj"))					///文件名已经带有后缀.cj
	{
		free(file_name);
		file_name=(char*)malloc(sizeof(char)*strlen(file_na));
		return true;
	}
	else if(strcmp(suffix,".cj"))					///名称不对
	{
		return false;
	}
}








