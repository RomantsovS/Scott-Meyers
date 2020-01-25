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

class Widget
{
public:
	Widget(int num);
};

int main()
{
	Widget w;
	
	int n = 5;

	for (int i = 0; i < n; ++i)
		w = i;

	for (int i = 0; i < n; ++i)
		Widget w(i);

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
