//�Ƚ��յ�һ�����֣�����������Ƕ��������ݣ�һ��һ���ӣ��ӵ�һ����ƴһ����
//�������һ�����ź�һ���ո� ȫ������͸����س���
//���������ַ������ж��Ż��߿ո񣬾�Ҫ��˫���š�
//����ѡ��ƴ�Ӻ��������Ҳ����ѡ�� һ�ζ�ֱ�������
//����Ĵ�����ֱ��һ�ζ�����Ľ����

#include<iostream>]
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		cin.get();//����س�
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


//��������ӵڶ���Ϳ�ʼ��С���ˣ���������Ǵӵڶ��ʼ��쳲��������С�
//ǰ90�������ǡ�û���long long �ķ�Χ�ڣ�
//���Բ���Ҫ�߾��ȣ�ֱ��long long���
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