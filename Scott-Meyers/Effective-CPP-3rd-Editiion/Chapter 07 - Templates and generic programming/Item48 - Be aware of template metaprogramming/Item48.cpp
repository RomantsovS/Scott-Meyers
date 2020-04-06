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

template<unsigned n>
struct Factorial {
	enum { value = n * Factorial<n-1>::value };
};

template<>
struct Factorial<0> {
	enum { value = 1 };
};

int main()
{
	cout << Factorial<10>::value << endl;

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
