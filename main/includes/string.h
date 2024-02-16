
#ifndef flag_string
#define flag_string

namespace utility {

	class String {
	private:
		std::unique_ptr<char[]> stringBuffer;
		unsigned int stringSize;

	public:
		String(const char* string = "") {
			//std::cout << "Default constructor called" << "\n";

			stringSize = strlen(string);
			stringBuffer = std::make_unique<char[]>(stringSize + 1);
			memcpy(stringBuffer.get(), string, stringSize);
			stringBuffer[stringSize] = 0;
		}

		String(const String& str) {
			//std::cout << "Copy constructor called" << "\n";

			stringSize = str.stringSize;
			stringBuffer = std::make_unique<char[]>(stringSize + 1);
			memcpy(stringBuffer.get(), str.stringBuffer.get(), stringSize + 1);
		}

		String& operator=(const String& str) {
			//std::cout << "Copy Assignment called" << "\n";

			stringSize = str.stringSize;
			stringBuffer = std::make_unique<char[]>(stringSize + 1);
			memcpy(stringBuffer.get(), str.stringBuffer.get(), stringSize + 1);
			return *this;
		}

		String(String&& str) noexcept {
			//std::cout << "Move constructor called" << "\n";

			stringSize = str.stringSize;
			stringBuffer = std::move(str.stringBuffer);
			str.stringBuffer = nullptr;
			str.stringSize = 0;
		}

		String& operator=(String&& str) noexcept {
			//std::cout << "Move Assignment called" << "\n";

			stringSize = str.stringSize;
			stringBuffer = std::move(str.stringBuffer);
			str.stringBuffer = nullptr;
			str.stringSize = 0;
			return *this;
		}

		~String() = default;

		friend std::ostream& operator<<(std::ostream& stream, const String& string);

		char& operator[](unsigned int index);

		int length();

		void tolowercase();
		void touppercase();
		String operator+(const String&);

		bool equal(const String& str);

		void subStr(unsigned int, unsigned int);

		static String intToString(int);

		/*bool lessThan(const String& str);
		bool lessThanequall(const String& str);
		bool greaterThan(const String& str);
		bool greaterThanequall(const String& str);*/

	};


}

#endif