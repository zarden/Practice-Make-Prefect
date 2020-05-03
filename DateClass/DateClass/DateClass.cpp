#include<iostream>
using namespace std;

class Date
{
public:
	//��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		//��2���������귵��29
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDays[month];
	}

	//ȫȱʡ�Ĺ��캯��
	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "�Ƿ�����" << endl;
		}
	}

	//�������캯�� Date d2(d1)
	Date(const Date& d)
	{
		this->_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//��ֵ���������
	//d1 = d2 
	//d1.operator=(&d2,d3)
	Date& operator=(const Date&d)
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}

	//��������
	~Date()
	{
		//������
	}

	//�Ƚ����ڴ�С
	//1.����С�� d1<d2   
	//d1.operator<(&d1, d2);
	bool operator<(const Date& d) //bool operator<(Date* this,const Date& d)
	{
		if (_year < d._year)
			return true;
		if (_year == d._year && _month < d._month)
			return true;
		if (_year == d._year && _month == d._month && _day < d._day)
			return true;

		return false;
	}

	//2.���ص��� d1==d2
	bool operator==(const Date&d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	//3.����С�ڵ��� d1<=d2--> d1<d2 || d1==d2
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;//��������Ĵ���ʵ��
	}

	//4.���ش��� d1>d2 -> !(d1<=d2)
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	//5.���ش��ڵ��� d1>=d2--> d1>d2 || d1==d2
	bool operator>=(const Date& d)
	{
		return !(*this < d);//��������Ĵ���ʵ��
	}

	//6.���ز�����
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	//ʵ������+����������� 
	//d1+10  d1+100  d1+1000
	Date operator+(int day)
	{
		Date ret(*this);//��d1��������һ��ret
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			//������ڵ��첻�Ϸ�����Ҫ���½���
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;

			if (ret._month==13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}

	//d1+=10   d1+=-10
	Date operator+=(int day)
	{
		if (day<0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;

			if (_month==13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	
	//����-=����  d1-=10  d1-=-10
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return (*this) += -day;
		}
		_day -= day;
		while (_day<=0)
		{
			--_month;
			if (_month==0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	//����-���� d1-10 
	Date& operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}

	//ǰ��++  
	//++d1 --> d1.operator++(&d)
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	//����++
	//d1++  --> d1.operator++(&d,0)
	Date& operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}

	//ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	//����--
	Date& operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}

	//����-���� ��������
	//d1-d2
	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}

		int day = 0;
		while (min<max)
		{
			++(min);
			++day;
		}
		return day*flag;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 5, 1);
	d1.Print();

	Date d2(2020, 5, 3);
	d2.Print();

	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 >= d2) << endl;

	//�Ƿ�Ҫ����һ����������������������Ƿ�������Ķ���������
	Date d3 = d1 + 1000;
	d3.Print();

	Date d4 =d2 += 1000;
	d4.Print();
	
	d1 += 10;
	d1.Print();

	d1 - 10;
	d1.Print();

	d1 -= 10;
	d1.Print();

	d1 - d2;

	d1++;
	d1.Print();

	d1--;
	d1.Print();

	system("pause");
	return 0;
}