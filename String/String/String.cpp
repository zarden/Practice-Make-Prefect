#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

//void test_string()
//{
//	//四个默认成员函数
//	string s1;//ok
//	string s2("hello");//ok
//	string s3(s2); //ok
//	string s4("hello", 2);
//	string s5(s2, 1, 8);
//	string s6(s2, 1);
//	string s7(10, 'a');
//
//	cout << s1 << endl;
//	cout << s2 << endl;//hello
//	cout << s3 << endl;//hello
//	cout << s4 << endl;//he
//	cout << s5 << endl;//ello
//	cout << s6 << endl;//ello
//	cout << s7 << endl;//aaaaaaaaaa
//
//	s1 = s7;//ok
//	cout << s1 << endl;//aaaaaaaaaa
//}

//void test_string()
//{
//	string s1("hello");
//	s1 += ' ';
//	s1 += "world";
//	cout << s1 << endl;
//
//	//1、[] +下标
//	//读
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	//写
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		s1[i] += 1;
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	//2、迭代器
//	//写
//	//string::iterator it = s1.begin();
//	auto it = s1.begin();
//	while (it != s1.end())
//	{
//		*it -= 1;
//		++it;
//	}
//
//	//读
//	it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//3、范围for
//	//C++11 --> 原理被替换成迭代器
//	for (auto ch : s1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//}

//void test_string()
//{
//	//反向迭代器
//	string s1("hello world");
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}

//void string2int(const string& str)
//{
//	int val = 0;
//	//const迭代器 只能读不能写
//	string::const_iterator it = str.begin();
//	while (it != str.end())
//	{
//		val *= 10;
//		val += (*it - '0');
//		++it;
//	}
//	cout<<val<<endl;
//}

void test_string()
{
	string s1("hello world");
	string s2("hello");
	cout << s1.size() << endl;//11
	cout << s2.size() << endl;//5
	cout << s1.length() << endl;//11
	cout << s2.length() << endl;//5

	cout << s1.max_size() << endl;//4294967294
	cout << s2.max_size() << endl;//4294967294

	cout << s1.capacity() << endl;//15
	cout << s2.capacity() << endl;//15

	s1 += "111111";
	cout << s1.capacity() << endl;//31
	s1.clear();
	cout << s1 << endl;//空
	cout << s1.capacity() << endl;//31
	
	s1.reserve(100);
	cout << s1.capacity() << endl;
	s1.resize(100, 'x');
	cout << s1.capacity() << endl;
	cout << s1 << endl;
}

//void test_string2()
//{
//	string s;
//	s.reserve(100);
//	//s.resize(100, 'x');
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//
//	/*string s("hello world");
//	s.resize(5);
//	s.resize(20, 'x');*/
//}

void test_string6()
{
	string s;
	s += '1';
	s += "3456";
	cout << s << endl;
	s.insert(s.begin(), '0');
	cout << s << endl;
	s.insert(2, "2");
	cout << s << endl;
	s.erase(2, 10);
	cout << s << endl;

}
int main()
{
	test_string();

	system("pause");
	return 0;
}