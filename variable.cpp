#include "variable.h"


using namespace std;

struct link
{
    char stu_id[11];
    char stu_name[20];
    struct link *next;
};

struct student
{
    char stu_id[11];
    char stu_name[20];
    unsigned int score;
};

struct bstree
{
    unsigned int score,stu_quantity;
    struct bstree *lchild;
    struct bstree *rchild;
    struct link *next;
};

struct STACK
{
	struct bstree *data;
	unsigned int stack_size;
	struct STACK *next;
};

struct operate
{
	bool is_op_file;							///�Ƿ����ڶ�һ���ļ����в���
	char file_name[20];							///�������ļ�����
	unsigned int count_rm_stu;					///ͳ��ɾ��������Ľڵ�ĸ���
	unsigned int count_rm_score;				///ͳ��ɾ�������Ľڵ�ĸ���
	unsigned int count_insert_stu;				///ͳ�Ʋ��������ĸ���
	unsigned int count_insert_score;			///ͳ�Ʋ�������Ľڵ�ĸ���
	struct bstree *BST;							///�򿪵��ļ�������
};


struct cmm
{
	char file_name[30];
	char parameter_stu[20];						///ѧ��ѧ�Ż�����
	char parameter_stu_id[11],parameter_stu_name[20];	///ѧ��ѧ�ţ�ѧ������
	unsigned int parameter_score_a,parameter_score_b;	///��������
	unsigned int code;			///��ʾ����
	char cmd_str[40];
};



