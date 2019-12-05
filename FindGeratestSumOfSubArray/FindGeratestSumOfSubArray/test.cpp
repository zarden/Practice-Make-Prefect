#include<stdlib.h>
#include<vector>
using namespace std;

class Solution
{
public:
	int FindGreatestSumOfSubArray(vector<int>array)
	{
		if (array.empty())
		{
			return -1;
		}
		int sum = array[0];
		int maxsum = array[0];

		for (int i = 1; i < array.size(); i++)
		{
			sum = (sum>0) ? sum + array[i] : array[i];
			maxsum = (sum < maxsum) ? maxsum : sum;
		}
		return maxsum;

	}

};