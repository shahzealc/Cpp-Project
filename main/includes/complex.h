
#ifndef complex_flag
#define complex_flag

namespace utility {

	class Complex
	{

	private:
		double real_number{};
		double imaginary_number{};

	public:
		Complex(double i = 0,double j = 0):real_number{i}, imaginary_number{j}{}

		void operator+=(const Complex&);
		void operator-=(const Complex&);
		void operator*=(const Complex&);
		void operator/=(const Complex&);

		friend Complex operator+(const Complex&, const Complex& );
		friend Complex operator-(const Complex& , const Complex& );
		friend Complex operator*(const Complex& , const Complex& );
		friend Complex operator/(const Complex& num1, const Complex& num2);

		friend std::ostream& operator<<(std::ostream& , const Complex& );

	};

}
   
#endif