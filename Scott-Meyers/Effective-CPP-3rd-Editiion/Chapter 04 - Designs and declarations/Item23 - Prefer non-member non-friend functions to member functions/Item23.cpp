#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>

using std::string;
using std::list;
using std::cout;
using std::endl;

class WebBrowser
{
public:
	void clearCache();
	void clearHistory();
	void removeCookies();

	void clearEveryThing();
};

void clearBrowser(WebBrowser &wb)
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}

int main()
{

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
