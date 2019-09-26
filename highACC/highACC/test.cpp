#include<iostream>
#include"highACC.h"
using namespace std;

int main()
{
	string s1("12");
	string s2("45");

	highACC num1(s1);
	highACC num2(s2);

	cout<<(string)(num1 * num2);



	system("pause");
	return 0;
}