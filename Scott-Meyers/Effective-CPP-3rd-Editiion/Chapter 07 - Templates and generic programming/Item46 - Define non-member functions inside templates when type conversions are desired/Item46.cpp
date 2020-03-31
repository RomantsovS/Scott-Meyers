#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>
#include <vector>

using std::string;
using std::list;
using std::cout;
using std::endl;

template<typename T> class Rational;

template<typename T>
const Rational<T> doMultiply(const Rational<T>& lhs, const Rational<T>& rhs)
{
	return Rational<T>(lhs.numerator() * rhs.numerator(),
		lhs.denominator() * rhs.denominator());
}

template<typename T>
class Rational {
public:
	Rational(const T& numerator = 0,
		const T& denominator = 1) : num(numerator), den(denominator)
	{

	}

	const T numerator() const
	{
		return num;
	}

	const T denominator() const
	{
		return den;
	}

	friend const Rational operator*(const Rational& lhs, const Rational& rhs)
	{
		/*return Rational(lhs.numerator() * rhs.numerator(), 
			lhs.denominator() * rhs.denominator());*/
		return doMultiply(lhs, rhs);
	}
private:
	T num, den;
};

Rational<int> oneHalf(1, 2);
Rational<int> result = oneHalf * 2;

int main()
{
	cout << "press any key to exit\n";
	_getch();

	return 0;
}
