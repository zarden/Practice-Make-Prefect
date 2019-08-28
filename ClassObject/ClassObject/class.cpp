#include<iostream>
using namespace std;

class ct
{
	int a;
public:
	double b;
	char c;

	void test()
	{

	}

	void changeA(int i)
	{
		a = i;
	}

	void printA()
	{
		printf("%d\n", a);//成员函数中可以直接使用自己的成员变量
	}
protected:
	void printB();
};

void ct::printB()
{
	printf("%.2lf\n", b);
}


int main()
{
	ct c;
	ct d;
	ct *pc = nullptr;
	//c.a = 4;
	c.changeA(5);
	c.printA();

	d.changeA(6);
	d.printA();

	pc->test();

	cout << sizeof(ct) << endl;

	system("pause");
	return 0;
}