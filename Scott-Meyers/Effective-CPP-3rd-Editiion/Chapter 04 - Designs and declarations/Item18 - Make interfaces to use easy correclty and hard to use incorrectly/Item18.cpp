#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>

using std::string;
using std::list;
using std::cout;
using std::endl;

struct Day
{
	explicit Day(int d) : val(d) {}
	int val;
};

struct Month
{
public:
	static Month Jan() { return Month(1); }
	explicit Month(int d) : val(d) {}
	int val;
};

struct Year
{
	explicit Year(int d) : val(d) {}
	int val;
};

class Date
{
public:
	Date(const Month& m, const Day& d, const Year& y) {}
};

int main()
{
	//Date d(30, 3, 1995);
	Date(Month(3), Day(30), Year(1995));
	Date d(Month::Jan(), Day(3), Year(1995));

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
