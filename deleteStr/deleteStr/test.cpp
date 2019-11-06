#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	char buf[256] = { 0 };
	for (int i = 0; i < str2.size(); i++)
	{
		buf[str2[i]]++;
	}
	string ret;
	for (int i = 0; i < str1.size(); i++)
	{
		if (buf[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;

	system("pause");
	return 0;
}