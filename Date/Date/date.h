#pragma once
#include<iostream>
using namespace std;
typedef unsigned int uint;

class Date
{
	uint m_year;
	uint m_month;
	uint m_day;
public:
	Date(uint y, uint m, uint d) :
		m_year(y),
		m_month(m),
		m_day(d)
	{

	}
	
	~Date()
	{
		cout << "123" << endl;
	}

	Date operator+(uint delay) const;

	bool operator<(const Date &d)const;
	bool operator>(const Date &d)const;
	bool operator<=(const Date &d)const;
	bool operator>=(const Date &d)const;
	bool operator==(const Date &d)const;
	bool operator!=(const Date &d)const;

	friend ostream & operator<<(ostream & os, Date &d);

};