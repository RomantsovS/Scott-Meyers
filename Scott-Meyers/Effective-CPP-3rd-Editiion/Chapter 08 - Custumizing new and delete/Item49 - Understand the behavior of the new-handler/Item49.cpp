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

namespace std {
	typedef void(*new_handler)();
	new_handler std::set_new_handler(new_handler p) throw();
}

void outOfMem()
{
	std::cerr << "Error\n";
	std::abort();
}

class Widget {
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc);
private:
	static std::new_handler currentHandler;
};

std::new_handler Widget::currentHandler = 0;

std::new_handler Widget::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}

class NewHandlerHolder {
public:
	explicit NewHandlerHolder(std::new_handler nh) : handler(nh) {}
	~NewHandlerHolder() { std::set_new_handler(handler); }
private:
	std::new_handler handler;

	NewHandlerHolder(const NewHandlerHolder&);
	NewHandlerHolder& operator=(const NewHandlerHolder&);
};

void* Widget::operator new(std::size_t size) throw(std::bad_alloc)
{
	NewHandlerHolder h(std::set_new_handler(currentHandler));
	return ::operator new(size);
}

template<typename T>
class NewHandlerSupport {
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc);
private:
	static std::new_handler currentHandler;
};

template<typename T>
std::new_handler NewHandlerSupport<T>::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}

template<typename T>
void* NewHandlerSupport<T>::operator new(std::size_t size) throw(std::bad_alloc)
{
	NewHandlerHolder h(std::set_new_handler(currentHandler));
	return ::operator new(size);
}

template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = 0;

class Widget2 : public NewHandlerSupport<Widget> {
public:
};

int main()
{
	std::set_new_handler(outOfMem);
	int a = 0;
	std::cin >> a;
	int* pBigDataArray = new int[100000000l * a];

	Widget::set_new_handler(outOfMem);

	Widget* pw1 = new Widget;
	std::string* ps = new std::string;

	Widget::set_new_handler(0);
	Widget* pw2 = new Widget;

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
