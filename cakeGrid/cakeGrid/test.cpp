#include<iostream>
#include<string.h>
using namespace std;

int G[1002][1002], w, h;//������

bool isOk(int x, int y)
{
	return(x < w && y < h);
}

int main()
{
	while (cin >> w >> h)
	{
		memset(G, 0, sizeof(G));//��ÿ�����ӳ�ʼ��Ϊ0
		int count = 0;
		int i, j;
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < h; j++)
			{
				if (G[i][j] == 0)//��������G[i][j]==0�ĸ����ǿ��Էŵ���ĸ���
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