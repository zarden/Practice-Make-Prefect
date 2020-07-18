#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int len = str.size();
		for (int i = 0; i < len; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}