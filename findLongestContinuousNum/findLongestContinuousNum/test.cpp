#include<iostream>
#include<string>
using namespace std;

void Findnum(string str)
{
	size_t i = 0;
	int count = 0;//����
	int maxnum = 0;//���������ִ�����
	int pos = 0;//������ִ��Ŀ�ʼλ��
	while (i < str.size())
	{
		while (!isdigit(str[i]))
			i++;//�������־�������
		while (isdigit(str[i]))
		{
			count++;
			i++;
		}
		if (count>maxnum)
		{
			maxnum = count;//����maxnum
			pos = i - maxnum;//���pos
		}
		count = 0;
	}
	for (int j = pos; j < pos+maxnum; j++)
	{
		cout << str[j] ;
	}
}

int main()
{
	string str="abcd12345ed125ss123456789";
	Findnum(str);
	system("pause");
	return 0;
}