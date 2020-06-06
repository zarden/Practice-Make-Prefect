#include<iostream>
using namespace std;
#include<assert.h>

//ʵ��һ��String�࣬����ʱ�䲻���ܾ߱�std::string�Ĺ��ܣ�������Ҫ������ȷ������Դ��
//���캯��+��������+�������캯��+operator=

class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	//String s2(s1)
	//���->��ͳд��
	/*String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}*/

	//���-�ִ�д��
	//String s2(s1)
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	//��ֵ s1=s2;
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

	//��ֵ����
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

