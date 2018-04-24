#include <stdafx.h>
#include "date_formatter.hpp"

std::string ComputerDateFormatter::format(const Date & d) const
{
	std::ostringstream computer_date;
	computer_date << d.get_year() << "-" << std::setfill('0') << std::setw(2) << d.get_month() << "-" << std::setfill('0') << std::setw(2) << d.get_day();
	return computer_date.str();
}

std::string GermanDateFormatter::format(const Date & d) const
{
	std::ostringstream german_date;
	german_date << std::setfill('0') << std::setw(2) << d.get_day() << "-" << std::setfill('0') << std::setw(2) << d.get_month() << "-" << d.get_year() ;
	return german_date.str();
}