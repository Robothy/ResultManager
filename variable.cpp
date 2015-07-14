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
	bool is_op_file;							///是否正在对一个文件进行操作
	char file_name[20];							///操作的文件名称
	unsigned int count_rm_stu;					///统计删除的链表的节点的个数
	unsigned int count_rm_score;				///统计删除的树的节点的个数
	unsigned int count_insert_stu;				///统计插入的链表的个数
	unsigned int count_insert_score;			///统计插入的树的节点的个数
	struct bstree *BST;							///打开的文件创建树
};


struct cmm
{
	char file_name[30];
	char parameter_stu[20];						///学生学号或姓名
	char parameter_stu_id[11],parameter_stu_name[20];	///学生学号，学生姓名
	unsigned int parameter_score_a,parameter_score_b;	///两个分数
	unsigned int code;			///表示代码
	char cmd_str[40];
};



