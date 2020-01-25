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

class Point
{
public:
	Point(int x, int y);

	void setX(int newVal);
	void setY(int newVal);
};

struct RectData
{
	Point ulhc;
	Point lrhc;
};

class Rectangle
{
public:
	const Point& upperLeft() const { return pData->lrhc; }
	const Point& lowerRight() const { return pData->lrhc; }
private:
	std::shared_ptr<RectData> pData;
};

class GUIObject {};
const Rectangle boundingBox(const GUIObject& obj);

int main()
{
	Point coord1(0, 0);
	Point coord2(100, 100);
	const Rectangle rec(coord1, coord2);

	rec.upperLeft().setX(50);

	GUIObject *pgo;
	const Point *uUpperLeft = &(boundingBox(*pgo).upperLeft());

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
