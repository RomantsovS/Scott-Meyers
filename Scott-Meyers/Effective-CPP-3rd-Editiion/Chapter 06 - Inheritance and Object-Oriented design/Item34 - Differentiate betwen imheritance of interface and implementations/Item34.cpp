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

class Shape
{
public:
	virtual void draw() const = 0;
	virtual void error(const string & msg);
	int objectID() const;
};

class Rectangle : public Shape {};
class Ellipse: public Shape {};

int main()
{
	Shape *ps = new Shape;
	Shape *ps1 = new Rectangle;
	ps1->draw();

	Shape *ps2 = new Ellipse;
	ps->draw();

	ps1->Shape::draw();
	ps2->Shape::draw();

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
