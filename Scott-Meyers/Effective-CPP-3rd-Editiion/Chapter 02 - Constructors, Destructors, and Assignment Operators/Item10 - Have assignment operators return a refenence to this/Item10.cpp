#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <vector>

using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;

class Widget
{
public:
	Widget &operator=(const Widget &rhs)
	{
		return *this;
	}
	
	Widget &operator+=(const Widget &rhs)
	{
		return *this;
	}
	
	Widget &operator=(int rhs)
	{
		return *this;
	}
};

int main()
{
	cout << "press any key to exit\n";
	_getch();

	return 0;
}