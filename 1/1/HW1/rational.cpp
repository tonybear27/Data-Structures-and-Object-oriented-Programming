#include "rational.h"
#include <iostream>

Rational::Rational(const int& numerator, const int& denominator)
{
	numer = numerator;
	denom = denominator;
}

void Rational::print()
{
	reduce(&numer, &denom);

	if (denom < 0)
		cout << -numer << '/' << -denom << endl;
	else
		cout << numer << '/' << denom << endl;
}

void Rational::add(const Rational& fr)
{
	numer = numer * fr.denom + fr.numer * denom;
	denom = denom * fr.denom;
}

void Rational::sub(const Rational& fr)
{
	numer = numer * fr.denom - fr.numer * denom;
	denom = denom * fr.denom;
}

void Rational::mul(const Rational& fr)
{
	numer = numer * fr.numer;
	denom = denom * fr.denom;
}

void Rational::div(const Rational& fr)
{
	numer = numer * fr.denom;
	denom = denom * fr.numer;
}

int Rational::gcd(int a, int b)
{
	int r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

void Rational::reduce(int* a, int* b)
{
	int k;
	k = gcd(*a, *b);
	if (k)
	{
		(*a) /= k;
		(*b) /= k;
	}
}