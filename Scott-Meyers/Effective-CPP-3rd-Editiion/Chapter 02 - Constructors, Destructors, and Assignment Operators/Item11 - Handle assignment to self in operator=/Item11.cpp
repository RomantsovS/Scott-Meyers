#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <vector>

using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;

class Bitmap {};

class Widget
{
public:
	Widget &operator=(const Widget &rhs)
	{
		//if (this == &rhs) return *this;

		//delete pb;
		//pb = new Bitmap(*rhs.pb);

		Bitmap *pOrig = pb;
		pb = new Bitmap(*rhs.pb);
		delete pOrig;

		return *this;
	}

	Widget& Widget::operator=(Widget rhs)
	{
		swap(rhs);

		return *this;
	}
private:
	Bitmap *pb;
};

int main()
{
	Widget w;

	w = w;

	cout << "press any key to exit\n";
	_getch();

	return 0;
}