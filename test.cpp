#include "stdio.h"
#include <string.h>
#include <alloc.h>

#define str_test

/**************************************************
1.����
2.����
3.����ʽ�����봫��ַ������
4.����������
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



///��������
/*
void f1(int);
void f2(int&);

int main()
{
	int i=1,j=2;
	printf("���ú���f1֮ǰ��i=%d\n",i);
	f1(i);
	printf("���ú���f1֮��i=%d\n",i);

	printf("���ú���f2֮ǰ��j=%d\n",j);
	f2(j);
	printf("���ú���f2֮��j=%d\n",j);
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
