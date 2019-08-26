#include <iostream>
using namespace std;
#include "t1.h"
using namespace t1;


namespace test
{
	namespace n1
	{
		int add(int a, int b)
		{
			std::cout << "1\n";
			return a + b;
		}
	}

	namespace n2
	{
		int add(int a, int b)
		{
			cout << "2\n";
			return a + b;
		}
	}
}

namespace n2
{
	int add(int a, int b)
	{
		cout << "3\n";
		return a + b;
	}
}

namespace n2
{
	int sub(int a, int b)
	{
		cout << "4\n";
		return a - b;
	}
}

int add(int a, int b)
{
	return a + b;
}
/*
int main()
{
  
    cout << t1::add(2, 3);
    system("pause");
    return 0;
}
*/
//namespace n1
//{
//	int add(int a, int b)
//	{
//		cout << "1\n";
//		return a + b;
//	}
//}
//
//void TestFunc(int a, int b = 10, int c = 20) 
//{ cout << "a = " << a << endl;
//cout << "b = " << b << endl;
//cout << "c = " << c << endl;
//}

//void TestFunc(int a = 0)  缺省函数不能在声明和定义中同时出现
//{ 
//	cout << a << endl;
//}


//void swapArgs(int *ps, int *pb)
//{
//	int tmp = *ps;
//	*ps = *pb;
//	*pb = tmp;
//}
//
//
//void swapArgs(float *s, float *b)

//函数重载看的是参数，返回值类型不影响
//函数重载允许两个重名函数同时存在，但参数列表不能完全相同。

//缺省参数
//1.若传入，取传入的值，没传取默认值
//2.参数必须位于参数列表尾部，不能穿插
//3.被赋值的参数列表在声明和定义中不能同时出现，一般放在定义中 

//{
//	float tmp = *s;
//	*s = *b;
//	*b = tmp;
//}
//int main() 
//{
//	int a = 4, b = 7;
//	float c = 3.14, d = 1.628;
//	swapArgs(&a, &b);
//	swapArgs(&c, &d);
//	cout << a << "" << b << endl;
//	TestFunc(); // 没有传参时，使用参数的默认值 
//	TestFunc(10); // 传参时，使用指定的实参
//	
//	system("pause");
//	return 0;
//}

//int main()
//{
//	cout << n1::add(2, 3);
//	return 0;
//}

//1.名字空间可以解决函数，全局变量名重复的问题，包在不同的名字空间里的重复函数实际就是两个完全无关的函数。
//2.名字空间允许嵌套，名字空间内部和外部直接没有任何关系
//3。名字空间允许重名，最后会合成同一个命名空间


//用来定义作用域的。解决了c语言中只能用文件划分
//使用using 关键字，可以引言一个名字空间，使得这个名字空间内的所有内容对自己可见。

//如果两个名字空间里面分别有相同的两个函数，那么即使同时用using引言了两个名字空间也不会报错，
//除非使用了这个函数（使用函数会产生歧义，也就是不知道该调用哪个）