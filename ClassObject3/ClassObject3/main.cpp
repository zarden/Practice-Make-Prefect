#include<iostream>

using namespace std;

class Test2{


public:
	Test2(int i)
	{_
	}
};



class Test
{
public:
	const int i;
	int &ri;
	//auto  不行

	Test(int &a) :i(3), ri(a),t2(a)//相当于初始化
	{}
};








int main()
{
	

	system("pause");
	return 0;
}