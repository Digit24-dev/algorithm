#include <stdio.h>
#include <stdlib.h>

int f2(int x);

int a=10;
int b;
int a2=20;
int b2;

int f1(int x)
{
	return ++x;
}

int main()
{
	int c=100, c2;
	char *d = "hello";
	char *name;
	int *score;
	
	printf("Main Start!!\n");
	c2 = f1(10);
	printf("ret_f1():%d\n", c2);
	c2 = f2(10);
	printf("ret_f2():%d\n", c2);
	name = malloc(50);
	score = malloc(20*sizeof(int));
	printf("%s\n", d);
	printf("addr(TEXT)=> main:%p, f1:%p, f2:%p\n", main, f1, f2);
	printf("addr(CONST)=> d:%p\n", d);
	printf("addr(DATA)=> a:%p, a2:%p\n", &a, &a2);
	printf("addr(BSS)=> b:%p, b2:%p\n", &b, &b2);
	printf("addr(STACK)=> c:%p, c2:%p\n", &c, &c2);
	printf("addr(HEAP)=> name:%p, score:%p\n", name, score);

	return 0;
}

int f2(int x)
{
	return --x;
}