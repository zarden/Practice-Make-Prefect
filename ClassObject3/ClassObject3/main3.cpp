#include<iostream>
using namespace std;

class TestSt{
public:
	int a;
	static int m_s_i;

	TestSt()
	{
		m_s_i++;
	}

	static void testst()
	{
		m_s_i = 4;
	}
};

int TestSt::m_s_i = 0;

int main()
{
	/* t1;
	cout << t1.m_s_i << endl;//1

	TestSt t2;
	cout << t1.m_s_i << endl;//2
	cout << t2.m_s_i << endl;//2

	TestSt t3;
	cout << t1.m_s_i << endl;//3
	cout << t2.m_s_i << endl;//3
	cout << t3.m_s_i << endl;//3
	*/

	TestSt::testst();
	cout << TestSt::m_s_i << endl;//4

	system("pause");
	return 0;
}