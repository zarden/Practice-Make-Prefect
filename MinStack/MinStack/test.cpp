#include<stack>
#include<queue>
#include<iostream>
using namespace std;

class MinStack
{
	stack<int> m_data;
	stack<int> m_min;
public:
	MinStack()
	{

	}
	void push(int x)
	{
		m_data.push(x);
		if (m_min.empty() || m_min.top()>x)
		{
			m_min.push(x);
		}
	}

	void pop()
	{
		if (m_data.top() == m_min.top())
		{
			m_min.pop();
		}
		m_data.pop();
	}

	int top()
	{
		return m_data.top();
	}

	int getMin()
	{
		return m_min.top();
	}
};

int main()
{
	MinStack ms;
	ms.push(-2);
	ms.push(0);
	ms.push(-3);
	cout << ms.getMin() << endl;
	ms.pop();
	cout << ms.top() << endl;
	cout << ms.getMin() << endl;

	system("pause");
	return 0;
}