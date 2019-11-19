#include<iostream>
using namespace std;

class Base
{
public:	int m_b;
};
class Test :public Base
{
};

int main()
{
	try
	{
		int a;
		a = 5;
		throw a;
	}
	catch (int & e)
	{
		cout << e;
	}
	catch (float & e)
	{
		cout << e;
	}
	try
	{
		Test a;
		throw a;
	}
	catch (Base & e)
	{
		cout << e.m_b;
	}
	system("pausse");
	return 0;
}