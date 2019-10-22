#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<class T>
void to_string(string &result, const T &t)//������ֵtת��Ϊ�ַ�����д��result��
{

	ostringstream oss;//����һ����
	oss << t;//��ֵ����������
	result = oss.str();//��ȡת������ַ�������д��result��
}

//����һ��ͨ�õ�ת��ģ�壬������������֮���ת����
//����ģ��convert()��������ģ�����out_type��in_value�������ǽ�in_valueֵת����out_type����
template<class out_type, class in_value>
out_type convert(const in_value & t)
{
	stringstream stream;

	stream << t;//�����д�ֵ
	out_type result;//�洢ת�����
	stream >> result;//��result��д��ֵ

	return result;
}

int main()
{
	//to_stringʵ��
	string s1, s2, s3;

	to_string(s1, 10.5);  //double��string
	to_string(s2, 123);  //int��string
	to_string(s3, true);  //bool��string
	cout << s1 << endl << s2 << endl << s3 << endl << endl;

	//convert()����
	double d;
	string sa;
	string s = "12.56";

	d = convert <double>(s);  //d����12.56
	sa = convert <string>(9000.0); //sa����"9000"

	cout << d << endl << sa << endl;

	system("pause");
	return 0;
}