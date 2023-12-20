#include "rational.h"
#include <iostream>
using namespace std;

Rational::Rational()
{
	numer = 0;
	denom = 1;
}

Rational::Rational(int a, int b)
{
	numer = a;
	denom = b;
}

int Rational::gcd(int a, int b)
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

void Rational::reduce()
{
	int k = gcd(numer, denom);
	if (k)
	{
		numer /= k;
		denom /= k;
	}
}

Rational Rational::operator+(const Rational& fr)
{
	Rational t;
	t.numer = numer * fr.denom + fr.numer * denom;
	t.denom = denom * fr.denom;
	return t;
}

Rational Rational::operator-(const Rational& fr)
{
	Rational t;
	t.numer = numer * fr.denom - fr.numer * denom;
	t.denom = denom * fr.denom;
	return t;
}

Rational Rational::operator*(const Rational& fr)
{
	Rational t;
	t.numer = numer * fr.numer;
	t.denom = denom * fr.denom;
	return t;
}

Rational Rational::operator/(const Rational& fr)
{
	Rational t;
	t.numer = numer * fr.denom;
	t.denom = denom * fr.numer;
	return t;
}

void Rational::operator+=(const Rational& fr)
{
	numer = numer * fr.denom + fr.numer * denom;
	denom *= fr.denom;
}

void Rational::operator-=(const Rational& fr)
{
	numer = numer * fr.denom - fr.numer * denom;
	denom *= fr.denom;
}

void Rational::operator*=(const Rational& fr)
{
	numer *= fr.numer;
	denom *= fr.denom;
}

void Rational::operator/=(const Rational& fr)
{
	numer *= fr.denom;
	denom *= fr.numer;
}

int Rational::operator>(const Rational& fr)
{
	Rational t, tfr;
	t = *this;
	tfr = fr;
	t.numer *= fr.denom;
	t.denom *= fr.denom;
	tfr.numer *= denom;
	tfr.denom *= denom;

	if (t.numer > tfr.numer)
		return 1;
	else
		return 0;
}

int Rational::operator<(const Rational& fr)
{
	Rational t, tfr;
	t = *this;
	tfr = fr;
	t.numer *= fr.denom;
	t.denom *= fr.denom;
	tfr.numer *= denom;
	tfr.denom *= denom;

	if (t.numer < tfr.numer)
		return 1;
	else
		return 0;
}

int Rational::operator>=(const Rational& fr)
{
	Rational t, tfr;
	t = *this;
	tfr = fr;
	t.numer *= fr.denom;
	t.denom *= fr.denom;
	tfr.numer *= denom;
	tfr.denom *= denom;

	if (t.numer >= tfr.numer)
		return 1;
	else
		return 0;
}

int Rational::operator<=(const Rational& fr)
{
	Rational t, tfr;
	t = *this;
	tfr = fr;
	t.numer *= fr.denom;
	t.denom *= fr.denom;
	tfr.numer *= denom;
	tfr.denom *= denom;

	if (t.numer <= tfr.numer)
		return 1;
	else
		return 0;
}

int Rational::operator==(const Rational& fr)
{
	Rational t, tfr;
	t = *this;
	tfr = fr;
	t.numer *= fr.denom;
	t.denom *= fr.denom;
	tfr.numer *= denom;
	tfr.denom *= denom;

	if (t.numer == tfr.numer)
		return 1;
	else
		return 0;
}

int Rational::operator!=(const Rational& fr)
{
	Rational t, tfr;
	t = *this;
	tfr = fr;
	t.numer *= fr.denom;
	t.denom *= fr.denom;
	tfr.numer *= denom;
	tfr.denom *= denom;

	if (t.numer != tfr.numer)
		return 1;
	else
		return 0;
}

Rational Rational::operator-()
{
	Rational t;
	t.numer = numer * -1;
	t.denom = denom;
	return t;
}

Rational Rational::operator++()
{
	Rational t;
	t.numer = numer + denom;
	t.denom = denom;
	numer += denom;
	return t;
}

Rational Rational::operator--()
{
	Rational t;
	t.numer = numer - denom;
	t.denom = denom;
	numer -= denom;
	return t;
}

Rational Rational::operator++(int a)
{
	Rational t;
	t = *this;
	numer += denom;
	return t;
}

Rational Rational::operator--(int a)
{
	Rational t;
	t = *this;
	numer -= denom;
	return t;
}

ostream& operator<<(ostream& ost, Rational fr)
{
	fr.reduce();

	if (fr.denom < 0)
		ost << -fr.numer << '/' << -fr.denom;
	else
		ost << fr.numer << '/' << fr.denom;
	return ost;
}