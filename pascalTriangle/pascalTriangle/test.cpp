#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &v, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}

void printGenerate(int n)
{
	vector<int> v(n, 0);
	v[0] = 1;
	printArray(v, 1);

	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = i; j > 0; j--)
		{
			v[j] += v[j - 1];
		}
		printArray(v, i + 1);
	}
}

int main1()
{
	printGenerate(10);
	system("pause");
	return 0;
}




