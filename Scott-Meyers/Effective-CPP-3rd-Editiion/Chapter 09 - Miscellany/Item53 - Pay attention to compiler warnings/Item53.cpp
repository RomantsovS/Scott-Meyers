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
	virtual void f() const;
};

class D : public B {
public:
	virtual void f();
};

int main()
{
	

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
