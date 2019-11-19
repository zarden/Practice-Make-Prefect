#include<iostream>
#include<vector>
using namespace std;

int findBreakPoint(const vector<int> &src)
{
	int left = 0, right = src.size() - 1, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (src[mid]>src[mid + 1])
		{
			return mid + 1;
		}

		if (src[left]>src[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
}

int bfind(const vector<int> &src, int bp, int x)
{
	int size = src.size();
	int left = bp, right = bp + size - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (src[mid%size]>x)
		{
			right = mid - 1;
		}
		else if (src[mid%size]<x)
		{
			left = mid + 1;
		}
		else
		{
			return mid%size;
		}
	}
}

int main()
{
	vector<int> src{ 6, 1, 2, 3, 4, 5 };
	int bp = findBreakPoint(src);
	cout << bfind(src, bp, 6);
	system("pause");
	return 0;
}