#ifndef date_hpp
#define date_hpp
#include <array>
#include <iostream>

const int DAYS_IN_YEAR = 365;
const std::array<const int, 12> DAYS_IN_MONTHS = {
	31, // Jan
	28, // Feb
	31, // Mar
	30, // Apr
	31, // May
	30, // Jun
	31, // Jul
	31, // Aug
	30, // Sep
	31, // Oct
	30, // Nov
	31  // Dec
};


class Date {

		int day;
		int month;
		int year;

	public:

		Date(int = 1, int = 1, int = 1970);
		Date(const Date &) = default;
		Date operator+(int &) const;
		Date operator-(int &);
		Date & operator=(const Date &);
		Date & operator+=(int &);
		Date & operator-=(int &);
		int operator-(const Date &);
		bool operator==(const Date & date) { return date_to_days(*this) == date_to_days(date); }
		bool operator!=(const Date & date) { return date_to_days(*this) != date_to_days(date); }
		friend Date operator+(int & days, const Date & date) { return date + days; }
		friend std::istream & operator>>(std::istream &, Date &);
		friend std::ostream & operator<<(std::ostream &, const Date &);
		friend int date_to_days(const Date& date);
		friend Date days_to_date(int days);

		int get_day() const { return day; }
		int get_month() const { return month; }
		int get_year() const { return year; }
};

#endif
