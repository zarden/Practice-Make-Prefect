#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<class T>
void to_string(string &result, const T &t)//将任意值t转换为字符串并写入result中
{

	ostringstream oss;//创建一个流
	oss << t;//把值传递入流中
	result = oss.str();//获取转换后的字符并将其写入result中
}

//定义一个通用的转换模板，用于任意类型之间的转换。
//函数模板convert()含有两个模板参数out_type和in_value，功能是将in_value值转换成out_type类型
template<class out_type, class in_value>
out_type convert(const in_value & t)
{
	stringstream stream;

	stream << t;//向流中传值
	out_type result;//存储转换结果
	stream >> result;//向result中写入值

	return result;
}

int main()
{
	//to_string实例
	string s1, s2, s3;

	to_string(s1, 10.5);  //double到string
	to_string(s2, 123);  //int到string
	to_string(s3, true);  //bool到string
	cout << s1 << endl << s2 << endl << s3 << endl << endl;

	//convert()例子
	double d;
	string sa;
	string s = "12.56";

	d = convert <double>(s);  //d等于12.56
	sa = convert <string>(9000.0); //sa等于"9000"

	cout << d << endl << sa << endl;

	system("pause");
	return 0;
}