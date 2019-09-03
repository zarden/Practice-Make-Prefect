#include<iostream>
using namespace std;

class Test2{

public:
	int b;
	
	explicit Test2(int a) :b(a)
	{}

	Test2(Test2 & t)
	{
		b = t.b;
	}	
};

class Test
{
public:
	int a = 5;

	const int i=3;

	int &ri;
	//auto  不行
	Test2 t2;

	Test(int &a) :i(3), ri(a),t2(a)//相当于初始化
	{}
};

int main1()
{
	int i = 8;
	int j = 9;
	Test2 a(i);
	Test2 b = a;

	Test2 c(j);

	cout << a.b << endl;//8
	cout << c.b << endl;//9

	system("pause");
	return 0;
}
