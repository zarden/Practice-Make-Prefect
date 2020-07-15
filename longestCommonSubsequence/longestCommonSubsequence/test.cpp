#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int aLength = A.length();
		int bLength = B.length();
		// ��������״̬ת�Ʒ����м����ľ��� ? 

		vector<vector<int> > dp(aLength, vector<int>(bLength, 0));
		// ��ʼ��dp����߽磺�߽��ַ�Ҫô�ڣ�Ҫô���� ? ?

		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i<aLength; i++)
		{
			dp[i][0] = (A[i] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}

		for (int j = 1; j<bLength; j++)
		{
			dp[0][j] = (A[0] == B[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j - 1], dp[0][j]);
		}

		// ����״̬ת�Ʒ��̽��м��� ? ? ?
		for (int i = 1; i<aLength; i++)
		{
			for (int j = 1; j<bLength; j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (A[i] == B[j])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}

		cout << dp[aLength - 1][bLength - 1] << endl;
	}

	return 0;
}