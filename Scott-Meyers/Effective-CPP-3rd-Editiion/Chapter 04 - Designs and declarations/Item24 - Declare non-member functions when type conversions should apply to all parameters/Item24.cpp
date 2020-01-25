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
	Rational(int numerator = 0, int denominator = 1);

	int numerator() const;
	int denominator() const;

	//const Rational operator*(const Rational & rhs) const;
private:

};

const Rational operator*(const Rational& lhs, const Rational & rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(),
		lhs.denominator() * rhs.denominator());
}

int main()
{
	Rational oneEight(1, 8);
	Rational oneHalf(1, 2);

	Rational result = oneHalf * oneEight;

	result = result * oneEight;

	result = oneHalf * 2;
	result = 2 * oneHalf;

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
