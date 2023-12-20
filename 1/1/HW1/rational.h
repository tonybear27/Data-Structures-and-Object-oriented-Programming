#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class Rational
{
	int numer;
	int denom;
	int gcd(int a, int b);
	void reduce(int* a, int* b);

public:
	Rational(const int& numerator, const int& denominator);
	void add(const Rational& in);
	void sub(const Rational& in);
	void mul(const Rational& in);
	void div(const Rational& in);
	void print();
};

