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

class Base
{
private:
	int x;
public:
	virtual void mf1() = 0;
	virtual void mf1(int);

	virtual void mf2();
	void mf3();
	void mf3(double);
};

class Derived : public Base
{
public:
	using Base::mf1;
	using Base::mf3;

	virtual void mf1();
	void mf3();
	void mf4();
};

class DerivedPrivate : private Base
{
public:
	virtual void mf1()
	{
		Base::mf1();
	}
};

int main()
{
	Derived d;
	int x;

	d.mf1();
	d.mf1(x);

	d.mf2();

	d.mf3();
	d.mf3(x);

	DerivedPrivate dp;
	dp.mf1();
	//dp.mf1(x);

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
