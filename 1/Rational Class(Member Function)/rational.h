#include <iostream>
#include <algorithm>
using namespace std;
class Rational{
private:
    int a; // numerator
    int b; // denominator

public:
    Rational(const int &numerator, const int &denominator);
    void add(const Rational &in);
    void sub(const Rational &in);
    void mul(const Rational &in);
    void div(const Rational &in);
    void print();

};
