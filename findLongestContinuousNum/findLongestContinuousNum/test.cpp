#include<iostream>
#include<string>
using namespace std;

void Findnum(string str)
{
	size_t i = 0;
	int count = 0;//计数
	int maxnum = 0;//标记最大数字串长度
	int pos = 0;//最大数字串的开始位置
	while (i < str.size())
	{
		while (!isdigit(str[i]))
			i++;//不是数字就往后走
		while (isdigit(str[i]))
		{
			count++;
			i++;
		}
		if (count>maxnum)
		{
			maxnum = count;//更新maxnum
			pos = i - maxnum;//标记pos
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