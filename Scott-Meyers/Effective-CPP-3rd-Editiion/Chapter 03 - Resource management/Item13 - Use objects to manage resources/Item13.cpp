#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>

using std::string;
using std::list;
using std::cout;
using std::endl;

class Investment;

Investment * createInvestment();

void f()
{
	//Investment *plnv = createInvestment();

	//delete plnv;

	std::auto_ptr<Investment> plnv(createInvestment());
}

int main()
{

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
