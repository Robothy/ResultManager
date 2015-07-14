#include "stdio.h"
#include <string.h>
#include <alloc.h>

#define str_test

/**************************************************
1.函数
2.引用
3.传形式参数与传地址的区别
4.函数的声明
**************************************************/

#ifdef str_test


int main(void)
{
char *string1 = "abcdefghijklmnopqrstuvwxyz";
char *string2 = "onm";
char *ptr;
ptr = strpbrk(string1, string2);
if (ptr)
printf("strpbrk found first character: %c\n", *ptr);
else
printf("strpbrk didn't find character in set\n");
return 0;
}

#endif // str_test



///函数声明
/*
void f1(int);
void f2(int&);

int main()
{
	int i=1,j=2;
	printf("调用函数f1之前，i=%d\n",i);
	f1(i);
	printf("调用函数f1之后，i=%d\n",i);

	printf("调用函数f2之前，j=%d\n",j);
	f2(j);
	printf("调用函数f2之后，j=%d\n",j);
	return 0;
}

void f1(int m)
{
	m=100;
}

void f2(int &n)
{
	n=200;
}
*/
