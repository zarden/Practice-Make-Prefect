#define _CRT_SECURE_NO_WARNINGS
#include<queue>

using namespace std;
int n, m;
struct node{
	int num, id;
}e;
deque <node> q;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		e.num = a; e.id = i;
		if (i == 1) //��һ������ 
		{
			q.push_back(e);
			printf("0\n");
			continue;
		}
		while (!q.empty() && q.front().id <= i - m - 1)
			q.pop_front(); //�ȰѲ����������ĵ���ȥ 
		printf("%d\n", q.front().num); //�������ͷ 
		while (!q.empty() && q.back().num >= a) 
			q.pop_back(); //����� 
		q.push_back(e);
	}
	return 0;
}
