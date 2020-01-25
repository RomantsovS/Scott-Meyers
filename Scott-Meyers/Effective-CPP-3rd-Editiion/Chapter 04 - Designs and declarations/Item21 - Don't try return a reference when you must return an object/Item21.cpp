#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>

using std::string;
using std::list;
using std::cout;
using std::endl;

class Rational
{
public:
	Rational(int numerator = 0, int denomonator = 1);
private:
	int n, d;

	friend const Rational operator*(const Rational& lhs, const Rational& rhs);
};



int main()
{

	cout << "press any key to exit\n";
	_getch();

	return 0;
}

const Rational operator*(const Rational & lhs, const Rational & rhs)
{
	return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}
