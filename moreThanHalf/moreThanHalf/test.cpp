#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *data = new int[n];
	int *stack = new int[n];
	int top = 0;
	cin >> data[0];
	stack[++top] = data[0];
	for (int i = 1; i <n; ++i)
	{
		cin >> data[i];
		stack[++top] = data[i];
		if (top>1 && stack[top] != stack[top-1])
		{
			top -= 2;
		}
		cout<< stack[top];
		delete[] data;
		delete[] stack;
	}
	system("pause");
	return 0;
}