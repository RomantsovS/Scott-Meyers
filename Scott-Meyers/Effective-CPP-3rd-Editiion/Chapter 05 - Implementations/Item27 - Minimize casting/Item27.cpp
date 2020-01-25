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

class Base {};

class Derived : public Base {};

class Window
{
public:virtual void onResize() {}
};

class SpecialWindow : public Window
{
public:
	virtual void onResize()
	{
		Window::onResize();
	}
	void blink();
};

//typedef std::vector<std::shared_ptr<Window>> VPW;
//VPW winPtrs;

typedef std::vector<std::shared_ptr<SpecialWindow>> VPSW;
VPSW winPtrs;

int main()
{
	Derived d;

	Base *pb = &d;

	/*for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end();
		++iter)
	{
		if (SpecialWindow *psw = dynamic_cast<SpecialWindow*>(iter->get()))
			psw->blink();
	}*/

	for (VPSW::iterator iter = winPtrs.begin(); iter != winPtrs.end();
		++iter)
	{
		(*iter)->blink();
	}

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
