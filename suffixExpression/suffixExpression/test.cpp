#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n<3 || n>50)
			return 0;

		stack<int> st;
		int num1 = 0;
		int num2 = 0;
		string str;

		for (int i = 0; i<n; i++)
		{
			cin >> str;
			if ((str[0] >= '0') && (str[0] <= '9'))
				st.push(atoi(str.c_str()));
			else
			{
				num1 = st.top();
				st.pop();
				num2 = st.top();
				st.pop();
				if (str == "+")
				{
					num1 = num2 + num1;
					st.push(num1);
				}
				else if (str == "-")
				{
					num1 = num2 - num1;
					st.push(num1);
				}
				else if (str == "*")
				{
					num1 = num2*num1;
					st.push(num1);
				}
				else if (str == "/")
				{
					num1 = num2 / num1;
					st.push(num1);
				}

			}
		}
		cout << st.top() << endl;
	}

	return 0;
}