#include <iostream>
#include "../includes/complex.h"

using utility::Complex;

void utility::Complex::operator+=(const Complex& num1)
{
	this->real_number += num1.real_number;
	this->imaginary_number += num1.imaginary_number;
}

void utility::Complex::operator-=(const Complex& num1)
{
	this->real_number -= num1.real_number;
	this->imaginary_number -= num1.imaginary_number;
}

void utility::Complex::operator*=(const Complex& num1)
{
	this->real_number = (num1.real_number * this->real_number) - (num1.imaginary_number * this->imaginary_number);
	this->imaginary_number = (num1.real_number * this->imaginary_number) + (num1.imaginary_number * this->real_number);
}

void utility::Complex::operator/=(const Complex& num2)
{
	Complex temp;
	float denominator = (num2.real_number * num2.real_number) + (num2.imaginary_number * num2.imaginary_number);
	if (denominator == 0) {
		std::cout << "Divided by 0 is not possible" << std::endl;
	}
	else {
		temp.real_number = ((this->real_number * num2.real_number) + (this->imaginary_number * num2.imaginary_number)) / denominator;
		temp.imaginary_number = ((this->imaginary_number * num2.real_number) - (this->real_number * num2.imaginary_number)) / denominator;
	}
}

Complex utility::operator+(const Complex& num1, const Complex& num2)
{
	Complex temp = { (num1.real_number + num2.real_number), (num1.imaginary_number + num2.imaginary_number) };
	return temp;
}

Complex utility::operator-(const Complex& num1, const Complex& num2)
{
	Complex temp = { (num1.real_number - num2.real_number), (num1.imaginary_number - num2.imaginary_number) };
	return temp;
}

Complex utility::operator*(const Complex& num1, const Complex& num2)
{
	double real = (num1.real_number * num2.real_number) - (num1.imaginary_number * num2.imaginary_number);
	double image = (num1.real_number * num2.imaginary_number) + (num1.imaginary_number * num2.real_number);

	Complex temp = { real,image };
	return temp;
}

Complex utility::operator/(const Complex& num1, const Complex& num2)
{

	Complex temp;
	float denominator = (num2.real_number * num2.real_number) + (num2.imaginary_number * num2.imaginary_number);
	if (denominator == 0) {
		std::cout << "Divided by 0 is not possible" << std::endl;
		return 0;
	}
	else {
		temp.real_number = ((num1.real_number * num2.real_number) + (num1.imaginary_number * num2.imaginary_number)) / denominator;
		temp.imaginary_number = ((num1.imaginary_number *num2.real_number) - (num1.real_number * num2.imaginary_number)) / denominator;
		return temp;
	}
	return temp;
}

std::ostream& utility::operator<<(std::ostream& stream, const Complex& num) {

	stream << num.real_number << (num.imaginary_number > 0 ? "+" : "") << num.imaginary_number << "i" << "\n";

	return stream;
}