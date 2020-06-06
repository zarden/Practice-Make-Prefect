#include<iostream>
using namespace std;
#include<assert.h>

//实现一个String类，限于时间不可能具备std::string的功能，但至少要求能正确管理资源。
//构造函数+析构函数+拷贝构造函数+operator=

class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	//String s2(s1)
	//深拷贝->传统写法
	/*String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}*/

	//深拷贝-现代写法
	//String s2(s1)
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	//赋值 s1=s2;
	//String& operator=(const String& s)
	//{
	//	if (this !=&s)
	//	{
	//		char* tmp = new char[strlen(s._str) + 1];
	//		strcpy(_str, s._str);
	//		delete[] _str;
	//		_str = tmp;
	//	}
	//	return *this;
	//}

	/*String& operator=(const String& s)
	{
		if (this !=&s)
		{
			String tmp(s);
			swap(_str, tmp._str);
		}
		return *this;
	}*/

	//传值操作
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		delete[] _str;
		_str = nullptr;
	}

	size_t size()
	{
		return strlen(_str);
	}

	char& operator[](size_t i)
	{
		return _str[i];
	}

private:
	char* _str;
};

void test_String()
{
	String s1("hello");
	String s2(s1);
	for (size_t i = 0; i < s2.size(); ++i)
	{
		cout << s2[i];
	}
	cout << endl;

	String s3("world");
	s1 = s3;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i];
	}
	cout << endl;
}

