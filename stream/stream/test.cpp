#include<iostream>
#include<sstream>
using namespace std;

void T1()
{
	stringstream st;
	float s;

	st << 1.23;
	st >> s;
	cout << s;
	//str()�������ܷ�����ָ����ֵ���ʽ��Ӧ���ַ���
}

int main()
{
	T1();
	system("pause");
	return 0;
}