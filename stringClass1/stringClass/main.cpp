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

	//1�����ַ����Ƚϣ�ת����ASCII���ڽ��бȽϣ�
	//2�������ֺ������ַ�����Ƚϣ����ַ���������ʽת���������ٽ��бȽϣ�
	//3�������ֺͷ������ַ����Ƚϣ�������false��
	system("pause");
	return  0;
}