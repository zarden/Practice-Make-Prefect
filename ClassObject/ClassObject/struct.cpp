#include<stdio.h>
#include<stdlib.h>

struct A1
{
	int a;
	double b;//��СΪ16�ֽڣ����Ķ���
};

struct A2
{
};//��СΪ1�ֽ�


struct A3
{
	int a;
	double b;//��СΪ24�ֽ�
  	char c;

	void printA()
	{
		printf("%d\n", a);//��Ա�����п���ֱ��ʹ���Լ��ĳ�Ա����
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