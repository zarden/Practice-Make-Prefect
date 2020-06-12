#include <iostream>
#include <vector>
#include <list>
using namespace std;

//包含纯虚函数的类为抽象类，抽象类不能实例化出对象
//class Car
//{
//public:
//	virtual void Drive() = 0; // 纯虚函数,不需要实现
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//int main()
//{
//	Benz benz;
//
//	return 0;
//}

// 笔试题：sizeof(Base)是多少？
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
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//	int _p = 1;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
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
	// 取出对象的前4个字节
	Base b1;
	printf("vftptr虚表地址:%p\n", *(int*)&b1);
	//printf("vftptr:%p\n", (int)b1); //直接转语法不接受，这里用指针转，再解引用


	int i = 0;
	int* p1 = &i;
	int* p2 = new int;
	char* p3 = "hello";
	printf("栈变量:%p\n", p1);
	printf("堆变量:%p\n", p2);
	printf("代码段常量:%p\n", p3);
	printf("虚函数地址:%p\n", &Base::Func1);
	printf("普通函数地址:%p\n", func);
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
	// 静态绑定 静态的多态   (静态：编译时确定函数地址)  
	f1(i);
	f1(d);

	// 动态绑定  动态的多态  （动态：运行时到虚表中找虚函数地址）
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

//void(*p)(); // 定义一个函数指针变量
typedef void(*VF_PTR)(); // 函数指针类型typedef

// 打印虚表->虚表本质是一个虚函数指针数组
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