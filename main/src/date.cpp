#include <iostream>
#include "../includes/date.h"
#include "../includes/string.h"

using utility::Date;

// Date Class implementation of all function definations

Date Date::getTodaydate() noexcept {
	return Date{ 19_day,02_month,2024_year };
}

bool Date::isLeap(int year) const {

	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	return (year % 4 == 0);

}

bool utility::Date::checkDate() const
{
	
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	if (month == 2)
	{
		if (isLeap(year))
			return (day <= 29);
		else
			return (day <= 28);
	}
 
	if (month == 4 || month == 6 ||
		month == 9 || month == 11)
		return (day <= 30);

	return true;
}

void Date::addDay(const int d) noexcept {

	int days[12] = { 31 , 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	day += d;

	while (day > days[month - 1] || (month == 2 && day == 29 && (!isLeap(year)))) {
		day -= days[month - 1];
		++month;

		if (month == 13) {
			month = 1;
			++year;
		}
	}

}

void Date::addMonth(const int m) noexcept
{
	if ((m + month) <= 12)
		month += m;
	else {
		month += m;
		year += (month / 12);
		month = (month % 12);
	}
}
void Date::addYear(const int y) noexcept
{
	year += y;
}

utility::String Date::getStringrep() noexcept
{
	if (!cache_valid) {
		compute_cache_value();
		cache_valid = true;
	}
	return cache;
}

void Date::refdate() const noexcept {

	Date today = Date::getTodaydate();
	if (today.day == this->day && today.month == this->month && today.year == this->year) {
		cache_valid = true;
	}
	else {
		cache_valid = false;
	}
}

std::ostream& utility::operator<<(std::ostream& stream, Date& date) {
	String seprator{ "-" };
	String d = String::intToString(date.day);
	String m = String::intToString(date.month);
	String y = String::intToString(date.year);

	stream << (d + seprator + m + seprator + y);
	return stream;
}
