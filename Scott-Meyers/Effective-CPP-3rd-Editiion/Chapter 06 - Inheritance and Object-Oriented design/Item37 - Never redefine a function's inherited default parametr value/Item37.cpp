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

class Shape {
public:
	enum ShapeColor { Red, Green, Blue };

	//virtual void draw(ShapeColor col = Red) const = 0;
	void draw(ShapeColor col = Red) const
	{
		doDraw(col);
	}
private:
	virtual void doDraw(ShapeColor col) const = 0;
};

class Rectangle : public Shape {
public:
	/*virtual void draw(ShapeColor col = Green) const override
	{
		cout << col << endl;
	}*/

	void doDraw(ShapeColor col) const override
	{
		cout << col << endl;
	}
};

class Circle : public Shape {
public:
	/*virtual void draw(ShapeColor col) const override
	{
		cout << col << endl;
	}*/
};

int main()
{
	Shape *ps;
	//Shape* pc = new Circle;
	Shape* pr = new Rectangle;

	//pc->draw(Circle::Blue);
	pr->draw();
	pr->draw(Circle::Blue);

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
