#include <iostream>
#include <vector>
#include <list>
using namespace std;

//�������麯������Ϊ�����࣬�����಻��ʵ����������
//class Car
//{
//public:
//	virtual void Drive() = 0; // ���麯��,����Ҫʵ��
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-����" << endl;
//	}
//};
//
//int main()
//{
//	Benz benz;
//
//	return 0;
//}

// �����⣺sizeof(Base)�Ƕ��٣�
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;//8
//	Base b;
//
//	system("pause");
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//
//	int _p = 1;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//
//	int _s = 2;
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//
//	system("pause");
//	return 0;
//}

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}

	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}

private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};

void test1()
{
	Base b1;
	Derive d1;
}

void test2()
{
	Base b2;
	Derive d2;
}

void func()
{
	// ȡ�������ǰ4���ֽ�
	Base b1;
	printf("vftptr����ַ:%p\n", *(int*)&b1);
	//printf("vftptr:%p\n", (int)b1); //ֱ��ת�﷨�����ܣ�������ָ��ת���ٽ�����


	int i = 0;
	int* p1 = &i;
	int* p2 = new int;
	char* p3 = "hello";
	printf("ջ����:%p\n", p1);
	printf("�ѱ���:%p\n", p2);
	printf("����γ���:%p\n", p3);
	printf("�麯����ַ:%p\n", &Base::Func1);
	printf("��ͨ������ַ:%p\n", func);
}

void f1(int i)
{}

void f1(double d)
{}

int main()
{
	//test1();
	//test2();
	//func();

	int i = 0;
	double d = 1.1;
	// ��̬�� ��̬�Ķ�̬   (��̬������ʱȷ��������ַ)  
	f1(i);
	f1(d);

	// ��̬��  ��̬�Ķ�̬  ����̬������ʱ����������麯����ַ��
	Base* p = new Base;
	p->Func1();
	p = new Derive;
	p->Func1();

	return 0;
}

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

//void(*p)(); // ����һ������ָ�����
typedef void(*VF_PTR)(); // ����ָ������typedef

// ��ӡ���->�������һ���麯��ָ������
//void PrintVFTable(VF_PTR* pTable)
void PrintVFTable(VF_PTR pTable[])
{
	for (size_t i = 0; pTable[i] != 0; ++i)
	{
		printf("vfTable[%d]:%p->", i, pTable[i]);
		VF_PTR f = pTable[i];
		f();
	}
	cout << endl;
}

int main()
{
	cout << sizeof(Derive) << endl;
	Derive d;

	cout << sizeof(Base1) << endl;

	PrintVFTable((VF_PTR*)(*(int*)&d));
	PrintVFTable((VF_PTR*)(*(int*)((char*)&d + sizeof(Base1))));

	return 0;
}