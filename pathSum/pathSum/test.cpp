#include<iostream> 
using namespace std; 
int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		//b������ݹ�
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1))) 
		//a�������ֹ���� 
		return n + m;
	else 
		//����Ϊ0ʱ�� ·��Ϊ0
		return 0;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	}
	return 0;
}