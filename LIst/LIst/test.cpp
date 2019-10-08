#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> l1;//构造空列表l1;

	list<int> l2(6, 6);//l2列表中存放6个值为6的元素

	list<int> l3(l2.begin(), l2.end());//用l2列表的[begin(),end()) 左闭右开区间构造l3列表

	list<int> l4(l3);//用l3列表拷贝构造l4列表

	//打印l1,l2,l3,l4列表
	for (auto &i : l1)
		cout << i << " ";
	cout << endl;
	for (auto &i : l2)
		cout << i << " ";
	cout << endl;
	for (auto &i : l3)
		cout << i << " ";
	cout << endl;
	for (auto &i : l4)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}