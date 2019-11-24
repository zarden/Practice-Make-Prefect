#include<iostream>
using namespace std;

int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n)
		cout << NumberOf1(n) << endl;
	

	system("pause");
	return 0;
}