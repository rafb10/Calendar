#include <stdafx.h>
#include "date.hpp"
#include <iomanip>

Date::Date(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}

int date_to_days(const Date& date)
{
	int days = (date.year - 1970) * DAYS_IN_YEAR;
	for(int i = 0; i < date.month-1; i++)
	{
		days += DAYS_IN_MONTHS[i];
	}
	days += date.day;
	return days;
}

Date days_to_date(int days)
{
	Date date;
	date.year = 1970 + days / DAYS_IN_YEAR;
	days = days % DAYS_IN_YEAR;
	int i = 0;
	while(days/DAYS_IN_MONTHS[i])
	{
		date.month++;
		days -= DAYS_IN_MONTHS[i];
		i++;
	}
	date.day = days;
	return date;
}


Date Date::operator+(int & days) const
{
	int date_days;
	date_days = date_to_days(*this);
	date_days += days;
	return days_to_date(date_days);

}

Date Date::operator-(int & days)
{
	int date_days = date_to_days(*this);
	date_days -= days;
	return days_to_date(date_days);
}

int Date::operator-(const Date & date)
{
	int days = date_to_days(*this) - date_to_days(date);
	return days;
}

Date & Date::operator+=(int & days)
{
	int date_days = date_to_days(*this);
	date_days += days;
	*this = days_to_date(date_days);
	return *this;
}

Date & Date::operator-=(int & days)
{
	int date_days = date_to_days(*this);
	date_days -= days;
	*this = days_to_date(date_days);
	return *this;
}



std::ostream & operator<<(std::ostream & out, const Date & date)
{
	out << date.year << "-" << std::setfill('0') << std::setw(2) << date.month << "-" << std::setfill('0') << std::setw(2) << date.day;
	return out;
}

std::istream & operator>>(std::istream & in, Date & date)
{
	in >> date.year >> date.month >> date.day;
	return in;
}

Date & Date::operator=(const Date &date)
{
	day = date.day;
	month = date.month;
	year = date.year;
	return *this;
}
