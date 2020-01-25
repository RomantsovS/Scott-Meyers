#include <iostream>
#include <conio.h>
#include <string>
#include <list>

using std::string;
using std::list;
using std::cout;
using std::endl;

class Uncopyable
{
public:
	Uncopyable() {}
	~Uncopyable() {}
private:
	Uncopyable(const Uncopyable&);
	Uncopyable &operator=(const Uncopyable&);
};

class HomeForSale : private Uncopyable
{
public:
	HomeForSale()
	{

	}
};

int main()
{
	HomeForSale hfs1;

	//HomeForSale hfs2(hfs1);
	HomeForSale hfs2;
	//hfs2 = hfs1;

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
