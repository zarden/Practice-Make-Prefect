#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned char c = 8;//ÿ�μ�256 ����7
	int j = 0;
	for (; c > 0; c -= 7)
	{
		j++;
	}
	printf("%d", j);

	system("pause");
	return 0;

}