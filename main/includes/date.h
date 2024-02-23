#ifndef flag_date
#define flag_date

#include "string.h"
#include "myexception.h"

namespace utility {
	
	class Day {
	public:
		explicit constexpr Day(size_t d) :_day(d) {}
		constexpr operator size_t() noexcept { return _day; }

		size_t _day;
	};

	class Month {
	public:
		explicit constexpr Month(size_t m) :_month(m) {}
		constexpr operator size_t() noexcept { return _month; }

		size_t _month;
	};

	class Year {
	public:
		explicit constexpr Year(size_t y) :_year(y) {}
		constexpr operator size_t() noexcept { return _year; }

		size_t _year;
	};

	
	class Date
	{

	private:
		Day day_;
		Month month_;
		Year year_;

		size_t day{};
		size_t month{};
		size_t year{};

		mutable bool cache_valid = false;
		String cache;

		void compute_cache_value() noexcept {

			Date today = Date::getTodaydate();
			day = today.day;
			month = today.month;
			year = today.year;

			String seprator{ "-" };
			String d = String::intToString(day);
			String m = String::intToString(month);
			String y = String::intToString(year);

			cache = (d + seprator + m + seprator + y);

		}

	public:

		static Date getTodaydate() noexcept;

		Date(Day d, Month m, Year y) :day_(d), month_(m), year_(y), day(d._day), month(m._month), year(y._year) {
			try {
				if (!checkDate())
					throw DateException("Error :: Invalid Date !!!\n");
			}
			catch (DateException e) {
				e.what();
			}
		}
		Date(Month m, Day d, Year y) : day_(d), month_(m), year_(y), day(d._day), month(m._month), year(y._year) {
			try {
				if (!checkDate())
					throw DateException("Error :: Invalid Date !!!\n");
			}
			catch (DateException e) {
				e.what();
			}
		}
		Date(Year y, Day d, Month m) : day_(d), month_(m), year_(y), day(d._day), month(m._month), year(y._year) {
			try {
				if (!checkDate())
					throw DateException("Error :: Invalid Date !!!\n");
			}
			catch (DateException e) {
				e.what();
			}
		}
		Date(Year y, Month m, Day d) : day_(d), month_(m), year_(y), day(d._day), month(m._month), year(y._year) {
			try {
				if (!checkDate())
					throw DateException("Error :: Invalid Date !!!\n");
			}
			catch (DateException e) {
				e.what();
			}
		}
		/*Date(int d = 1, int m = 1, int y = 1970)
			: day{ d }, month{ m }, year{ y }
		{
			try {
				if (!checkDate())
					throw DateException("Error :: Invalid Date !!!\n");
			}
			catch (DateException e) {
				e.what();
			}
		}*/

		void setDate(int d, int m, int y) {
			day = d;
			month = m;
			year = y;
			try {
				if (!checkDate())
					throw DateException("Error :: Invalid Date !!!\n");
			}
			catch (DateException e) {
				e.what();
			}
			refdate();
		}

		void getDate() {
			std::cout << day << "-" << month << "-" << year << "\n";
		}

		bool isLeap(int year) const;
		bool checkDate() const;
		void addDay(const int d) noexcept;
		void addMonth(const int m) noexcept;
		void addYear(const int y) noexcept;

		utility::String getStringrep() noexcept;
		void refdate() const noexcept;

		friend std::ostream& operator<<(std::ostream& stream, Date& date);
	};

}
constexpr utility::Day operator "" _day(unsigned long long d) {
	return utility::Day(static_cast<size_t>(d));
}

constexpr utility::Month operator "" _month(unsigned long long m) {
	return utility::Month(static_cast<size_t>(m));
}

constexpr utility::Year operator "" _year(unsigned long long y) {
	return utility::Year(static_cast<size_t>(y));
}

#endif