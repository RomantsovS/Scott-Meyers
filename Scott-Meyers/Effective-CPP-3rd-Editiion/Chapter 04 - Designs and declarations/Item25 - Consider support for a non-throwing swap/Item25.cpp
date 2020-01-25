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

template<typename T>
class WidgetImpl
{
public:
private:
	int a, b, c;
	std::vector<double> v;
};

template<typename T>
class Widget
{
public:
	Widget(const Widget& rhs);
	
	Widget & operator=(const Widget& rhs)
	{
		*pimpl = *(rhs.pimpl);
	}

	void swap(Widget& other)
	{
		using std::swap;
		swap(pimpl, other.pimpl);
	}
private:
	WidgetImpl<T> *pimpl;
};

//namespace std
//{
	template<typename T>
	void swap(Widget<T>& a, Widget<T>& b)
	{
		//swap(a.pimpl, b.pimpl);
		a.swap(b);
	}
//}

int main()
{

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
