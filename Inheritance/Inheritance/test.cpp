#include<iostream>
using namespace std;

class TestBase
{
public:
	int m_a;

	TestBase(int i) :
		m_a(i)
	{

	}

	void func(int i)
	{
		cout << "���Ǹ���ĺ���" << endl;
	}
};

class Test:public TestBase
{
public:
	int m_a;
	Test(int a, int b) ://����Ķ����ʱ��Ҫ�͸������������������
		TestBase(a),
		m_a(b)
	{

	}

	void func()
	{
		cout << TestBase::m_a << endl;;
		cout << "��������ĺ���" << endl;
	}
};


int main()
{
#if 0
	Test t(5,6);
	t.func();
#else
	Test *pt = new Test(5, 6);
	TestBase *ptb = pt;

	
	//cout << pt->m_a<<endl;
	//cout << ptb->m_a << endl;

	pt->func();
	ptb->func(1);

	system("pause");
#endif
	return 0;
}