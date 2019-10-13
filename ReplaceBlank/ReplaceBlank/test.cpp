#include<iostream>
using namespace std;

void replaceBlank(char s[], int len)
{
	if (s==NULL || len<0)
	{
		return;
	}

	int blanks = 0;
	int i = 0;
	int lenS = 0;//实际长度

	while (s[i]!='\0')
	{
		++lenS;
		if (s[i]==' ')
		{
			++blanks;
		}
		++i;
	}

	int newlen = lenS + 2 * blanks;
	cout << lenS << " " << newlen << endl;//13 17

	int p1 = lenS;
	int p2 = newlen;
	while (p1>0 &&  p2>p1)
	{
		if (s[p1] == ' ')
		{
			s[p2--] = '0';
			s[p2--] = '2';
			s[p2--] = '%';
		}
		else
		{
			s[p2--] = s[p1];
		}
		--p1;
	}
}

int main()
{
	char s[20] = "we are happy.";//这里的20必须大于上面的newlen

	cout << strlen(s) << endl;//13
	cout << sizeof(s) << endl;//20
	replaceBlank(s, sizeof(s));

	cout << s << endl;

	system("pause");
	return 0;
}