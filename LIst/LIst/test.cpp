#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> l1;//������б�l1;

	list<int> l2(6, 6);//l2�б��д��6��ֵΪ6��Ԫ��

	list<int> l3(l2.begin(), l2.end());//��l2�б��[begin(),end()) ����ҿ����乹��l3�б�

	list<int> l4(l3);//��l3�б�������l4�б�

	//��ӡl1,l2,l3,l4�б�
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