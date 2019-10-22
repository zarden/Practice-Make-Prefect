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
	//str()函数功能返回与指定数值表达式对应的字符。
}

int main()
{
	T1();
	system("pause");
	return 0;
}