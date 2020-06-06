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

//2.使用using将命名空间中成员引入
using N::b;


//3. 使用using namespace命名空间名称引入
using namespace N;

int main()
{
	//1.加命名空间名称及作用域限定符
	printf("%d\n", N::a);

	//2.
	printf("%d\n", b);

	//3.
	printf("%d\n", b);
	Add(10, 20);

	return 0;
}

