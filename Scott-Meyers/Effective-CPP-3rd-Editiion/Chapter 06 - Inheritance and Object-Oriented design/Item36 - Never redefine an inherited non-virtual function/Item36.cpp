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

class B {
public:
	void mf();
};

class D : public B {
public:
	void mf();
};

int main() 
{
	D x;

	B* pB = &x;

	pB->mf();

	D* pD = &x;
	pD->mf();

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
