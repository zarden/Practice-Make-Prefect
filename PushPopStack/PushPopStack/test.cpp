#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool IsPopOrder(vector<int> pushv, vector<int> popv)
{
	stack<int> stmp;
	int i = 0;

	for (auto &vi : pushv)
	{
		stmp.push(vi);
		for (; !stmp.empty() && stmp.top() == popv[i]; i++)
		{
			stmp.pop();
		}
	}
	return stmp.empty();
}

int main()
{
	vector<int> puv{ 1, 2, 3, 4, 5 };
	vector<int>pov{ 4, 5, 1, 2, 3 };

	cout << IsPopOrder(puv, pov);
	system("pause");
	return 0;
}