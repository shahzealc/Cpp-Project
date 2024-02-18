
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

		int length() noexcept;

		void tolowercase() noexcept;
		void touppercase() noexcept;
		String operator+(const String&) noexcept;

		bool operator==(const String& str) noexcept;

		void subStr(unsigned int, unsigned int);

		static String intToString(int) noexcept;

		bool operator<(const String& str);
		bool operator<=(const String& str);
		bool operator>(const String& str);
		bool operator>=(const String& str);

		char* getCharString();
	};


}

#endif