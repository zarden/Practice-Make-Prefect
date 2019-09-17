#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1("xiao zhu pai pei pai");
	string s2("pei pei");
	string s3("pei qi");

	int pos = s1.find('p');
	cout << s1.find('p', pos + 1) << endl;

	cout << s1.find(s2, 0) << endl;
	cout << s1.find(s3) << endl;
	cout << s1.find("pei pei") << endl;
	cout << s1.find("pei pei", 0, 4) << endl;

	cout << s1.rfind('i') << endl;

	cout << s1.substr(0, 8) << endl;

	s1.operator+=("123");
	s1 += "123";
	cout << s1;

	system("pause");
	return 0;
}