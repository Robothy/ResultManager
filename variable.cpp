#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "iostream"
#include "Windows.h"

struct link
{
	char stu_id[10];
	char stu_name[20];
	struct link *next;
};

struct bstree
{
	unsigned int score;
	Link *stu;
	BSTree *lchild;
	BSTree *rchild;
};
