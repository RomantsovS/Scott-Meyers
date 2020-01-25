#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>

using std::string;
using std::list;
using std::cout;
using std::endl;

int priority()
{
	return 1;
}

class Widget {};

void processWidget(std::shared_ptr<Widget> pw, int priority)
{

}

//processWidget(std::shared_ptr<Widget(new Widget), priority());

int main()
{
	std::shared_ptr<Widget> pw(new Widget);
	processWidget(pw, priority());

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
