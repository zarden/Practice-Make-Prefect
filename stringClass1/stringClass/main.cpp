#include"String.h"

int _main()
{
	String s1(4, 'a');
	String s2("canvas");
	String s3 = s2;
	String s4("compent");

	cout << s1.size() << endl;
	cout << s4.size() << endl;
	cout << s4.capacity() << endl;
	s4.resize(16, '8');
	cout << s4.size() << endl;
	cout << s4.capacity() << endl;

	cout << s1 << endl;
	cout << s4 << endl;
	cout << (s4, s1) << endl;
	cout << s3 << endl;
	cout << (s4 < "888") << endl;
	cout << ("888" == s4) << endl;

	//1：纯字符串比较，转换成ASCII码在进行比较；
	//2：纯数字和数字字符串相比较，则将字符串数字隐式转换成数字再进行比较；
	//3：纯数字和非数字字符串比较，都返回false；
	system("pause");
	return  0;
}