#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>

using std::string;
using std::list;
using std::cout;
using std::endl;


int main()
{
	string *str1 = new string;
	string *str2 = new string[10];

	delete str1;
	delete[] str2;

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
