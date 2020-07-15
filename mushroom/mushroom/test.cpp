/* 使用动态规划 */ 
#include<iostream> 
#include <iomanip>
#include<algorithm> 
#include<vector> 
using namespace std; 

int main()
{
	int n, m, k;

	while (cin >> n >> m >> k)
	{
		// 用来保存蘑菇地图    
		vector<vector<int> > table((n + 1), vector<int>(m + 1));

		// 构造蘑菇地图      

		int x, y;
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			table[x][y] = 1;
		}

		//P[i][j]表示不碰到蘑菇走到i，j的概率 

		vector<vector<double> > P((n + 1), vector<double>(m + 1));
		P[1][1] = 1.0;// 起点概率为0

		for (int i = 1; i <= n; i++)
		{

			for (int j = 1; j <= m; j++)
			{
				if (!(i == 1 && j == 1))
				{
					P[i][j] = P[i - 1][j] * (j == m ? 1 : 0.5) + P[i][j - 1] * (i == n ? 1 : 0.5);
					//边界的时候，概率为1                 
					if (table[i][j] == 1) P[i][j] = 0;
					//如果该点有蘑 菇，概率置为0      			
				}
			}
		}
		cout << fixed << setprecision(2) << P[n][m] << endl;
	}
}