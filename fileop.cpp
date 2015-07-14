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
			fprintf(fp,"%d ",p->score);			///������д���ļ����ÿո�ָ�
			pLink r=p->next->next;				///��ʼ�������ڵ��е�����
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
    if(!get_file_name(file_name,file_na))	return false;			///������ļ����Ʋ���
    if(NULL==(fp=fopen(file_name,"r"))) return false;				///û���ҵ�.cj�ļ�
    unsigned int score;
    char ch,str1[10],str2[20];
    pBSTree tree_node=NULL;
    pLink link_node=NULL,L=NULL;
    while(!feof(fp))
	{
		fscanf(fp,"%d ",&score);
		if(feof(fp)) break;						///��ֹ����ס
		tree_node=build_tree_node(score);
		while(1)
		{
			fscanf(fp,"%s %s ",str1,str2);
			char *stu_id=str1,*stu_name=str2;
			link_node=build_link_node(stu_id,stu_name);
			insert_link_node(L,link_node);						///�Ѵ����õ�����ڵ�link_node���뵽����L��
            tree_node->stu_quantity++;
			ch=fgetc(fp);
			if('&'==ch) break;
		}
		tree_node->next=L;										///������L�����Ľڵ�Խ�
		L=NULL;													///�Խ���ɣ�Lָ��NULL������L��Խ��Խ��
		insert_tree_node(BST,tree_node);
	}
    fclose(fp);
	return true;
}

bool get_file_name(char*&file_name,char *file_na)
{
	char *suffix=strchr(file_na,'.');
	if(!suffix)										///������׺
	{
		file_name=(char*)malloc(sizeof(char)*strlen(file_na));
		strcpy(file_name,file_na);
		strcat(file_name,".cj");
		return true;
	}
	else if(!strcmp(suffix,".cj"))					///�ļ����Ѿ����к�׺.cj
	{
		free(file_name);
		file_name=(char*)malloc(sizeof(char)*strlen(file_na));
		return true;
	}
	else if(strcmp(suffix,".cj"))					///���Ʋ���
	{
		return false;
	}
}








