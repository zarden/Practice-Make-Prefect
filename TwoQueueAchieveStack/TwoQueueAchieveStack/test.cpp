#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class queueStack
{
	queue<int> m_qu1;
public:
	queueStack()
	{

	}

	void push(int x)
	{
		m_qu1.push(x);
	}

	void pop()
	{
		queue<int> m_qu2;
		while (m_qu1.size() > 1)
		{
			m_qu2.push(m_qu1.front());
			m_qu1.pop();
		}
		m_qu1 = m_qu2;
	}

	int top()
	{
		queue<int> m_qu2;
		while (m_qu1.size() > 1)
		{
			m_qu2.push(m_qu1.front());
			m_qu1.pop();
		}
		int tmp = m_qu1.front();
		/*m_qu2.push(m_qu1.front());
		m_qu1 = m_qu2;*/
		return tmp;
	}
};

int main()
{
	queueStack qs;

	qs.push(1);
	qs.push(2);
	qs.push(3);
	qs.push(4);

	cout << qs.top() << endl;
	qs.pop();
	cout << qs.top() << endl;
	qs.pop();
	cout << qs.top() << endl;
	qs.pop();
	cout << qs.top() << endl;
	qs.pop();

	system("pause");
	return 0;
}