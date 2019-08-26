#include<iostream>
#include<typeinfo>
using namespace std;

int func1(int &a)
{
	return a;
}

inline int &func2(int &a)
{
	return a;
}

inline int* func3(int *pa)
{
	return pa;
}

int main()
{
	int a = 3;
	cout << func1(a) << endl;
	cout << (func2(a)=4) << endl;

	*func3(&a) = 5;
	system("pause");
	return 0;
}