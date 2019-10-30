#include<iostream>
using namespace std;

class Base
{
public:
	int m_i;
	virtual void func1()
	{
		cout << "Base::func1" << endl;
	}
};

class TestBase :virtual public Base
{
public:
	int m_a = 3;
	virtual void func1()
	{
		cout << "TestBase::func1" << endl;
	}
};

class TestBase2 :virtual public Base
{
public:
	int m_b = 2;
	virtual void func1()
	{
		cout << "TestBase2::func1" << endl;
	}
};

class Test:public TestBase,public TestBase2
{
public:
	virtual void func1()
	{
		cout << "Test::func1" << endl;
	}

};

int main()
{
	Test t;
	t.func1();//Test::func1
	Base *pb = &t;
	TestBase * ptb = &t;
	TestBase2 * ptb2 = &t;
	pb->func1(); //Test::func1
	ptb->func1();//Test::func1
	ptb2->func1();//Test::func1

	system("pause");
	return 0;
}