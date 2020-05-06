//#include <iostream>
//using namespace std;
//
//// 1、C语言中struct是用来定义结构体的
//// 2、C++中，兼容C的struct定义结构体的用法。但是同时struct也可以用来定义类
//// 3、C++中使用class和struct定义类的区别？-》默认的访问限定符
//struct ListNode_C
//{
//	int _val;
//	struct ListNode_C* _next;
//	struct ListNode_C* _prev;
//};
//
////struct ListNode_CPP
//class ListNode_CPP
//{
//	int _val;
//	struct ListNode_CPP* _next; // 兼容C的用法
//	ListNode_CPP* _prev;        // C++当成类的用法
//
//	// 还可以定义函数->成员函数
//	ListNode_CPP* CreateNode(int val);
//};
//
//// 1、声明和定义的区别？ 声明是一种承诺，承诺要干嘛，但是还没做，定义就是把这个事落地了。
//// 如何定义一个类
//// 封装
//// 1、将数据和方法放到定义一起。
//// 2、把想给你看到的数据给你看，不想给你看封装起来。->访问限定符
//class Stack
//{
//public:
//	// 1、成员函数
//	void Push(int x)   // 在类里面定义
//	{
//		// ...
//	}
//
//	void Pop();       // 在类里面声明，类外面定义
//
//	bool Empty();     // 这里是声明
//	//...
//private:
//	// 2、成员变量
//	int* _a;
//	int _size;
//	int _capacity;   // 这里是声明
//};
//
//// 类外面定义
//void Stack::Pop()
//{
//	// ...
//}
//
// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1(){}
private:
	int _a;            //8 
	char _ch;
};

// 类中仅有成员函数
class A2 {
public:
	void f2() {}       // 1
};

// 类中什么都没有---空类
class A3
{};               // 1

int main()
{
	// 类实例化出对象,相当于定义出了类的成员变量
	Stack s1;
	Stack s2;
	Stack s3;
	s1._a = nullptr;
	s1.Push(1);
	s2.Push(2);
	s3.Push(3);

	// 对象中只存储成员变量，不存储成员函数？思考一下为什么？
	cout << sizeof(s1) << endl;
	// 一个类实例化出N个对象，每个对象的成员变量都可以存储不同的值，但是调用的函数确是同一个
	// 如果每个对象都放成员函数，而这些成员函数确实一样的，浪费空间。

	// 如何计算一个类实例化出的对象的大小，计算成员变量之和，并且考虑内存对齐规则
	// 没有成员变量的类的大小是1，面试题：为什么是1，而不是0。开1个字节不是为了存数据，而是占位，表示对象存在
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;

	A2 a2;
	A2 aa2;
	A2 aaa2;

	return 0;
}

// 实例化-》就是用自己定义的类型定义出对象
// 1、内置类型，基本类型  int/char/double
// 2、自定义类型，class/struct


#include <iostream>
using namespace std;

class Date
{
public:
	// this是谁调用这个成员函数，this就指向谁
	void Init(int year, int month, int day) // void Init(Date* this, int year, int month, int day)
	{
		/*_year = year;
		_month = month;
		_day = day;*/
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	void Print()  // void Print(Date* this) 
	{
		//cout << _year << "-" << _month << "-" << _day << endl;
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;

	}
private:
	int _year;
	int _month;
	int _day;
};
//
//this指针存在哪里？(也就是存在进程地址空间的哪个区域？）
//答：栈上的，因为他是一个形参。 （ps:vs下是在ecx这个寄存器，来传递）
//
//// 1.下面程序能编译通过吗？
//// 2.下面程序会崩溃吗？在哪里崩溃
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//		//cout << this->_a << endl;
//	}
//
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;  //p->PrintA(p);
//	p->PrintA(); // 这一行会引发什么？编译不通过？ 程序崩溃？ 正常运行？    // 崩溃
//	p->Show();   // 这一行会引发什么？编译不通过？ 程序崩溃？ 正常运行？    // 正常运行
//	// 成员函数存在公共的代码段，所以p->Show()这里不会去p指向的对象上找
//	// 访问成员函数，才回去找
//
//	A a;
//	a.PrintA();  //p->PrintA(&a);
//}

//int main()
//{
//	Date d1;
//	d1.Init(2020, 4, 7); // d1.Init(&d1, 2020, 4, 7);
//	d1.Print();			// d1.Print(&d1);
//
//	return 0;
//}

#include <iostream>
using namespace std;

// 出去工作3-5年，首付+彩礼钱+装修钱就出来了
// 我毕业时腾讯给12w/一年
// 2019年腾讯给30W/一年  sp平均37W/一年

// 构造函数
//1. 函数名与类名相同。
//2. 无返回值。
//3. 对象实例化时编译器自动调用对应的构造函数。
//4. 构造函数可以重载。

//class Date
//{
//public:
//	// 构造函数 ->在对象构造时调用的函数，这个函数完成初始化工作
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	void Init(int year, int month, int day) // void Init(Date* this, int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()  // void Print(Date* this) 
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// 对象实例化时自动调用
//	Date d1(2020, 4, 8);
//	d1.Print();
//
//	Date d2;  // Date d2();不能加括号
//	d2.Print();
//
//	return 0;
//}


//// 5、如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦用户显式定义编译器将不再生成。
//class Time
//{
//public:
//	Time()
//	{
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//
//};
//
//class Date
//{
//public:
//	// 我们没有显式定义构造函数，这里编译器生成无参默认构造函数
//	// 默认生成无参构造函数（语法坑：双标狗）
//	// 1、针对内置类型的成员变量没有做处理
//	// 2、针对自定义类型的成员变量，调用它的构造函数初始化
//
//	// 一旦用户显式定义编译器将不再生成。
//	/*Date(int year, int month, int day)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}*/
//
//	void Print()  // void Print(Date* this) 
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d1;  // 调用编译器生成构造函数
//	d1.Print();
//
//	//Date d2(2020, 3, 8); 
//	//d1.Print();
//
//	return 0;
//}

// 6.无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认构造函数。
// 默认构造函数
//class Date
//{
//public:
//	// 一旦用户显式定义编译器将不再生成。
//	/*Date()
//	{
//	_year = 0;
//	_month = 1;
//	_day = 1;
//	}
//	*/
//	
//	Date(int year, int month, int day)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}
//
//	// 更好的方式->全缺省
//	/*Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	void Print()  // void Print(Date* this) 
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;   // 调用默认构造函数  -》1、自己实现无参的构造函数 2、自己实现的全缺省构造函数  3、我们不写，编译自动生成的
//	                                   // 特点：不用传参数
//	d1.Print();
//
//	//Date d2(2020, 3, 8);
//	//d2.Print();
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		cout << "Date(int year = 0, int month = 1, int day = 1)" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()  // void Print(Date* this) 
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

class Stack
{
public:
	Stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int)*n);
		cout << "malloc:" << _a << endl;
		_size = 0;
		_capacity = n;
	}

	~Stack()
	{
		free(_a);
		cout << "free:" << _a << endl;
		_a = nullptr;
		_size = _capacity = 0;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};

int main()
{
	析构：对象声明周期到了以后，自动调用。完成对象里面的资源清理工作，不是完成d1和d2销毁
		Date d1;
	Date d2;

	Stack s1;
	Stack s2;

	...Push

		return 0;
}
​