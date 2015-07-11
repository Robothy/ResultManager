#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string.h"


using namespace std;

struct link
{
    char stu_id[11];
    char stu_name[20];
    struct link *next;
};

struct student
{
    char stu_id[10];
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



