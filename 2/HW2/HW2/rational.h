#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class Rational
{
	int numer;
	int denom;
	int gcd(int a, int b);
	void reduce();

public:
	Rational();
	Rational(int a, int b);

	// Binary Arithmetic
	Rational operator+(const Rational& fr);
	Rational operator-(const Rational& fr);
	Rational operator*(const Rational& fr);
	Rational operator/(const Rational& fr);

	//Assignment
	void operator+=(const Rational& fr);
	void operator-=(const Rational& fr);
	void operator*=(const Rational& fr);
	void operator/=(const Rational& fr);

	//Relational
	int operator>(const Rational& fr);
	int operator<(const Rational& fr);
	int operator>=(const Rational& fr);
	int operator<=(const Rational& fr);
	int operator==(const Rational& fr);
	int operator!=(const Rational& fr);

	// Unary Arithmetic
	Rational operator-();
	Rational operator++();
	Rational operator--();
	Rational operator++(int a);
	Rational operator--(int a);

	friend ostream& operator<<(ostream& ost, Rational fr);
};

