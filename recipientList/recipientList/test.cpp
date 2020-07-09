//先接收到一个数字，代表接下来是多少组数据，一个一个接，接到一个就拼一个，
//后面跟上一个逗号和一个空格， 全部接完就给个回车。
//如果输入的字符串里有逗号或者空格，就要加双引号。
//可以选择拼接好了输出，也可以选择 一段段直接输出。
//下面的代码是直接一段段输出的结果。

#include<iostream>]
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		cin.get();//处理回车
		string name;
		for (int i = 0; i < n; i++)
		{
			bool quote = false;
			getline(cin, name);
			if (name.find(',') != string::npos || name.find(' ')!=string::npos)
				quote = true;
			if (quote)
				putchar('\"');
			cout << name;
			if (quote)
				putchar('\"');
			if (i == n - 1)
				putchar('\n');
			else
			{
				putchar(',');
				putchar(' ');
			}

		}
	}
	return 0;
}


//本题的兔子第二天就开始下小兔了，所以这个是从第二项开始的斐波那契数列。
//前90组的数据恰好还在long long 的范围内，
//所以不需要高精度，直接long long求解
#include<iostream>
#include<cstdio>
int main()
{
	long long n[91] = { 1, 1 };
	for (int i = 2; i <= 90; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	}
	int d;
	while (std::cin >> d)
	{
		printf("%lld\n", n[d]);
	}
	return 0;
}