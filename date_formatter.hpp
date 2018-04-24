#ifndef date_formatter_hpp
#define date_formatter_hpp

#include <sstream>
#include "date.hpp"
#include <iomanip>

class DateFormatter {
	public:
		virtual std::string format(const Date &) const = 0;
};

class ComputerDateFormatter : public DateFormatter {
	public:
		std::string format(const Date &) const;
};

class GermanDateFormatter : public DateFormatter {
	public:
		std::string format(const Date &) const;
};

#endif