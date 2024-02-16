#ifndef flag_date
#define flag_date

#include "string.h"
#include "myexception.h"

namespace utility {

	class Date
	{

	private:
		int day{};
		int month{};
		int year{};

		mutable bool cache_valid = false;
		String cache;

		void compute_cache_value() noexcept {

			Date today = Date::getTodaydate();
			day = today.day;
			month = today.month;
			year = today.year;

			String back{ "/" };
			String d = String::intToString(day);
			String m = String::intToString(month);
			String y = String::intToString(year);

			cache = (d + back + m + back + y);

		}

	public:

		static Date getTodaydate() noexcept;

		Date(int d = 1, int m = 1, int y = 1970)
			: day{ d }, month{ m }, year{ y }
		{
			try {
				if (!checkDate())
					throw DateException("Error :: Invalid Date !!!\n");
			}
			catch (DateException e) {
				e.what();
			}
		}

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
			std::cout << day << "/" << month << "/" << year << "\n";
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

#endif