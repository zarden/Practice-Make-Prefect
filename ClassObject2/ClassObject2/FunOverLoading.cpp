#include<iostream>
#include<cstring>

using namespace std;

struct student
{
	char name[32];
	int age;
	int classid;
	bool sex;
};

bool cmpEql(student a, student b)
{
	return a.age == b.age;
}

int countS(student *st, int n, student value, bool(*cmp)(student,student)=cmpEql)
{
	int i;
	int count = 0;

	for ( i = 0; i < n; i++)
	{
		if (cmp(st[i], value))
		{
			count++;
		}
	}
	return count;
}

bool cmpEqlname(student a, student b)
{
	return strcmp(a.name, b.name) ? false : true;//若str1=str2，则返回零；
												//若str1<str2，则返回负数；
												//若str1>str2，则返回正数

}

bool cmpEqlSex(student a, student b)
{
	return !(a.sex^b.sex);//如果a、b两个值不相同，则异或结果为1。
						//如果a、b两个值相同，异或结果为0。
}

int main()
{
	student st[] = { { "caixukun", 18, 1, true },
					{ "qiaobiluo", 18, 1, false },
					{ "wuyifan", 20, 2, true }, 
					{ "luhan", 22, 2, true }, 
					{ "lubenwei", 22, 2, true }, 
					{ "yangchaoyue", 20, 1, false }, 
					{ "caixukun", 18, 1, true} };

	student test = { "caixukun", 18, 1, true };

	cout << countS(st, 7, test, cmpEqlSex) << endl;

	system("pause");
	return 0;
}