#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (IsInvalid(year, month, day))
		{
			cout << "非法日期" << endl;
		}
		else
		{
			_year = year;
			_month = month;
			_day = day;
			cout << "调用构造函数" << endl;
		}
	}
	Date(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
		//cout << "调用拷贝构造函数" << endl;
	}
	Date& operator=(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
		return *this;
	}
	~Date(){}

	void Show()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool IsInvalid(int year, int month, int day);
	bool isLeapYear(int year);
	int GetMonthDay(int year, int month);

	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);

	Date& operator++(); // 前置 
	Date operator++(int); // 后置 
	Date& operator--();
	Date operator--(int);
private:
	int _year;
	int _month;
	int _day;
};
bool Date::isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}
bool Date::IsInvalid(int year, int month, int day)
{
	if (year > 0 && month > 0 && month<13 && GetMonthDay(year, month) >= day&&day>0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);
	int static monthday[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = monthday[month];
	if (month == 2 && isLeapYear(year))
	{
		day = 29;
	}
	return day;
}
bool Date::operator==(const Date& d)
{
	if (_year == d._year&&_month == d._month&&_day == d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::operator!=(const Date& d)
{
	if (_year != d._year||_month != d._month||_day != d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::operator>=(const Date& d)
{

	if ((_year > d._year) 
		|| (_year == d._year&&_month > d._month) 
		|| (_year == d._year&&_month == d._month&&_day >= d._day))
		return true;
	else
		return false;
}
bool Date::operator<=(const Date& d)
{
	if ((_year < d._year)
		|| (_year == d._year&&_month < d._month)
		|| (_year == d._year&&_month == d._month&&_day <= d._day))
		return true;
	else
		return false;
}
bool Date::operator>(const Date& d)
{
	if ((_year > d._year)
		|| (_year == d._year&&_month > d._month)
		|| (_year == d._year&&_month == d._month&&_day > d._day))
		return true;
	else
		return false;
}
bool Date::operator<(const Date& d)
{
	if ((_year < d._year)
		|| (_year == d._year&&_month < d._month)
		|| (_year == d._year&&_month == d._month&&_day < d._day))
		return true;
	else
		return false;
}
Date Date::operator+(int day)
{
	Date ret = *this;
	ret._day += day;
	while (ret._day>GetMonthDay(ret._year,ret._month))
	{
		ret._day -= GetMonthDay(ret._year, ret._month);
		if (ret._month > 0 && ret._month < 12)
		{
			ret._month++;
		}
		else
		{
			ret._year++;
			ret._month = 1;
		}
	}
	return ret;
}
Date& Date::operator+=(int day)
{
	_day = _day + day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day = _day - GetMonthDay(_year, _month);
		if (_month > 0 && _month < 12)
		{
			_month++;
		}
		else
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		//if (_month == 1)
		//{
		//	_day = _day + GetMonthDay(_year-1, 12);
		//}
		//else
		//{
		//	_day = _day + GetMonthDay(_year, _month-1);
		//}
		if (_month > 1 && _month <= 12)
		{
			_month--;
		}
		else
		{
			_year--;
			_month = 12;
		}
		_day = _day + GetMonthDay(_year, _month);
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date ret = *this;
	ret._day -= day;
	while (ret._day <= 0)
	{
		if (ret._month > 1 && ret._month <= 12)
		{
			ret._month--;
		}
		else
		{
			ret._year--;
			ret._month = 12;
		}
		ret._day = ret._day + GetMonthDay(ret._year, ret._month);
	}
	return ret;
}
int Date::operator-(const Date& d)
{
	Date ret1 = *this;
	Date ret2 = d;
	int count = 0;
	while (ret1 != ret2)
	{
		if (ret1 > ret2)
		{
			ret2 = ret2 + 1;
			count++;
		}
		else
		{
			ret1 = ret1 + 1;
			count--;
		}
	}
	return count;
}
Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}
Date Date::operator++(int)
{
	Date ret = *this;
	*this = *this + 1;
	return ret;
}
Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}
Date Date::operator--(int)
{
	Date ret = *this;
	*this = *this - 1;
	return ret;
}
int main()
{
	Date d1;
	d1.Show();
	Date d2(2018, 6, 10);
	d2.Show();
	Date d3(d2);
	d3.Show();

	int count = d2 - d1;
	cout << count << endl;


	system("pause");
	return 0;
}
