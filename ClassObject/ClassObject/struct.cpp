#include<stdio.h>
#include<stdlib.h>

struct A1
{
	int a;
	double b;//大小为16字节，向大的对齐
};

struct A2
{
};//大小为1字节


struct A3
{
	int a;
	double b;//大小为24字节
  	char c;

	void printA()
	{
		printf("%d\n", a);//成员函数中可以直接使用自己的成员变量
	}

	void printB();
};

void A3::printB()
{
	printf("%.2lf\n", b);
}

int main()
{
	printf("%d %d %d\n", sizeof(A1), sizeof(A2), sizeof(A3));
	A3 test;
	printf("%p %p %p\n %p\n", &test.a, &test.b, &test.c, &test);

	test.a = 5;
	test.printA();
	test.b = 3.14;
	test.printB();
	system("pause");
	return 0;
}