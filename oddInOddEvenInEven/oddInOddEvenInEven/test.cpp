#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	void oddInOddEvenInEven(vector<int>& arr, int len)
	{
		long i = 0, j = 1;
		while (i<len && j< len)
		{
			if (arr[i] % 2 == 0)
			{
				i += 2;
				continue;
			}
			if (arr[j] % 2 != 0)
			{
				j += 2;
				continue;
			}
			swap(arr[i], arr[j]);
		}
	}
};