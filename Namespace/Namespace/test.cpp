#include<iostream>

namespace N
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}

	int sub(int left, int right)
	{
		return left - right;
	}
}

//2.ʹ��using�������ռ��г�Ա����
using N::b;


//3. ʹ��using namespace�����ռ���������
using namespace N;

int main()
{
	//1.�������ռ����Ƽ��������޶���
	printf("%d\n", N::a);

	//2.
	printf("%d\n", b);

	//3.
	printf("%d\n", b);
	Add(10, 20);

	return 0;
}

