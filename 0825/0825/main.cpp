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

//void TestFunc(int a = 0)  ȱʡ���������������Ͷ�����ͬʱ����
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

//�������ؿ����ǲ���������ֵ���Ͳ�Ӱ��
//������������������������ͬʱ���ڣ��������б�����ȫ��ͬ��

//ȱʡ����
//1.�����룬ȡ�����ֵ��û��ȡĬ��ֵ
//2.��������λ�ڲ����б�β�������ܴ���
//3.����ֵ�Ĳ����б��������Ͷ����в���ͬʱ���֣�һ����ڶ����� 

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
//	TestFunc(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ 
//	TestFunc(10); // ����ʱ��ʹ��ָ����ʵ��
//	
//	system("pause");
//	return 0;
//}

//int main()
//{
//	cout << n1::add(2, 3);
//	return 0;
//}

//1.���ֿռ���Խ��������ȫ�ֱ������ظ������⣬���ڲ�ͬ�����ֿռ�����ظ�����ʵ�ʾ���������ȫ�޹صĺ�����
//2.���ֿռ�����Ƕ�ף����ֿռ��ڲ����ⲿֱ��û���κι�ϵ
//3�����ֿռ���������������ϳ�ͬһ�������ռ�


//��������������ġ������c������ֻ�����ļ�����
//ʹ��using �ؼ��֣���������һ�����ֿռ䣬ʹ��������ֿռ��ڵ��������ݶ��Լ��ɼ���

//����������ֿռ�����ֱ�����ͬ��������������ô��ʹͬʱ��using�������������ֿռ�Ҳ���ᱨ��
//����ʹ�������������ʹ�ú�����������壬Ҳ���ǲ�֪���õ����ĸ���