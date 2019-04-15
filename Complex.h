#pragma once
#include <iostream>

using namespace std;

class Complex
{
	float re;
	float im;
public:
	Complex(const float r = 0, const float i = 0);

	Complex operator+(const Complex);
	Complex operator-(const Complex);
	Complex operator*(const Complex);
	Complex operator/(const Complex);

	Complex operator*(int);

	bool operator!=(const Complex);
	bool operator==(const Complex);

	Complex& operator+=(const Complex);
	Complex& operator-=(const Complex);
	Complex& operator*=(const Complex);
	Complex& operator/=(const Complex);

	float GetR()const;
	float GetI()const;

	void SetR(const float);
	void SetI(const float);

	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
};

