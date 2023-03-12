#include <iostream>
#include <cmath>
#pragma once
using namespace std;
class Complex
{
public: double Re, Im;
public:
	Complex(double re = 0, double im = 0) {
		Re = re;
		Im = im;
	}

	double Mod() {
		return sqrt(Re * Re + Im * Im);
	}

	double Arg() {
		if (sqrt(Re * Re + Im * Im) == 0) return 0;
		else if (Re > 0) return atan(Im / Re);
		else if (Re < 0) {
			if (Im >= 0) return acos(-1) + atan(Im / Re);
			else if (Im < 0) return -acos(-1) - atan(Im / Re);
		}
		else {
			if (Im > 0) return acos(0);
			else if (Im < 0) return -acos(0);
		}
	}

	Complex Conjugate() {
		return Complex(this->Re,-this->Im);
	}

	Complex operator +(const Complex& c)const
	{
		return Complex(Re + c.Re, Im + c.Im);
	}

	Complex operator -(const Complex& c)const
	{
		return Complex(Re - c.Re, Im - c.Im);
	}

	Complex operator *(const Complex& c)const
	{
		return Complex(Re * c.Re - Im * c.Im, Re * c.Im + c.Re * Im);
	}

	Complex operator /(const Complex& c)const
	{
		return Complex((Re * c.Re + Im * c.Im)/(c.Re * c.Re + c.Im * c.Im), (- Re * c.Im + c.Re * Im)/ (c.Re * c.Re + c.Im * c.Im));
	}
};

inline ostream& operator << (ostream& o, const Complex& c)
{
	return o << '(' << c.Re << ", " << c.Im << ')';
}


