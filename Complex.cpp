
#include "Complex.h"

Complex::Complex(const float r, const float i)
{
	this->re = r;
	this->im = i;
}

Complex Complex::operator+(const Complex z)
{
	Complex result(this->re + z.re, this->im + z.im);
	return result;
}

Complex Complex::operator-(const Complex z)
{
	Complex result(this->re - z.re, this->im - z.im);
	return result;
}
Complex Complex::operator*(const Complex z)
{
	float a = this->GetR(), b = this->GetI();
	float c = z.GetR(), d = z.GetI();

	Complex result(a*c - b * d, b*c + a * d);

	return result;
}
Complex Complex::operator/(const Complex z)
{
	float a = this->GetR(), b = this->GetI();
	float c = z.GetR(), d = z.GetI();

	Complex result((a*c + b * d) / (c*c + d * d), (b*c - a * d) / (c*c + d * d));

	return result;
}

Complex Complex::operator*(int a)
{
	Complex result(this->re * a, this->im * a);
	return result;
}

Complex& Complex::operator+=(const Complex z)
{
	re += z.re;
	im += z.im;

	return *this;
}
Complex& Complex::operator-=(const Complex z)
{
	re -= z.re;
	im -= z.im;

	return *this;
}
Complex& Complex::operator*=(const Complex z)
{
	re *= z.re;
	im *= z.im;

	return *this;
}
Complex& Complex::operator/=(const Complex z)
{
	re /= z.re;
	im /= z.im;

	return *this;
}

bool Complex::operator!=(const Complex z)
{
	if ((this->re == z.re) && (this->im == z.im))
		return false;
	else
		return true;
}
bool Complex::operator==(const Complex z)
{
	if ((this->re == z.re) && (this->im == z.im))
		return true;
	else
		return false;
}

float Complex::GetR()const
{
	return re;
}
float Complex::GetI()const
{
	return im;
}

void Complex::SetR(const float r)
{
	re = r;
}
void Complex::SetI(const float i)
{
	im = i;
}

ostream& operator<<(ostream& out, const Complex& B)
{
	if (B.im < 0)
		return out << B.re << B.im << "i";
	else
		return out << B.re << "+" << B.im << "i";
}
istream& operator>>(istream& in, Complex& z)
{
	char ch = 0;
	in >> z.re >> z.im >> ch;
	return in;
}
