#include<iostream>
using namespace std;

class Testtop{
public:
	int m_a;
	int m_b;

	Testtop() :
		m_a(0),
		m_b(0)
	{

	}

	Testtop(int a, int b):
		m_a(a),
		m_b(b)
	{

	}

	void test1(int a, int b)
	{
		test2(2, 4);
	}

	void test2(int a, int b) const
	{
		//test1(2, 4);
	}

	Testtop operator+(const Testtop &s) const
	{
		Testtop res;

		res.m_a = m_a + s.m_a;
		res.m_b = m_b + s.m_b;

		return res;
	}

	Testtop & operator =(const Testtop & s)
	{
		m_a = s.m_a;
		m_b = s.m_b;

		return *this;
	}
};

int main2()
{
	Testtop a(3, 5);
	Testtop b(2, 7);

	Testtop c;
	const Testtop d;
	c = c = a + b;

	cout << c.m_a << ' ' << c.m_b << endl;//5   12
	system("pause");
	return 0;
}