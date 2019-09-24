#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{

	vector<vector<int>> data(numRows);
	if (numRows == 0)
	{
		return data;
	}
	int i, j;
	data[0].push_back(1);

	for (i = 1; i < numRows; i++)
	{
		data[i] = data[i - 1];
		for (j = i - 1; j > 0; j--)
		{
			data[i][j] += data[i][j - 1];
		}
		data[i].push_back(1);
	}
	return data;
}

int main()
{
	vector<vector<int>> data = generate(5);

	for (auto &i : data)
	{
		for (auto &j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}

	/*vector<vector<int>> data(10);
	data[0].push_back(3);
	data[0].push_back(5);
	for (int i = 1; i < 10; i++)
	{
		data[i] = data[0];
	}
	for (int i = 0; i < 10; i++)
	{
		cout << data[i][0] << ' ' << data[i][1] << endl;
	}*/

	system("pause");
	return 0;
}
