#include<iostream>
#include<string.h>
using namespace std;

int G[1002][1002], w, h;//长，宽

bool isOk(int x, int y)
{
	return(x < w && y < h);
}

int main()
{
	while (cin >> w >> h)
	{
		memset(G, 0, sizeof(G));//给每个格子初始化为0
		int count = 0;
		int i, j;
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < h; j++)
			{
				if (G[i][j] == 0)//遍历到的G[i][j]==0的个数是可以放蛋糕的个数
				{
					count++;
					if (isOk(i + 2, j))
					{
						G[i + 2][j] = 1;
					}
					if (isOk(i, j + 2))
					{
						G[i][j + 2] = 1;
					}
				}
			}
		}
			cout << count << endl;
		
	}
	return 0;
}