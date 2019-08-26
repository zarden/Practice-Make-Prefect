#include<iostream>
using namespace std;

int &Add(int a, int b)
{
	int c = a + b;
	return c;
}

int _0main()
{
	int &ret = Add(1, 2);//ret理论上是一个随机值，但由于连续调用两次，所以为7
	Add(3, 4);
	cout << "Add(1,2) is:" << ret << endl;
	return 0;
}

struct A
{
	int a[100000];
};

void test1(A &a)
{

}

void test2(A a)
{

}

int _main()
{
	A a;
	for (int i = 0; i < 100000; i++)
	{
		test1(a);
	}
	return 0;
}